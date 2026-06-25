#ifndef MEMORYMANAGER_H
#define MEMORYMANAGER_H

#include <vector>
#include <QString>
#include <algorithm>
#include "Scheduler.h"
#include "Process.h"

enum class MemoryAlgo { FIFO, LRU, Otimo};

class MemoryManager {
public:
    // Construtor: recebe o tamanho da memória física (em MB ou KB) e o algoritmo
    MemoryManager(int numFrames, MemoryAlgo algo);

    // Função principal: simula o acesso do processo à memória naquele instante de tempo
    // Retorna 'true' se deu Page Fault, ou 'false' se a página já estava na memória (Page Hit)
    bool accessProcessMemory(const QString& processId, int memoryMb, const std::vector<Scheduler::TimelineEvent>& timeline, size_t indiceAtual);

    int getPageFaults() const { return pageFaults; }

private:
    int totalFrames;
    MemoryAlgo selectedAlgo;
    int pageFaults;

    // Representa a nossa Memória Física (vetor de IDs de processos ou páginas ocupando os frames)
    std::vector<QString> physicalMemory;

    // Histórico de uso para o algoritmo LRU (guarda a ordem de acesso)
    std::vector<QString> lruTracker;

    void insertFIFO(const QString& pageId);
    void insertLRU(const QString& pageId);
    void insertOtimo(const QString& pageId, const std::vector<Scheduler::TimelineEvent>& timeline, size_t indiceAtual);
};

#endif // MEMORYMANAGER_H