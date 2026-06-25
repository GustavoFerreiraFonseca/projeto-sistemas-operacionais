#include "Scheduler.h"
#include <algorithm>

Scheduler::Scheduler(std::vector<Process> processes, Algorithm algo, int quantum)
    : allProcesses(processes), selectedAlgo(algo), quantumTime(quantum) {}

void Scheduler::runSimulation() {
    // Ordena inicialmente por tempo de chegada
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

    // Filtro de segurança: ignora processos com tempo de execução zero
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
            if (currentProc->responseTime == -1) {
                currentProc->responseTime = currentTime - currentProc->arrivalTime;
            }

            currentProc->remainingTime--;
            timeline.push_back({currentTime, currentProc->id});

            if (currentProc->remainingTime == 0) {
                currentProc->completionTime = currentTime + 1;
                currentProc->waitTime = currentProc->completionTime - currentProc->arrivalTime - currentProc->burstTime;
                readyQueue.erase(idx);
                completed++;
            }
        } else {
            timeline.push_back({currentTime, "IDLE"});
        }
        currentTime++;
    }
}

// Faça a mesma proteção na função de Prioridade Preemptiva:
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
            if (currentProc->responseTime == -1) {
                currentProc->responseTime = currentTime - currentProc->arrivalTime;
            }

            currentProc->remainingTime--;
            timeline.push_back({currentTime, currentProc->id});

            if (currentProc->remainingTime == 0) {
                currentProc->completionTime = currentTime + 1;
                currentProc->waitTime = currentProc->completionTime - currentProc->arrivalTime - currentProc->burstTime;
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
    size_t pointer = 0; // Para controlar quais processos já entraram na fila por tempo de chegada

    // Ordena por tempo de chegada inicialmente (garantia extra)
    std::sort(allProcesses.begin(), allProcesses.end(), [](const Process& a, const Process& b) {
        return a.arrivalTime < b.arrivalTime;
    });

    // Loop até que todos os processos sejam concluídos
    while (completed < allProcesses.size()) {

        // 1. Coloca na fila de prontos todos os processos que chegaram neste instante 'currentTime'
        while (pointer < allProcesses.size() && allProcesses[pointer].arrivalTime <= currentTime) {
            readyQueue.push(&allProcesses[pointer]);
            pointer++;
        }

        if (!readyQueue.empty()) {
            // Pega o próximo processo da fila
            Process* currentProc = readyQueue.front();
            readyQueue.pop();

            // Métrica de tempo de resposta (primeira vez que executa)
            if (currentProc->responseTime == -1) {
                currentProc->responseTime = currentTime - currentProc->arrivalTime;
            }

            // Define quanto tempo ele vai rodar neste turno (o menor entre o quantum ou o que resta)
            int timeToExecute = std::min(quantumTime, currentProc->remainingTime);

            // Simula a execução passo a passo dentro do intervalo do quantum
            for (int i = 0; i < timeToExecute; ++i) {
                timeline.push_back({currentTime, currentProc->id});
                currentTime++;

                // Importante: Enquanto o processo executa, novos processos podem chegar!
                while (pointer < allProcesses.size() && allProcesses[pointer].arrivalTime <= currentTime) {
                    readyQueue.push(&allProcesses[pointer]);
                    pointer++;
                }
            }

            currentProc->remainingTime -= timeToExecute;

            // Se o processo terminou
            if (currentProc->remainingTime == 0) {
                currentProc->completionTime = currentTime;
                currentProc->waitTime = currentProc->completionTime - currentProc->arrivalTime - currentProc->burstTime;
                completed++;
            } else {
                // Se não terminou, ele volta para o fim da fila de prontos
                readyQueue.push(currentProc);
            }
        } else {
            // Se a fila está vazia, a CPU ficou ociosa neste instante
            timeline.push_back({currentTime, "IDLE"});
            currentTime++;
        }
    }
}
