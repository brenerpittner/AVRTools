#pragma once
#include "ui_MainWindow.h"

#include <QtWidgets/QMainWindow>
#include <QtWidgets/QComboBox>
#include <QtWidgets/QPushButton>
#include <QProcess>
#include <QtCore/QtDebug>

#include <QFileDialog>
#include <QtWidgets/QLabel>    

#include <QSerialPortInfo>      // used to get portCOM descriptions

class App : public QMainWindow
{
    Q_OBJECT

public:
    App(QWidget* parent = nullptr);
    ~App();

    QString path_file;
    QString com_port;
    QStringList com_ports;

    

 
private:
    Ui::MainWindow ui;

    QLabel* label_path;
    QLabel* label_result;
    QComboBox* comboBox_com_port;
    QPushButton* pushButton_start;
    QPushButton* pushButton_2;
    QPushButton* pushButton_update_com_port;

    

public slots:
    void command();
    void fileDialog();
    void setComPort(int);
    void get_com_port();
    
};
