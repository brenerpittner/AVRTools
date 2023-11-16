#include "app.h"


App::App(QWidget* parent) //* pega o valor do endereço & aponta para o endereço
    : QMainWindow(parent)
{
    ui.setupUi(this);

    this->resize(280, 150);

    pushButton_2 = new QPushButton(this);
    pushButton_2->setObjectName(QString::fromUtf8("pushButton_2"));
    pushButton_2->setGeometry(QRect(5, 20, 75, 25)); // posição x , posição y, comprimento em x, comprimento em y
    pushButton_2->setText("Select File");
    QObject::connect(pushButton_2, SIGNAL(clicked()), this, SLOT(fileDialog()));

    label_path = new QLabel(this);
    label_path->setObjectName(QString::fromUtf8("label_path"));
    label_path->setGeometry(QRect(90, 20, 500, 25)); //int left, int top, int width, int height
    label_path->setText("<-- select file here");

    comboBox_com_port = new QComboBox(this);
    comboBox_com_port->setObjectName(QString::fromUtf8("comboBox_com_port"));
    comboBox_com_port->setGeometry(QRect(5, 50, 75, 25));
    QObject::connect(comboBox_com_port, SIGNAL(currentIndexChanged(int)), this, SLOT(setComPort(int)));

    pushButton_update_com_port = new QPushButton(this);
    pushButton_update_com_port->setObjectName(QString::fromUtf8("pushButton_2"));
    pushButton_update_com_port->setGeometry(QRect(90, 50, 50, 25)); // posição x , posição y, comprimento em x, comprimento em y
    pushButton_update_com_port->setText("reload");
    QObject::connect(pushButton_update_com_port, SIGNAL(clicked()), this, SLOT(get_com_port()));

    comboBox_board = new QComboBox(this);
    comboBox_board->setObjectName(QString::fromUtf8("comboBox_com_port"));
    comboBox_board->setGeometry(QRect(150, 50, 100, 25));
    QObject::connect(comboBox_board, SIGNAL(currentIndexChanged(int)), this, SLOT(setBoard(int)));

    pushButton_start = new QPushButton(this);
    pushButton_start->setObjectName(QString::fromUtf8("pushButton"));
    pushButton_start->setGeometry(QRect(5, 80, 75, 25));
    pushButton_start->setText("Start");
    QObject::connect(pushButton_start, SIGNAL(clicked()), this, SLOT(command()));

    label_result = new QLabel(this);
    label_result->setObjectName(QString::fromUtf8("label_result"));
    label_result->setGeometry(QRect(20, 100, 500, 25)); //int left, int top, int width, int height
    //label_result->setText("...");

    get_com_port();
    listBoard();
    statusBar()->showMessage(tr("Bem-vindo !"), 2000);
};

App::~App()
{
    
}

void App::fileDialog(){
    path_file = QFileDialog::getOpenFileName(this,
        tr("Open"), QCoreApplication::applicationDirPath() + "/*.hex", tr("hex File (*.hex)"));

    const QFileInfo info(path_file);
    const QString file(info.fileName());

    qDebug() << path_file;
    label_path->setText(file);
}

void App::command() {
    QString mensagem = "App::command() - clicked";
    qDebug() << mensagem;

    if (path_file.isEmpty()) {
        qDebug() << "O path_file esta vazia";
        path_file = QCoreApplication::applicationDirPath() + "/test.hex";
    }
    else {
        qDebug() << "O path_file não esta vazia";
    }

    if (com_port.isEmpty()) {
        qDebug() << "A com_port esta vazia";
    }
    else {
        qDebug() << "A com_port não esta vazia";
    }

    QString avrdudePath = QCoreApplication::applicationDirPath() + QString("/avrdude.exe -c arduino -p %3 -P %2 -b 115200 -U flash:w:\"%1\":a").arg(path_file, com_port, board);
    qDebug() << avrdudePath;

    QProcess avrdudeProcess;
    avrdudeProcess.start(avrdudePath);

    if (avrdudeProcess.waitForStarted() && avrdudeProcess.waitForFinished()) {
        qDebug() << "avrdude executado com sucesso. Saída:" << avrdudeProcess.readAllStandardOutput();
        QString msg_sucess = "Sucesso !";
        statusBar()->showMessage(msg_sucess, 2000);
    }
    else {
        qDebug() << "Falha ao executar avrdude. Erro:" << avrdudeProcess.errorString();
        QString msg_fail = "Falha !";
        statusBar()->showMessage(msg_fail, 2000);
    }
}

void App::get_com_port() {
    comboBox_com_port->clear();
    com_ports.clear();

    Q_FOREACH(const QSerialPortInfo & serialPortInfo, QSerialPortInfo::availablePorts())
    {
        comboBox_com_port->addItem(serialPortInfo.portName());// +" - " + serialPortInfo.description());
        com_ports << serialPortInfo.portName();

        com_port = com_ports.value(comboBox_com_port->currentIndex());
        qDebug() << com_ports;
    }
}

void App::setComPort(int index)
{
    com_port = com_ports.value(index);
    qDebug() << "com_port set to: " << com_port;
}

void App::listBoard() {

    // Adicionando itens ao modelo
    foreach(const QString & text, boards) {
        QStandardItem* item = new QStandardItem(text);
        model_board->appendRow(item);
    }
    comboBox_board->setModel(model_board);
}


void App::setBoard(int index)
{
    board = partno.value(index);
    qDebug() << "board set to: " << board;
}