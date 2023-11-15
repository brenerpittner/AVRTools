#pragma once
#include "ui_MainWindow.h"

#include <QtWidgets/QMainWindow>
#include <QProcess>
#include <QtCore/QtDebug>

#include <QFileDialog>
#include <QtWidgets/QLabel>     

class App : public QMainWindow
{
    Q_OBJECT

public:
    App(QWidget* parent = nullptr);
    ~App();

    QString path_file;

 
private:
    Ui::MainWindow ui;

    QLabel* label;
    QPushButton* pushButton_2;

public slots:
    void command();
    void fileDialog();
};
