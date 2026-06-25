/********************************************************************************
** Form generated from reading UI file 'mainwindow.ui'
**
** Created by: Qt User Interface Compiler version 6.11.1
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_MAINWINDOW_H
#define UI_MAINWINDOW_H

#include <QtCore/QVariant>
#include <QtWidgets/QApplication>
#include <QtWidgets/QButtonGroup>
#include <QtWidgets/QComboBox>
#include <QtWidgets/QFrame>
#include <QtWidgets/QGridLayout>
#include <QtWidgets/QHBoxLayout>
#include <QtWidgets/QHeaderView>
#include <QtWidgets/QLabel>
#include <QtWidgets/QLineEdit>
#include <QtWidgets/QMainWindow>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QSpacerItem>
#include <QtWidgets/QStackedWidget>
#include <QtWidgets/QTableWidget>
#include <QtWidgets/QVBoxLayout>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_MainWindow
{
public:
    QWidget *centralwidget;
    QVBoxLayout *verticalLayout_3;
    QVBoxLayout *verticalLayout_4;
    QHBoxLayout *horizontalLayout;
    QFrame *BordaEscura;
    QVBoxLayout *B;
    QLabel *Titulo;
    QSpacerItem *verticalSpacer_4;
    QPushButton *Botao_telaCarregaCSV;
    QPushButton *Botao_TelaRelatorio;
    QSpacerItem *verticalSpacer_2;
    QPushButton *Botao_sair;
    QSpacerItem *verticalSpacer;
    QStackedWidget *Lista_Frames;
    QWidget *CarregandoArquivoCSV;
    QVBoxLayout *verticalLayout_6;
    QGridLayout *gridLayout;
    QFrame *frame_2;
    QVBoxLayout *verticalLayout_5;
    QGridLayout *gridLayout_2;
    QSpacerItem *horizontalSpacer;
    QLabel *label_2;
    QLabel *label_3;
    QSpacerItem *verticalSpacer_7;
    QLabel *label_5;
    QSpacerItem *verticalSpacer_8;
    QSpacerItem *horizontalSpacer_2;
    QSpacerItem *verticalSpacer_11;
    QLineEdit *lineEdit_2;
    QLabel *label;
    QLabel *Titulo_memoria;
    QSpacerItem *verticalSpacer_12;
    QComboBox *comboBox_2;
    QPushButton *botao_IniciarSimulacao;
    QLabel *Titulo_config;
    QLineEdit *lineEdit;
    QSpacerItem *verticalSpacer_13;
    QComboBox *comboBox;
    QSpacerItem *verticalSpacer_10;
    QSpacerItem *verticalSpacer_9;
    QSpacerItem *verticalSpacer_16;
    QFrame *frame_3;
    QHBoxLayout *horizontalLayout_3;
    QVBoxLayout *verticalLayout;
    QTableWidget *Tabela_CSV;
    QSpacerItem *verticalSpacer_6;
    QLabel *labelCSV;
    QHBoxLayout *horizontalLayout_5;
    QLineEdit *Caminho_CSV;
    QPushButton *Botao_AbrirArquivo;
    QSpacerItem *verticalSpacer_3;
    QWidget *RelatorioDaSimulacao;
    QVBoxLayout *verticalLayout_2;
    QGridLayout *gridLayout_3;
    QFrame *frame;
    QVBoxLayout *verticalLayout_8;
    QVBoxLayout *verticalLayout_7;
    QLabel *Titulo_MetricasIndividuais;
    QTableWidget *tableWidget;
    QHBoxLayout *horizontalLayout_2;
    QSpacerItem *horizontalSpacer_3;
    QPushButton *Botao_gerarRelatorio;
    QSpacerItem *horizontalSpacer_4;
    QFrame *frame_4;
    QVBoxLayout *verticalLayout_10;
    QVBoxLayout *verticalLayout_9;
    QSpacerItem *verticalSpacer_14;
    QLabel *Titulo_LinhaTempo;
    QTableWidget *tableWidget_2;
    QSpacerItem *verticalSpacer_5;
    QLabel *Titulo_MetricasGerais;
    QTableWidget *tableWidget_3;
    QSpacerItem *verticalSpacer_15;
    QButtonGroup *buttonGroup;

    void setupUi(QMainWindow *MainWindow)
    {
        if (MainWindow->objectName().isEmpty())
            MainWindow->setObjectName("MainWindow");
        MainWindow->resize(1231, 809);
        QSizePolicy sizePolicy(QSizePolicy::Policy::Maximum, QSizePolicy::Policy::Fixed);
        sizePolicy.setHorizontalStretch(0);
        sizePolicy.setVerticalStretch(0);
        sizePolicy.setHeightForWidth(MainWindow->sizePolicy().hasHeightForWidth());
        MainWindow->setSizePolicy(sizePolicy);
        MainWindow->setMaximumSize(QSize(1600, 1000));
        centralwidget = new QWidget(MainWindow);
        centralwidget->setObjectName("centralwidget");
        verticalLayout_3 = new QVBoxLayout(centralwidget);
        verticalLayout_3->setObjectName("verticalLayout_3");
        verticalLayout_4 = new QVBoxLayout();
        verticalLayout_4->setSpacing(0);
        verticalLayout_4->setObjectName("verticalLayout_4");
        verticalLayout_4->setSizeConstraint(QLayout::SizeConstraint::SetMinimumSize);
        verticalLayout_4->setContentsMargins(0, -1, -1, -1);
        horizontalLayout = new QHBoxLayout();
        horizontalLayout->setObjectName("horizontalLayout");
        horizontalLayout->setSizeConstraint(QLayout::SizeConstraint::SetMinAndMaxSize);
        BordaEscura = new QFrame(centralwidget);
        BordaEscura->setObjectName("BordaEscura");
        B = new QVBoxLayout(BordaEscura);
        B->setObjectName("B");
        B->setContentsMargins(0, 0, 0, 0);
        Titulo = new QLabel(BordaEscura);
        Titulo->setObjectName("Titulo");
        QSizePolicy sizePolicy1(QSizePolicy::Policy::Preferred, QSizePolicy::Policy::Preferred);
        sizePolicy1.setHorizontalStretch(0);
        sizePolicy1.setVerticalStretch(0);
        sizePolicy1.setHeightForWidth(Titulo->sizePolicy().hasHeightForWidth());
        Titulo->setSizePolicy(sizePolicy1);
        Titulo->setAlignment(Qt::AlignmentFlag::AlignCenter);

        B->addWidget(Titulo);

        verticalSpacer_4 = new QSpacerItem(20, 50, QSizePolicy::Policy::Minimum, QSizePolicy::Policy::Fixed);

        B->addItem(verticalSpacer_4);

        Botao_telaCarregaCSV = new QPushButton(BordaEscura);
        buttonGroup = new QButtonGroup(MainWindow);
        buttonGroup->setObjectName("buttonGroup");
        buttonGroup->addButton(Botao_telaCarregaCSV);
        Botao_telaCarregaCSV->setObjectName("Botao_telaCarregaCSV");
        Botao_telaCarregaCSV->setEnabled(true);
        QSizePolicy sizePolicy2(QSizePolicy::Policy::Fixed, QSizePolicy::Policy::Fixed);
        sizePolicy2.setHorizontalStretch(0);
        sizePolicy2.setVerticalStretch(0);
        sizePolicy2.setHeightForWidth(Botao_telaCarregaCSV->sizePolicy().hasHeightForWidth());
        Botao_telaCarregaCSV->setSizePolicy(sizePolicy2);
        Botao_telaCarregaCSV->setMinimumSize(QSize(200, 0));
        Botao_telaCarregaCSV->setCheckable(true);

        B->addWidget(Botao_telaCarregaCSV);

        Botao_TelaRelatorio = new QPushButton(BordaEscura);
        buttonGroup->addButton(Botao_TelaRelatorio);
        Botao_TelaRelatorio->setObjectName("Botao_TelaRelatorio");
        Botao_TelaRelatorio->setEnabled(true);
        sizePolicy2.setHeightForWidth(Botao_TelaRelatorio->sizePolicy().hasHeightForWidth());
        Botao_TelaRelatorio->setSizePolicy(sizePolicy2);
        Botao_TelaRelatorio->setMinimumSize(QSize(200, 0));
        Botao_TelaRelatorio->setCheckable(true);

        B->addWidget(Botao_TelaRelatorio);

        verticalSpacer_2 = new QSpacerItem(20, 50, QSizePolicy::Policy::Minimum, QSizePolicy::Policy::Expanding);

        B->addItem(verticalSpacer_2);

        Botao_sair = new QPushButton(BordaEscura);
        Botao_sair->setObjectName("Botao_sair");
        QSizePolicy sizePolicy3(QSizePolicy::Policy::Preferred, QSizePolicy::Policy::Fixed);
        sizePolicy3.setHorizontalStretch(0);
        sizePolicy3.setVerticalStretch(0);
        sizePolicy3.setHeightForWidth(Botao_sair->sizePolicy().hasHeightForWidth());
        Botao_sair->setSizePolicy(sizePolicy3);

        B->addWidget(Botao_sair);

        verticalSpacer = new QSpacerItem(20, 50, QSizePolicy::Policy::Minimum, QSizePolicy::Policy::Fixed);

        B->addItem(verticalSpacer);


        horizontalLayout->addWidget(BordaEscura);

        Lista_Frames = new QStackedWidget(centralwidget);
        Lista_Frames->setObjectName("Lista_Frames");
        Lista_Frames->setMinimumSize(QSize(0, 100));
        CarregandoArquivoCSV = new QWidget();
        CarregandoArquivoCSV->setObjectName("CarregandoArquivoCSV");
        verticalLayout_6 = new QVBoxLayout(CarregandoArquivoCSV);
        verticalLayout_6->setObjectName("verticalLayout_6");
        gridLayout = new QGridLayout();
        gridLayout->setSpacing(20);
        gridLayout->setObjectName("gridLayout");
        gridLayout->setSizeConstraint(QLayout::SizeConstraint::SetDefaultConstraint);
        gridLayout->setContentsMargins(20, 20, 20, 20);
        frame_2 = new QFrame(CarregandoArquivoCSV);
        frame_2->setObjectName("frame_2");
        QSizePolicy sizePolicy4(QSizePolicy::Policy::Expanding, QSizePolicy::Policy::Expanding);
        sizePolicy4.setHorizontalStretch(0);
        sizePolicy4.setVerticalStretch(0);
        sizePolicy4.setHeightForWidth(frame_2->sizePolicy().hasHeightForWidth());
        frame_2->setSizePolicy(sizePolicy4);
        frame_2->setMinimumSize(QSize(100, 0));
        frame_2->setFrameShape(QFrame::Shape::StyledPanel);
        frame_2->setFrameShadow(QFrame::Shadow::Raised);
        verticalLayout_5 = new QVBoxLayout(frame_2);
        verticalLayout_5->setObjectName("verticalLayout_5");
        gridLayout_2 = new QGridLayout();
        gridLayout_2->setObjectName("gridLayout_2");
        horizontalSpacer = new QSpacerItem(20, 20, QSizePolicy::Policy::Fixed, QSizePolicy::Policy::Minimum);

        gridLayout_2->addItem(horizontalSpacer, 3, 0, 1, 1);

        label_2 = new QLabel(frame_2);
        label_2->setObjectName("label_2");
        label_2->setAlignment(Qt::AlignmentFlag::AlignCenter);

        gridLayout_2->addWidget(label_2, 8, 1, 1, 1);

        label_3 = new QLabel(frame_2);
        label_3->setObjectName("label_3");
        label_3->setAlignment(Qt::AlignmentFlag::AlignCenter);

        gridLayout_2->addWidget(label_3, 11, 1, 1, 1);

        verticalSpacer_7 = new QSpacerItem(20, 40, QSizePolicy::Policy::Minimum, QSizePolicy::Policy::Expanding);

        gridLayout_2->addItem(verticalSpacer_7, 5, 1, 1, 1);

        label_5 = new QLabel(frame_2);
        label_5->setObjectName("label_5");
        label_5->setAlignment(Qt::AlignmentFlag::AlignCenter);

        gridLayout_2->addWidget(label_5, 14, 1, 1, 1);

        verticalSpacer_8 = new QSpacerItem(20, 40, QSizePolicy::Policy::Minimum, QSizePolicy::Policy::Expanding);

        gridLayout_2->addItem(verticalSpacer_8, 0, 1, 1, 1);

        horizontalSpacer_2 = new QSpacerItem(20, 20, QSizePolicy::Policy::Fixed, QSizePolicy::Policy::Minimum);

        gridLayout_2->addItem(horizontalSpacer_2, 3, 2, 1, 1);

        verticalSpacer_11 = new QSpacerItem(20, 20, QSizePolicy::Policy::Minimum, QSizePolicy::Policy::Fixed);

        gridLayout_2->addItem(verticalSpacer_11, 7, 1, 1, 1);

        lineEdit_2 = new QLineEdit(frame_2);
        lineEdit_2->setObjectName("lineEdit_2");
        lineEdit_2->setMinimumSize(QSize(0, 50));

        gridLayout_2->addWidget(lineEdit_2, 12, 1, 1, 1);

        label = new QLabel(frame_2);
        label->setObjectName("label");
        QSizePolicy sizePolicy5(QSizePolicy::Policy::Expanding, QSizePolicy::Policy::Fixed);
        sizePolicy5.setHorizontalStretch(0);
        sizePolicy5.setVerticalStretch(0);
        sizePolicy5.setHeightForWidth(label->sizePolicy().hasHeightForWidth());
        label->setSizePolicy(sizePolicy5);
        label->setMinimumSize(QSize(200, 0));
        label->setAlignment(Qt::AlignmentFlag::AlignCenter);

        gridLayout_2->addWidget(label, 3, 1, 1, 1);

        Titulo_memoria = new QLabel(frame_2);
        Titulo_memoria->setObjectName("Titulo_memoria");
        Titulo_memoria->setAlignment(Qt::AlignmentFlag::AlignCenter);

        gridLayout_2->addWidget(Titulo_memoria, 6, 1, 1, 1);

        verticalSpacer_12 = new QSpacerItem(20, 10, QSizePolicy::Policy::Minimum, QSizePolicy::Policy::Fixed);

        gridLayout_2->addItem(verticalSpacer_12, 10, 1, 1, 1);

        comboBox_2 = new QComboBox(frame_2);
        comboBox_2->addItem(QString());
        comboBox_2->addItem(QString());
        comboBox_2->addItem(QString());
        comboBox_2->setObjectName("comboBox_2");
        comboBox_2->setMinimumSize(QSize(200, 50));

        gridLayout_2->addWidget(comboBox_2, 15, 1, 1, 1);

        botao_IniciarSimulacao = new QPushButton(frame_2);
        botao_IniciarSimulacao->setObjectName("botao_IniciarSimulacao");

        gridLayout_2->addWidget(botao_IniciarSimulacao, 17, 1, 1, 1);

        Titulo_config = new QLabel(frame_2);
        Titulo_config->setObjectName("Titulo_config");
        Titulo_config->setAlignment(Qt::AlignmentFlag::AlignCenter);

        gridLayout_2->addWidget(Titulo_config, 1, 1, 1, 1);

        lineEdit = new QLineEdit(frame_2);
        lineEdit->setObjectName("lineEdit");
        lineEdit->setMinimumSize(QSize(0, 50));

        gridLayout_2->addWidget(lineEdit, 9, 1, 1, 1);

        verticalSpacer_13 = new QSpacerItem(20, 10, QSizePolicy::Policy::Minimum, QSizePolicy::Policy::Fixed);

        gridLayout_2->addItem(verticalSpacer_13, 13, 1, 1, 1);

        comboBox = new QComboBox(frame_2);
        comboBox->addItem(QString());
        comboBox->addItem(QString());
        comboBox->addItem(QString());
        comboBox->setObjectName("comboBox");
        sizePolicy5.setHeightForWidth(comboBox->sizePolicy().hasHeightForWidth());
        comboBox->setSizePolicy(sizePolicy5);
        comboBox->setMinimumSize(QSize(200, 50));

        gridLayout_2->addWidget(comboBox, 4, 1, 1, 1);

        verticalSpacer_10 = new QSpacerItem(20, 20, QSizePolicy::Policy::Minimum, QSizePolicy::Policy::Fixed);

        gridLayout_2->addItem(verticalSpacer_10, 2, 1, 1, 1);

        verticalSpacer_9 = new QSpacerItem(20, 40, QSizePolicy::Policy::Minimum, QSizePolicy::Policy::Expanding);

        gridLayout_2->addItem(verticalSpacer_9, 16, 1, 1, 1);

        verticalSpacer_16 = new QSpacerItem(20, 40, QSizePolicy::Policy::Minimum, QSizePolicy::Policy::Expanding);

        gridLayout_2->addItem(verticalSpacer_16, 18, 1, 1, 1);


        verticalLayout_5->addLayout(gridLayout_2);


        gridLayout->addWidget(frame_2, 0, 1, 1, 1);

        frame_3 = new QFrame(CarregandoArquivoCSV);
        frame_3->setObjectName("frame_3");
        sizePolicy4.setHeightForWidth(frame_3->sizePolicy().hasHeightForWidth());
        frame_3->setSizePolicy(sizePolicy4);
        frame_3->setMinimumSize(QSize(600, 0));
        frame_3->setFrameShape(QFrame::Shape::StyledPanel);
        frame_3->setFrameShadow(QFrame::Shadow::Raised);
        horizontalLayout_3 = new QHBoxLayout(frame_3);
        horizontalLayout_3->setObjectName("horizontalLayout_3");
        verticalLayout = new QVBoxLayout();
        verticalLayout->setObjectName("verticalLayout");
        Tabela_CSV = new QTableWidget(frame_3);
        Tabela_CSV->setObjectName("Tabela_CSV");
        Tabela_CSV->setTextElideMode(Qt::TextElideMode::ElideMiddle);

        verticalLayout->addWidget(Tabela_CSV);

        verticalSpacer_6 = new QSpacerItem(20, 10, QSizePolicy::Policy::Minimum, QSizePolicy::Policy::Fixed);

        verticalLayout->addItem(verticalSpacer_6);

        labelCSV = new QLabel(frame_3);
        labelCSV->setObjectName("labelCSV");
        sizePolicy2.setHeightForWidth(labelCSV->sizePolicy().hasHeightForWidth());
        labelCSV->setSizePolicy(sizePolicy2);
        labelCSV->setMinimumSize(QSize(0, 0));
        labelCSV->setMaximumSize(QSize(1000, 300));
        labelCSV->setTextFormat(Qt::TextFormat::MarkdownText);
        labelCSV->setAlignment(Qt::AlignmentFlag::AlignCenter);

        verticalLayout->addWidget(labelCSV);

        horizontalLayout_5 = new QHBoxLayout();
        horizontalLayout_5->setObjectName("horizontalLayout_5");
        Caminho_CSV = new QLineEdit(frame_3);
        Caminho_CSV->setObjectName("Caminho_CSV");
        sizePolicy5.setHeightForWidth(Caminho_CSV->sizePolicy().hasHeightForWidth());
        Caminho_CSV->setSizePolicy(sizePolicy5);
        Caminho_CSV->setMinimumSize(QSize(400, 0));
        Caminho_CSV->setMaximumSize(QSize(300, 300));
        Caminho_CSV->setReadOnly(true);

        horizontalLayout_5->addWidget(Caminho_CSV);

        Botao_AbrirArquivo = new QPushButton(frame_3);
        Botao_AbrirArquivo->setObjectName("Botao_AbrirArquivo");
        Botao_AbrirArquivo->setMaximumSize(QSize(200, 16777215));

        horizontalLayout_5->addWidget(Botao_AbrirArquivo);


        verticalLayout->addLayout(horizontalLayout_5);

        verticalSpacer_3 = new QSpacerItem(20, 10, QSizePolicy::Policy::Minimum, QSizePolicy::Policy::Fixed);

        verticalLayout->addItem(verticalSpacer_3);


        horizontalLayout_3->addLayout(verticalLayout);


        gridLayout->addWidget(frame_3, 0, 0, 1, 1);


        verticalLayout_6->addLayout(gridLayout);

        Lista_Frames->addWidget(CarregandoArquivoCSV);
        RelatorioDaSimulacao = new QWidget();
        RelatorioDaSimulacao->setObjectName("RelatorioDaSimulacao");
        verticalLayout_2 = new QVBoxLayout(RelatorioDaSimulacao);
        verticalLayout_2->setObjectName("verticalLayout_2");
        gridLayout_3 = new QGridLayout();
        gridLayout_3->setSpacing(20);
        gridLayout_3->setObjectName("gridLayout_3");
        gridLayout_3->setContentsMargins(20, 20, 20, 20);
        frame = new QFrame(RelatorioDaSimulacao);
        frame->setObjectName("frame");
        frame->setFrameShape(QFrame::Shape::StyledPanel);
        frame->setFrameShadow(QFrame::Shadow::Raised);
        verticalLayout_8 = new QVBoxLayout(frame);
        verticalLayout_8->setObjectName("verticalLayout_8");
        verticalLayout_7 = new QVBoxLayout();
        verticalLayout_7->setObjectName("verticalLayout_7");
        Titulo_MetricasIndividuais = new QLabel(frame);
        Titulo_MetricasIndividuais->setObjectName("Titulo_MetricasIndividuais");
        Titulo_MetricasIndividuais->setMinimumSize(QSize(500, 0));
        Titulo_MetricasIndividuais->setAlignment(Qt::AlignmentFlag::AlignCenter);

        verticalLayout_7->addWidget(Titulo_MetricasIndividuais);

        tableWidget = new QTableWidget(frame);
        tableWidget->setObjectName("tableWidget");
        sizePolicy4.setHeightForWidth(tableWidget->sizePolicy().hasHeightForWidth());
        tableWidget->setSizePolicy(sizePolicy4);

        verticalLayout_7->addWidget(tableWidget);

        horizontalLayout_2 = new QHBoxLayout();
        horizontalLayout_2->setObjectName("horizontalLayout_2");
        horizontalSpacer_3 = new QSpacerItem(40, 20, QSizePolicy::Policy::Expanding, QSizePolicy::Policy::Minimum);

        horizontalLayout_2->addItem(horizontalSpacer_3);

        Botao_gerarRelatorio = new QPushButton(frame);
        Botao_gerarRelatorio->setObjectName("Botao_gerarRelatorio");
        sizePolicy2.setHeightForWidth(Botao_gerarRelatorio->sizePolicy().hasHeightForWidth());
        Botao_gerarRelatorio->setSizePolicy(sizePolicy2);
        Botao_gerarRelatorio->setMinimumSize(QSize(300, 0));

        horizontalLayout_2->addWidget(Botao_gerarRelatorio);

        horizontalSpacer_4 = new QSpacerItem(40, 20, QSizePolicy::Policy::Expanding, QSizePolicy::Policy::Minimum);

        horizontalLayout_2->addItem(horizontalSpacer_4);


        verticalLayout_7->addLayout(horizontalLayout_2);


        verticalLayout_8->addLayout(verticalLayout_7);


        gridLayout_3->addWidget(frame, 0, 0, 1, 1);

        frame_4 = new QFrame(RelatorioDaSimulacao);
        frame_4->setObjectName("frame_4");
        frame_4->setFrameShape(QFrame::Shape::StyledPanel);
        frame_4->setFrameShadow(QFrame::Shadow::Raised);
        verticalLayout_10 = new QVBoxLayout(frame_4);
        verticalLayout_10->setObjectName("verticalLayout_10");
        verticalLayout_9 = new QVBoxLayout();
        verticalLayout_9->setObjectName("verticalLayout_9");
        verticalSpacer_14 = new QSpacerItem(20, 40, QSizePolicy::Policy::Minimum, QSizePolicy::Policy::Expanding);

        verticalLayout_9->addItem(verticalSpacer_14);

        Titulo_LinhaTempo = new QLabel(frame_4);
        Titulo_LinhaTempo->setObjectName("Titulo_LinhaTempo");
        Titulo_LinhaTempo->setAlignment(Qt::AlignmentFlag::AlignCenter);

        verticalLayout_9->addWidget(Titulo_LinhaTempo);

        tableWidget_2 = new QTableWidget(frame_4);
        tableWidget_2->setObjectName("tableWidget_2");

        verticalLayout_9->addWidget(tableWidget_2);

        verticalSpacer_5 = new QSpacerItem(20, 40, QSizePolicy::Policy::Minimum, QSizePolicy::Policy::Expanding);

        verticalLayout_9->addItem(verticalSpacer_5);

        Titulo_MetricasGerais = new QLabel(frame_4);
        Titulo_MetricasGerais->setObjectName("Titulo_MetricasGerais");
        Titulo_MetricasGerais->setAlignment(Qt::AlignmentFlag::AlignCenter);

        verticalLayout_9->addWidget(Titulo_MetricasGerais);

        tableWidget_3 = new QTableWidget(frame_4);
        tableWidget_3->setObjectName("tableWidget_3");

        verticalLayout_9->addWidget(tableWidget_3);

        verticalSpacer_15 = new QSpacerItem(20, 40, QSizePolicy::Policy::Minimum, QSizePolicy::Policy::Expanding);

        verticalLayout_9->addItem(verticalSpacer_15);


        verticalLayout_10->addLayout(verticalLayout_9);


        gridLayout_3->addWidget(frame_4, 0, 1, 1, 1);


        verticalLayout_2->addLayout(gridLayout_3);

        Lista_Frames->addWidget(RelatorioDaSimulacao);

        horizontalLayout->addWidget(Lista_Frames);


        verticalLayout_4->addLayout(horizontalLayout);


        verticalLayout_3->addLayout(verticalLayout_4);

        MainWindow->setCentralWidget(centralwidget);

        retranslateUi(MainWindow);

        Lista_Frames->setCurrentIndex(0);


        QMetaObject::connectSlotsByName(MainWindow);
    } // setupUi

    void retranslateUi(QMainWindow *MainWindow)
    {
        MainWindow->setWindowTitle(QCoreApplication::translate("MainWindow", "MainWindow", nullptr));
        Titulo->setText(QCoreApplication::translate("MainWindow", "Projeto SO", nullptr));
        Titulo->setProperty("class", QVariant(QCoreApplication::translate("MainWindow", "subTitulo", nullptr)));
        Botao_telaCarregaCSV->setText(QCoreApplication::translate("MainWindow", "Carregando arquivo CSV", nullptr));
        Botao_TelaRelatorio->setText(QCoreApplication::translate("MainWindow", "Relat\303\263rio da Simula\303\247\303\243o", nullptr));
        Botao_sair->setText(QCoreApplication::translate("MainWindow", "Sair", nullptr));
        frame_2->setProperty("class", QVariant(QCoreApplication::translate("MainWindow", "Frame_painel", nullptr)));
        label_2->setText(QCoreApplication::translate("MainWindow", "Tamanho Mem\303\263ria F\303\255sica", nullptr));
        label_3->setText(QCoreApplication::translate("MainWindow", "Tamanho Mem\303\263ria Virtual", nullptr));
        label_5->setText(QCoreApplication::translate("MainWindow", "Pol\303\255ticas de Substitui\303\247\303\243o", nullptr));
        label->setText(QCoreApplication::translate("MainWindow", "Algoritmo de Escalonamento", nullptr));
        Titulo_memoria->setText(QCoreApplication::translate("MainWindow", "Gerenciamento de Mem\303\263ria", nullptr));
        Titulo_memoria->setProperty("class", QVariant(QCoreApplication::translate("MainWindow", "subTitulo", nullptr)));
        comboBox_2->setItemText(0, QCoreApplication::translate("MainWindow", "FIFO", nullptr));
        comboBox_2->setItemText(1, QCoreApplication::translate("MainWindow", "LRU", nullptr));
        comboBox_2->setItemText(2, QCoreApplication::translate("MainWindow", "\303\223timo", nullptr));

        botao_IniciarSimulacao->setText(QCoreApplication::translate("MainWindow", "Iniciar Simula\303\247\303\243o", nullptr));
        Titulo_config->setText(QCoreApplication::translate("MainWindow", "Configura\303\247\303\265es da Simula\303\247\303\243o", nullptr));
        Titulo_config->setProperty("class", QVariant(QCoreApplication::translate("MainWindow", "subTitulo", nullptr)));
        comboBox->setItemText(0, QCoreApplication::translate("MainWindow", "Round-Robin(RR)", nullptr));
        comboBox->setItemText(1, QCoreApplication::translate("MainWindow", "SJF Preemptivo", nullptr));
        comboBox->setItemText(2, QCoreApplication::translate("MainWindow", "Prioridade Preemptiva", nullptr));

        frame_3->setProperty("class", QVariant(QCoreApplication::translate("MainWindow", "Frame_painel", nullptr)));
        labelCSV->setText(QCoreApplication::translate("MainWindow", "Lista de Processos", nullptr));
        Botao_AbrirArquivo->setText(QCoreApplication::translate("MainWindow", "Abrir Arquivo", nullptr));
        Titulo_MetricasIndividuais->setText(QCoreApplication::translate("MainWindow", "M\303\251tricas Individuais dos Processos", nullptr));
        Botao_gerarRelatorio->setText(QCoreApplication::translate("MainWindow", "Gerar Relat\303\263rio", nullptr));
        Titulo_LinhaTempo->setText(QCoreApplication::translate("MainWindow", "Linha do Tempo da Execu\303\247\303\243o", nullptr));
        Titulo_MetricasGerais->setText(QCoreApplication::translate("MainWindow", "M\303\251tricas gerais  de Performance", nullptr));
    } // retranslateUi

};

namespace Ui {
    class MainWindow: public Ui_MainWindow {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_MAINWINDOW_H
