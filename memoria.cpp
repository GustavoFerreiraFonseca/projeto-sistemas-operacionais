#include <iostream>
#include <vector>
#include <queue>
#include <list>
#include <algorithm>

using namespace std;

// Classe responsável por simular a Memória Física (RAM) e as políticas de paginação
class GerenciadorMemoria {
private:
    int capacidadeQuadros; // Quantidade máxima de páginas que cabem na memória RAM ao mesmo tempo

    // Função auxiliar para verificar se uma página já está carregada na memória (Hit)
    bool paginaEstaNaMemoria(int pagina, const vector<int>& memoria) {
        return find(memoria.begin(), memoria.end(), pagina) != memoria.end();
    }

public:
    // Construtor: define o tamanho da memória física quando a classe é instanciada
    GerenciadorMemoria(int tamanho_memoria) {
        capacidadeQuadros = tamanho_memoria;
    }

    // ====================================================================================
    // 1. Algoritmo FIFO (First-In, First-Out) - A primeira página a entrar é a primeira a sair
    // ====================================================================================
    int simularFIFO(const vector<int>& sequenciaDeAcessos) {
        vector<int> memoria;       // Representa nossa memória RAM atual
        queue<int> filaDeEntrada;  // Fila para rastrear a ordem de chegada das páginas
        int faltasDePagina = 0;    // Contador de Page Faults

        cout << "\n--- Iniciando Simulacao FIFO ---" << endl;

        for (int paginaAtual : sequenciaDeAcessos) {
            // Se a página NÃO está na memória, ocorre um Page Fault (Falta de Página)
            if (!paginaEstaNaMemoria(paginaAtual, memoria)) {
                faltasDePagina++; // Registra o erro de página

                // Se a memória está cheia, precisamos remover a página mais antiga (FIFO)
                if (memoria.size() == capacidadeQuadros) {
                    int paginaMaisAntiga = filaDeEntrada.front(); // Pega a primeira da fila
                    filaDeEntrada.pop(); // Remove da fila

                    // Encontra e apaga a página mais antiga da nossa memória RAM
                    auto it = find(memoria.begin(), memoria.end(), paginaMaisAntiga);
                    memoria.erase(it);
                }

                // Adiciona a nova página na memória e no final da fila de rastreamento
                memoria.push_back(paginaAtual);
                filaDeEntrada.push(paginaAtual);
            }
        }
        return faltasDePagina;
    }

    // ====================================================================================
    // 2. Algoritmo LRU (Least Recently Used) - Remove a página usada há mais tempo
    // ====================================================================================
    int simularLRU(const vector<int>& sequenciaDeAcessos) {
        list<int> memoria;      // Usamos uma lista pois facilita mover itens para o "topo" (mais recentes)
        int faltasDePagina = 0; // Contador de Page Faults

        cout << "\n--- Iniciando Simulacao LRU ---" << endl;

        for (int paginaAtual : sequenciaDeAcessos) {
            // Verifica se a página já está na memória
            auto it = find(memoria.begin(), memoria.end(), paginaAtual);

            if (it == memoria.end()) {
                // Página NÃO está na memória (Page Fault)
                faltasDePagina++;

                // Se a memória estiver cheia, remove a página do final da lista (usada há mais tempo)
                if (memoria.size() == capacidadeQuadros) {
                    memoria.pop_back(); 
                }
                
                // Insere a nova página no início da lista (marca como a mais recentemente usada)
                memoria.push_front(paginaAtual);
            } else {
                // Página JÁ ESTÁ na memória (Hit)
                // Removemos ela da posição atual e a colocamos no início da lista para atualizar seu uso recente
                memoria.erase(it);
                memoria.push_front(paginaAtual);
            }
        }
        return faltasDePagina;
    }

    // ====================================================================================
    // 3. Algoritmo Ótimo - Remove a página que demorará mais tempo para ser usada no futuro
    // ====================================================================================
    int simularOtimo(const vector<int>& sequenciaDeAcessos) {
        vector<int> memoria;
        int faltasDePagina = 0;

        cout << "\n--- Iniciando Simulacao Algoritmo Otimo ---" << endl;

        for (int i = 0; i < sequenciaDeAcessos.size(); i++) {
            int paginaAtual = sequenciaDeAcessos[i];

            if (!paginaEstaNaMemoria(paginaAtual, memoria)) {
                faltasDePagina++;

                // Se a memória encheu, prever o futuro para achar a vítima
                if (memoria.size() == capacidadeQuadros) {
                    int paginaVitima = -1;
                    int indiceMaisDistante = -1;

                    // Avalia cada página que está atualmente na RAM
                    for (int paginaNaRAM : memoria) {
                        int proximoUso;
                        // Olha do momento atual (i) para a frente na sequência de acessos
                        for (proximoUso = i + 1; proximoUso < sequenciaDeAcessos.size(); proximoUso++) {
                            if (sequenciaDeAcessos[proximoUso] == paginaNaRAM) {
                                break; // Encontrou quando será o próximo uso
                            }
                        }

                        // Se a página não for mais usada no futuro, ela é a vítima perfeita
                        if (proximoUso == sequenciaDeAcessos.size()) {
                            paginaVitima = paginaNaRAM;
                            break; 
                        }

                        // Procura a página que vai demorar mais tempo para ser acessada novamente
                        if (proximoUso > indiceMaisDistante) {
                            indiceMaisDistante = proximoUso;
                            paginaVitima = paginaNaRAM;
                        }
                    }

                    // Remove a página vítima da memória
                    auto itVitima = find(memoria.begin(), memoria.end(), paginaVitima);
                    memoria.erase(itVitima);
                }

                // Insere a nova página na memória
                memoria.push_back(paginaAtual);
            }
        }
        return faltasDePagina;
    }
};

// ====================================================================================
// Função Principal (MAIN) - Apenas para você testar a sua lógica isoladamente
// ====================================================================================
int main() {
    // Definimos uma memória física (RAM) que suporta apenas 3 páginas simultâneas (3 frames)
    int tamanhoRAM = 3; 
    GerenciadorMemoria gerencia(tamanhoRAM);

    // Uma sequência fictícia de páginas que os processos estão pedindo para acessar
    vector<int> acessos = {7, 0, 1, 2, 0, 3, 0, 4, 2, 3, 0, 3, 2};

    cout << "Sequencia de paginas solicitadas: ";
    for (int p : acessos) cout << p << " ";
    cout << "\nTamanho da RAM: " << tamanhoRAM << " quadros (frames)\n";

    // Roda e imprime os resultados de cada algoritmo
    int faltasFIFO = gerencia.simularFIFO(acessos);
    cout << "Total de Page Faults (FIFO): " << faltasFIFO << endl;

    int faltasLRU = gerencia.simularLRU(acessos);
    cout << "Total de Page Faults (LRU): " << faltasLRU << endl;

    int faltasOtimo = gerencia.simularOtimo(acessos);
    cout << "Total de Page Faults (Otimo): " << faltasOtimo << endl;

    return 0;
}