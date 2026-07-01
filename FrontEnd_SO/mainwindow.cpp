#include "mainwindow.h"
#include "./ui_mainwindow.h"
#include "Process.h"
#include "Scheduler.h"
#include <QMessageBox>
#include "MemoryManager.h"

MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
{
    ui->setupUi(this);

    this->showFullScreen();

    ui->Botao_telaCarregaCSV->setChecked(true);
    ui->Lista_Frames->setCurrentWidget(ui->CarregandoArquivoCSV);
}

using namespace std;

MainWindow::~MainWindow()
{
    delete ui;
}

void MainWindow::on_Botao_AbrirArquivo_clicked()
{
    // Abre o diálogo do Windows e guarda o caminho do arquivo selecionado
    QString caminhoArquivo = QFileDialog::getOpenFileName(
        this,                                   // Diz que a janela do dialogo pertence a esta tela (mainWindow)
        tr("Selecionar Arquivo de Processos"),  // Título da janela
        "C://",                                 // Diretório inicial padrão
        tr("Arquivos CSV (*.csv);;Todos os arquivos (*.*)")); // Filtro de extensão (no caso pedindo arquivos CSV, ou todos os outros tipos)

    ui->Caminho_CSV->setText(caminhoArquivo);
}


void MainWindow::on_Caminho_CSV_textChanged(const QString &CaminhoArquivo)
{
    if (CaminhoArquivo == "") return;

    QFile arquivo(CaminhoArquivo);
    if (!arquivo.open(QIODevice::ReadOnly)) {
        qDebug() << arquivo.errorString();
        return;
    }

    QTextStream TextoArquivo(&arquivo);
    QString header = TextoArquivo.readLine();
    this->InicializarTabela(header.split(","));

    QList<QStringList> linhas;
    processosCarregados.clear();

    int idContador = 1;
    while(!TextoArquivo.atEnd()) {
        QString linha = TextoArquivo.readLine();
        if(linha.trimmed().isEmpty()) continue;

        QStringList colunas = linha.split(",");
        linhas.append(colunas);

        // CASO 1: O arquivo possui a coluna PID (5 ou mais colunas, como o seu arquivo_teste.csv)
        if(colunas.size() >= 5) {
            Process p;
            p.id = colunas.at(0).trimmed();
            p.arrivalTime = colunas.at(1).toInt();
            p.burstTime = colunas.at(2).toInt();
            p.remainingTime = p.burstTime;
            p.priority = colunas.at(3).toInt();
            p.memoryRequired = colunas.at(4).toInt();
            processosCarregados.push_back(p);
        }
        // CASO 2: O arquivo não possui a coluna PID (4 colunas padrão do requisito)
        else if(colunas.size() == 4) {
            Process p;
            p.id = "P" + QString::number(idContador++);
            p.arrivalTime = colunas.at(0).toInt();
            p.burstTime = colunas.at(1).toInt();
            p.remainingTime = p.burstTime;
            p.priority = colunas.at(2).toInt();
            p.memoryRequired = colunas.at(3).toInt();
            processosCarregados.push_back(p);
        }
    }

    this->PreencherTabela(linhas);
    arquivo.close();
}

void MainWindow::PreencherTabela(QList<QStringList> linhasArquivoCSV)
{
    for(int i = 0; i < linhasArquivoCSV.size(); i++)
    {
        ui->Tabela_CSV->insertRow(i);

        for(int j = 0; j < linhasArquivoCSV.at(i).size(); j++)
        {
            QString texto = linhasArquivoCSV.at(i).at(j);
            QTableWidgetItem* item = new QTableWidgetItem(texto);

            ui->Tabela_CSV->setItem(i, j, item);
        }
    }

}

void MainWindow::InicializarTabela(QStringList header)
{
    ui->Tabela_CSV->setRowCount(0);
    ui->Tabela_CSV->setColumnCount(header.size());
    ui->Tabela_CSV->setHorizontalHeaderLabels(header);

    ui->Tabela_CSV->horizontalHeader()->setSectionResizeMode(QHeaderView::Stretch);
    ui->Tabela_CSV->verticalHeader()->setVisible(false);
    return;
}


void MainWindow::on_Botao_sair_clicked() { this->close(); }


void MainWindow::on_Botao_telaCarregaCSV_clicked()
{
    ui->Lista_Frames->setCurrentWidget(ui->CarregandoArquivoCSV);
}

