#pragma once

#include <QWidget>
#include "ui_about.h"

#include <QtWidgets/QPushButton>	// Used to create buttons
#include "QDesktopServices"
#include "QUrl"
#include <QDebug>					// Used to qDebug()

#include "definitions.h"

class About : public QWidget
{
	Q_OBJECT

public:
	About(QWidget *parent = nullptr);
	~About();

private:
	Ui::AboutClass ui;

	QPushButton* pushButton_GitHub;

public slots:
	void slotOpenLink(const QString&);
};
