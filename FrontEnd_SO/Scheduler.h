#ifndef SCHEDULER_H
#define SCHEDULER_H

#include <vector>
#include <queue>
#include "Process.h"

enum class Algorithm { RoundRobin, SJF_P, Priority_P };

class Scheduler {
public:
    Scheduler(std::vector<Process> processes, Algorithm algo, int quantum = 2);
    void runSimulation();
    std::vector<Process> getProcessedProcesses() const { return allProcesses; }

    // Retornos para a interface gráfica e relatórios
    struct TimelineEvent {
        int timeInstant;
        QString processId;
    };
    std::vector<TimelineEvent> getTimeline() const { return timeline; }

private:
    std::vector<Process> allProcesses;
    Algorithm selectedAlgo;
    int quantumTime;
    std::vector<TimelineEvent> timeline;

    // Funções internas para cada algoritmo
    void simulateRoundRobin();
    void simulateSJFP();
    void simulatePriorityP();
};

#endif // SCHEDULER_H
