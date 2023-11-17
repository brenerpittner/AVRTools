#include "about.h"

About::About(QWidget *parent)
	: QWidget(parent)
{
	ui.setupUi(this);

    pushButton_GitHub = new QPushButton(this);
    //pushButton_GitHub->setObjectName(QString::fromUtf8("pushButton_GitHub"));
    pushButton_GitHub->setGeometry(QRect(5, 5, 40, 40)); // posi??o x , posi??o y, comprimento em x, comprimento em y
    pushButton_GitHub->setIcon(QIcon(ICON_GITHUB));
    pushButton_GitHub->setIconSize(QSize(35, 35));
    QString link = QString::fromStdString(LINK_GITHUB);
    //QObject::connect(pushButton_GitHub, SIGNAL(clicked()), this, SLOT(openLink()));
    QObject::connect(pushButton_GitHub, &QPushButton::clicked, this, [=]() {
        slotOpenLink(link);
        });

}

About::~About()
{}

void About::slotOpenLink(const QString& link) {
	qDebug() << link;
	QDesktopServices::openUrl(QUrl(link));
}
