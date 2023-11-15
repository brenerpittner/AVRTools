#include "app.h"

App::App(QWidget* parent) //* pega o valor do endereço & aponta para o endereço
    : QMainWindow(parent)
{
    ui.setupUi(this);

    ui.pushButton->setGeometry(QRect(660, 20, 75, 23));
    QObject::connect(ui.pushButton, SIGNAL(clicked()), this, SLOT(command()));


    pushButton_2 = new QPushButton(this);
    pushButton_2->setObjectName(QString::fromUtf8("pushButton_2"));
    pushButton_2->setGeometry(QRect(5, 20, 75, 23)); // posição x , posição y, comprimento em x, comprimento em y
    pushButton_2->setText("Select File");
    QObject::connect(pushButton_2, SIGNAL(clicked()), this, SLOT(fileDialog()));

    label = new QLabel(this);
    label->setObjectName(QString::fromUtf8("label"));
    label->setGeometry(QRect(100, 20, 300, 25)); //int left, int top, int width, int height
    label->setText("<-- select file here");
};

App::~App()
{
    
}

void App::fileDialog(){
    path_file = QFileDialog::getOpenFileName(this,
        tr("Open"), "/home/*.hex", tr("hex File (*.hex)"));

    qDebug() << path_file;
    label->setText(path_file);
}

void App::command() {
    QString mensagem = "App::command() - clicked";
    qDebug() << mensagem;

    QString program("cmd.exe");
    QStringList parameters;
    QString command = "avrdude.exe - c arduino - p m328p - P COM3 - b 115200 - U flash : w:E:\Pessoal\BeautifulDay\arduino\GRAVAÇÃO\BeautifulDay_31102023.ino.hex : a";
    
    //parameters << " /k" << "cd " << QCoreApplication::applicationDirPath() << " & file.exe";
    qDebug() << path_file;
    parameters << " /k" << command;
    QProcess::startDetached(program, parameters);
}