#include "MemoryManager.h"

MemoryManager::MemoryManager(int numFrames, MemoryAlgo algo)
    : totalFrames(numFrames), selectedAlgo(algo), pageFaults(0) {}

bool MemoryManager::accessProcessMemory(const QString& processId, int memoryMb, const std::vector<Scheduler::TimelineEvent>& timeline, size_t indiceAtual) {
    QString pageId = processId;

    auto it = std::find(physicalMemory.begin(), physicalMemory.end(), pageId);
    if (it != physicalMemory.end()) {
        if (selectedAlgo == MemoryAlgo::LRU) {
            auto lruIt = std::find(lruTracker.begin(), lruTracker.end(), pageId);
            if (lruIt != lruTracker.end()) lruTracker.erase(lruIt);
            lruTracker.push_back(pageId);
        }
        return false;
    }

    pageFaults++;

    if (physicalMemory.size() < static_cast<size_t>(totalFrames)) {
        physicalMemory.push_back(pageId);
        lruTracker.push_back(pageId);
    } else {
        if (selectedAlgo == MemoryAlgo::FIFO) {
            insertFIFO(pageId);
        } else if (selectedAlgo == MemoryAlgo::LRU) {
            insertLRU(pageId);
        } else if (selectedAlgo == MemoryAlgo::Otimo) {
            insertOtimo(pageId, timeline, indiceAtual); // <--- Chamada do Ótimo
        }
    }
    return true;
}

void MemoryManager::insertOtimo(const QString& pageId, const std::vector<Scheduler::TimelineEvent>& timeline, size_t indiceAtual) {
    int indiceParaSubstituir = 0;
    int maiorDistancia = -1;

    // Varre as páginas que estão na memória física para ver qual demorará mais a ser usada
    for (size_t i = 0; i < physicalMemory.size(); ++i) {
        QString paginaNaMemoria = physicalMemory[i];
        int proximoUso = 999999; // Se não for usada mais, o peso é enorme

        // Procura no futuro da linha do tempo
        for (size_t j = indiceAtual + 1; j < timeline.size(); ++j) {
            if (timeline[j].processId == paginaNaMemoria) {
                proximoUso = j;
                break;
            }
        }

        // Quem tiver o próximo uso mais distante (maior índice) é o escolhido
        if (proximoUso > maiorDistancia) {
            maiorDistancia = proximoUso;
            indiceParaSubstituir = i;
        }
    }

    // Substitui a página ideal
    physicalMemory[indiceParaSubstituir] = pageId;
}

void MemoryManager::insertFIFO(const QString& pageId) {
    // FIFO: Remove o primeiro elemento que entrou (o índice 0 da memória)
    physicalMemory.erase(physicalMemory.begin());
    // Adiciona o novo processo no fim da fila
    physicalMemory.push_back(pageId);
}

void MemoryManager::insertLRU(const QString& pageId) {
    // LRU: O elemento menos usado recentemente está no início do lruTracker
    QString menosUsado = lruTracker.front();
    lruTracker.erase(lruTracker.begin());

    // Substitui ele na memória física
    auto it = std::find(physicalMemory.begin(), physicalMemory.end(), menosUsado);
    if (it != physicalMemory.end()) {
        *it = pageId;
    }

    // Adiciona o novo no rastreador de uso recente
    lruTracker.push_back(pageId);
}