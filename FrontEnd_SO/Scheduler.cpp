#include "Scheduler.h"
#include <algorithm>

Scheduler::Scheduler(std::vector<Process> processes, Algorithm algo, int quantum)
    : allProcesses(processes), selectedAlgo(algo), quantumTime(quantum) {}

void Scheduler::runSimulation() {
    std::sort(allProcesses.begin(), allProcesses.end(), [](const Process& a, const Process& b) {
        return a.arrivalTime < b.arrivalTime;
    });

    if (selectedAlgo == Algorithm::RoundRobin) {
        simulateRoundRobin();
    } else if (selectedAlgo == Algorithm::SJF_P) {
        simulateSJFP();
    } else if (selectedAlgo == Algorithm::Priority_P) {
        simulatePriorityP();
    }
}

void Scheduler::simulateSJFP() {
    int currentTime = 0;
    size_t completed = 0;
    std::vector<Process*> readyQueue;

    std::vector<Process*> activeProcesses;
    for (auto& p : allProcesses) {
        if (p.burstTime > 0) activeProcesses.push_back(&p);
    }
    if (activeProcesses.empty()) return;

    while (completed < activeProcesses.size()) {
        for (auto* p : activeProcesses) {
            if (p->arrivalTime == currentTime && p->remainingTime > 0) {
                if (std::find(readyQueue.begin(), readyQueue.end(), p) == readyQueue.end()) {
                    readyQueue.push_back(p);
                }
            }
        }

        if (!readyQueue.empty()) {
            auto idx = std::min_element(readyQueue.begin(), readyQueue.end(), [](const Process* a, const Process* b) {
                return a->remainingTime < b->remainingTime;
            });

            Process* currentProc = *idx;

            currentProc->remainingTime--;
            timeline.push_back({currentTime, currentProc->id});

            if (currentProc->remainingTime == 0) {
                currentProc->completionTime = currentTime + 1;
                currentProc->waitTime = currentProc->completionTime - currentProc->arrivalTime - currentProc->burstTime;
                currentProc->responseTime = currentProc->completionTime - currentProc->arrivalTime; // Perfeito!
                readyQueue.erase(idx);
                completed++;
            }
        } else {
            timeline.push_back({currentTime, "IDLE"});
        }
        currentTime++;
    }
}

void Scheduler::simulatePriorityP() {
    int currentTime = 0;
    size_t completed = 0;
    std::vector<Process*> readyQueue;

    std::vector<Process*> activeProcesses;
    for (auto& p : allProcesses) {
        if (p.burstTime > 0) activeProcesses.push_back(&p);
    }
    if (activeProcesses.empty()) return;

    while (completed < activeProcesses.size()) {
        for (auto* p : activeProcesses) {
            if (p->arrivalTime == currentTime && p->remainingTime > 0) {
                if (std::find(readyQueue.begin(), readyQueue.end(), p) == readyQueue.end()) {
                    readyQueue.push_back(p);
                }
            }
        }

        if (!readyQueue.empty()) {
            auto idx = std::min_element(readyQueue.begin(), readyQueue.end(), [](const Process* a, const Process* b) {
                if (a->priority == b->priority) {
                    return a->arrivalTime < b->arrivalTime;
                }
                return a->priority < b->priority;
            });

            Process* currentProc = *idx;
            // Bloco antigo de resposta removido daqui de forma limpa!

            currentProc->remainingTime--;
            timeline.push_back({currentTime, currentProc->id});

            if (currentProc->remainingTime == 0) {
                currentProc->completionTime = currentTime + 1;
                currentProc->waitTime = currentProc->completionTime - currentProc->arrivalTime - currentProc->burstTime;
                currentProc->responseTime = currentProc->completionTime - currentProc->arrivalTime; // Corrigido!
                readyQueue.erase(idx);
                completed++;
            }
        } else {
            timeline.push_back({currentTime, "IDLE"});
        }
        currentTime++;
    }
}

void Scheduler::simulateRoundRobin() {
    int currentTime = 0;
    size_t completed = 0;
    std::queue<Process*> readyQueue;
    size_t pointer = 0;

    std::sort(allProcesses.begin(), allProcesses.end(), [](const Process& a, const Process& b) {
        return a.arrivalTime < b.arrivalTime;
    });

    while (completed < allProcesses.size()) {

        while (pointer < allProcesses.size() && allProcesses[pointer].arrivalTime <= currentTime) {
            readyQueue.push(&allProcesses[pointer]);
            pointer++;
        }

        if (!readyQueue.empty()) {
            Process* currentProc = readyQueue.front();
            readyQueue.pop();

            // Bloco antigo de resposta removido daqui para evitar conflito com o Quantum!

            int timeToExecute = std::min(quantumTime, currentProc->remainingTime);

            for (int i = 0; i < timeToExecute; ++i) {
                timeline.push_back({currentTime, currentProc->id});
                currentTime++;

                while (pointer < allProcesses.size() && allProcesses[pointer].arrivalTime <= currentTime) {
                    readyQueue.push(&allProcesses[pointer]);
                    pointer++;
                }
            }

            currentProc->remainingTime -= timeToExecute;

            if (currentProc->remainingTime == 0) {
                currentProc->completionTime = currentTime;
                currentProc->waitTime = currentProc->completionTime - currentProc->arrivalTime - currentProc->burstTime;
                currentProc->responseTime = currentProc->completionTime - currentProc->arrivalTime; // Corrigido!
                completed++;
            } else {
                readyQueue.push(currentProc);
            }
        } else {
            timeline.push_back({currentTime, "IDLE"});
            currentTime++;
        }
    }
}