void MainWindow::on_botao_IniciarSimulacao_clicked()
{
    // 1. Validação básica de processos
    if (processosCarregados.empty()) {
        QMessageBox::warning(this, "Aviso", "Por favor, carregue um arquivo CSV de processos primeiro.");
        return;
    }

    // 2. Captura configurações de Processos do Front-End
    QString algoTexto = ui->comboBox->currentText();
    Algorithm algoSelecionado = Algorithm::RoundRobin;
    int quantum = ui->lineEdit_3->text().toInt() <= 0 ? 2 : ui->lineEdit_3->text().toInt();

    if (algoTexto.contains("Round-Robin") || algoTexto.contains("RR")) {
        algoSelecionado = Algorithm::RoundRobin;
    } else if (algoTexto.contains("SJF")) {
        algoSelecionado = Algorithm::SJF_P;
    } else if (algoTexto.contains("Prioridade")) {
        algoSelecionado = Algorithm::Priority_P;
    }

    // 3. Captura configurações de Memória do Front-End
    int memoriaFisicaMbs = ui->lineEdit->text().toInt();
    if (memoriaFisicaMbs <= 0) memoriaFisicaMbs = 4;

    int memoriaVirtualMbs = ui->lineEdit_2->text().toInt();
    if (memoriaVirtualMbs <= 0) memoriaVirtualMbs = 16;

    int numFrames = memoriaFisicaMbs;

    // Identifica a política de substituição escolhida
    QString politicaTexto = ui->comboBox_2->currentText();
    MemoryAlgo politicaMemoria = MemoryAlgo::FIFO;
    if (politicaTexto.contains("LRU")) {
        politicaMemoria = MemoryAlgo::LRU;
    } else if (politicaTexto.contains("Ótimo") || politicaTexto.contains("Otimo")) {
        politicaMemoria = MemoryAlgo::Otimo;
    }

    // Instancia o Gerenciador de Memória Virtual
    MemoryManager gerenciadorMemoria(numFrames, politicaMemoria);

    // 4. Executa a simulação no núcleo do Escalonador de Processos
    Scheduler simulador(processosCarregados, algoSelecionado, quantum);
    simulador.runSimulation();

    // AGORA SIM as variáveis existem e contêm os dados calculados!
    std::vector<Scheduler::TimelineEvent> resultadoTimeline = simulador.getTimeline();
    std::vector<Process> procsProcessados = simulador.getProcessedProcesses();

    // =========================================================================
    // SIMULAÇÃO DA MEMÓRIA PASSO A PASSO (Conectando Processos + Memória com 4 parâmetros)
    // =========================================================================
    for (size_t i = 0; i < resultadoTimeline.size(); ++i) {
        const auto& evento = resultadoTimeline[i];
        if (evento.processId != "IDLE") {
            auto it = std::find_if(processosCarregados.begin(), processosCarregados.end(),
                                   [&](const Process& p) { return p.id == evento.processId; });

            if (it != processosCarregados.end()) {
                // Chamada correta com os 4 parâmetros configurados!
                gerenciadorMemoria.accessProcessMemory(it->id, it->memoryRequired, resultadoTimeline, i);
            }
        }
    }

    // =========================================================================
    // RENDERIZAÇÃO: LINHA DO TEMPO DA EXECUÇÃO (tableWidget_2)
    // =========================================================================
    ui->tableWidget_2->setRowCount(0);
    ui->tableWidget_2->setColumnCount(2);
    ui->tableWidget_2->setHorizontalHeaderLabels(QStringList() << "Instante (Tempo)" << "Processo em Execução");
    ui->tableWidget_2->horizontalHeader()->setSectionResizeMode(QHeaderView::Stretch);
    ui->tableWidget_2->verticalHeader()->setVisible(false);

    for (size_t i = 0; i < resultadoTimeline.size(); ++i) {
        ui->tableWidget_2->insertRow(i);
        QString instanteStr = QString("t = %1s").arg(resultadoTimeline[i].timeInstant);
        ui->tableWidget_2->setItem(i, 0, new QTableWidgetItem(instanteStr));
        ui->tableWidget_2->setItem(i, 1, new QTableWidgetItem(resultadoTimeline[i].processId));
    }

    // =========================================================================
    // RENDERIZAÇÃO: MÉTRICAS INDIVIDUAIS (tableWidget)
    // =========================================================================
    ui->tableWidget->setRowCount(0);
    ui->tableWidget->setColumnCount(3);
    ui->tableWidget->setHorizontalHeaderLabels(QStringList() << "Processo" << "Tempo Espera" << "Tempo Resposta");
    ui->tableWidget->horizontalHeader()->setSectionResizeMode(QHeaderView::Stretch);
    ui->tableWidget->verticalHeader()->setVisible(false);

    double totalWait = 0;
    double totalResponse = 0;

    for (size_t i = 0; i < procsProcessados.size(); ++i) {
        ui->tableWidget->insertRow(i);
        const auto& p = procsProcessados[i];
        ui->tableWidget->setItem(i, 0, new QTableWidgetItem(p.id));
        ui->tableWidget->setItem(i, 1, new QTableWidgetItem(QString("%1s").arg(p.waitTime)));
        ui->tableWidget->setItem(i, 2, new QTableWidgetItem(QString("%1s").arg(p.responseTime)));

        totalWait += p.waitTime;
        totalResponse += p.responseTime;
    }

    // =========================================================================
    // RENDERIZAÇÃO: MÉTRICAS GERAIS DE PERFORMANCE + MEMÓRIA (tableWidget_3)
    // =========================================================================
    ui->tableWidget_3->setRowCount(0);
    ui->tableWidget_3->setColumnCount(2);
    ui->tableWidget_3->setHorizontalHeaderLabels(QStringList() << "Métrica Global" << "Valor Obtido");
    ui->tableWidget_3->horizontalHeader()->setSectionResizeMode(QHeaderView::Stretch);
    ui->tableWidget_3->verticalHeader()->setVisible(false);

    double avgWait = totalWait / procsProcessados.size();
    double avgResponse = totalResponse / procsProcessados.size();

    // Linha do algoritmo de CPU
    ui->tableWidget_3->insertRow(0);
    ui->tableWidget_3->setItem(0, 0, new QTableWidgetItem("Algoritmo de Escalonamento"));
    ui->tableWidget_3->setItem(0, 1, new QTableWidgetItem(algoTexto));

    // Linha da Política de Memória
    ui->tableWidget_3->insertRow(1);
    ui->tableWidget_3->setItem(1, 0, new QTableWidgetItem("Política de Substituição"));
    ui->tableWidget_3->setItem(1, 1, new QTableWidgetItem(politicaTexto));

    // Linha do Tempo Médio de Espera (AWT)
    ui->tableWidget_3->insertRow(2);
    ui->tableWidget_3->setItem(2, 0, new QTableWidgetItem("Tempo Médio de Espera (AWT)"));
    ui->tableWidget_3->setItem(2, 1, new QTableWidgetItem(QString("%1s").arg(avgWait, 0, 'f', 2)));

    // Linha do Tempo Médio de Resposta (ART)
    ui->tableWidget_3->insertRow(3);
    ui->tableWidget_3->setItem(3, 0, new QTableWidgetItem("Tempo Médio de Resposta (ART)"));
    ui->tableWidget_3->setItem(3, 1, new QTableWidgetItem(QString("%1s").arg(avgResponse, 0, 'f', 2)));

    // Linha de Page Faults calculada
    ui->tableWidget_3->insertRow(4);
    ui->tableWidget_3->setItem(4, 0, new QTableWidgetItem("Total de Page Faults"));
    ui->tableWidget_3->setItem(4, 1, new QTableWidgetItem(QString::number(gerenciadorMemoria.getPageFaults())));

    // 5. Redireciona para o frame de relatórios
    ui->Botao_TelaRelatorio->setChecked(true);
    ui->Lista_Frames->setCurrentWidget(ui->RelatorioDaSimulacao);
}


void MainWindow::on_Botao_TelaRelatorio_clicked()
{
    // Verifica se já existe uma simulação feita olhando se a tabela de resultados está vazia
    if (ui->tableWidget_2->rowCount() == 0) {
        QMessageBox::information(this, "Aviso",
                                 "Nenhuma simulação foi executada ainda.\n\nPor favor, carregue um arquivo CSV na tela inicial e clique em 'Iniciar Simulação' para gerar os dados.");
        return;
    }

    // Se já tiver dados simulados, apenas navega para o frame do relatório
    ui->Lista_Frames->setCurrentWidget(ui->RelatorioDaSimulacao);
}

void MainWindow::on_comboBox_activated(int index)
{
    if (ui->comboBox->currentText() == "Round-Robin(RR)")
    {
        ui->lineEdit_3->setDisabled(false);
    } else {
        ui->lineEdit_3->setDisabled(true);
    }
}

