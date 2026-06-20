#include "mainwindow.h"
#include "./ui_mainwindow.h"

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

    // declarando o arquivo
    QFile arquivo(CaminhoArquivo);

    // verificando se nenhum erro ocorreu no processo
    if (!arquivo.open(QIODevice::ReadOnly))
    {
        // se ocorreu algum erro, mostra uma mensagem de erro
        qDebug() << arquivo.errorString();
    }

    QTextStream TextoArquivo(&arquivo);
    QString header = TextoArquivo.readLine();
    this->InicializarTabela(header.split(","));

    QList<QStringList> linhas;

    while(!TextoArquivo.atEnd())
    {
        QString linha = TextoArquivo.readLine();
        linhas.append(linha.split(","));
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


void MainWindow::on_Botao_TelaRelatorio_clicked()
{
    ui->Lista_Frames->setCurrentWidget(ui->RelatorioDaSimulacao);
}

