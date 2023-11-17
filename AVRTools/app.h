 #pragma once
#include "ui_MainWindow.h"

#include <QtWidgets/QMainWindow>

#include <QtWidgets/QComboBox>
#include <QStandardItemModel>
#include <QStandardItem>

#include <QtWidgets/QPushButton>
#include <QProcess>
#include <QtCore/QtDebug>

#include <QFileDialog>
#include <QtWidgets/QLabel>    

#include <QSerialPortInfo>      // used to get portCOM descriptions
#include <QIcon>

//#include "../About/about.h"
#include <QWidget>

#include "about.h"

#define FULLNAME "AVRTools"
#define STRING_SPACE  
#define DEFAULT_VERSION 1.0
#define ICON_APP ":/general/app_icon_default"
#define ICON_UNDO ":/general/undo"


class App : public QMainWindow
{
    Q_OBJECT


public:
    App(QWidget* parent = nullptr);
    ~App();

    QString path_file;
    QString com_port;
    QString board;
    QStringList com_ports;
    QStringList boards = { "Arduino uno", "Arduino nano"};
    QStringList partno = { "atmega328p", "m328p" };

private:
    Ui::MainWindow ui;

    About about;

    QLabel* label_path;
    QLabel* label_result;
    QComboBox* comboBox_com_port;

    QStandardItemModel* model_board = new QStandardItemModel();
    QComboBox* comboBox_board;

    QPushButton* pushButton_start;
    QPushButton* pushButton_about;
    QPushButton* pushButton_2;
    QPushButton* pushButton_update_com_port;

    void listBoard();

public slots:
    void command();
    void fileDialog();
    void setComPort(int);
    void setBoard(int);
    void get_com_port();
    void slot_ShowAbout();
};