#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include <QFileDialog>
#include <qfile>
#include <QTextStream>
#include <QList>
#include "Process.h"
#include "Scheduler.h"

QT_BEGIN_NAMESPACE
namespace Ui {
class MainWindow;
}
QT_END_NAMESPACE

class MainWindow : public QMainWindow
{
    Q_OBJECT

    private:
        Ui::MainWindow *ui;
        std::vector<Process> processosCarregados; // Guarda dados do CSV

    private slots:
        void on_Botao_AbrirArquivo_clicked();

        void on_Caminho_CSV_textChanged(const QString &CaminhoArquivo);

        void on_Botao_sair_clicked();

        void on_Botao_telaCarregaCSV_clicked();

        void on_Botao_TelaRelatorio_clicked();

        void on_botao_IniciarSimulacao_clicked();

    public:
        explicit MainWindow(QWidget *parent = nullptr);

        ~MainWindow() override;

        void PreencherTabela(QList<QStringList> linhasArquivoCSV);

        void InicializarTabela(QStringList header);
};
#endif // MAINWINDOW_H
