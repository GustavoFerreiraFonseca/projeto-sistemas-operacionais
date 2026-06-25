#ifndef PROCESS_H
#define PROCESS_H

#include <QString>

struct Process {
    QString id;
    int arrivalTime;     // Tempo de Chegada [cite: 11]
    int burstTime;       // Tempo de Execução total (CPU Burst) [cite: 12]
    int remainingTime;   // Tempo que falta executar (essencial para preempção)
    int priority;        // Prioridade [cite: 13]
    int memoryRequired;  // Memória em MB [cite: 14]

    // Métricas de performance para o relatório final [cite: 36]
    int startTime = -1;
    int completionTime = 0;
    int waitTime = 0;
    int responseTime = -1;
};

#endif // PROCESS_H