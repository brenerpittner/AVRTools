#include "about.h"

About::About(QWidget *parent)
	: QWidget(parent)
{
	ui.setupUi(this);

    this->resize(150, 150);
    this->setFixedSize(size()); //fix main window

    pushButton_GitHub = new QPushButton(this);
    setpushButton(pushButton_GitHub, QRect(5, 5, 40, 40), QIcon(ICON_GITHUB), LINK_GITHUB);

    pushButton_Linkedin = new QPushButton(this);
    setpushButton(pushButton_Linkedin, QRect(50, 5, 40, 40), QIcon(ICON_LINKEDIN), LINK_LINKEDIN);

    label_developer = new QLabel(this);
    label_developer->setObjectName(QString::fromUtf8("label_developer"));
    label_developer->setGeometry(QRect(5, 50, 500, 25)); //int left, int top, int width, int height
    label_developer->setText("Brener Pittner");

    label_email = new QLabel(this);
    label_email->setObjectName(QString::fromUtf8("label_email"));
    label_email->setGeometry(QRect(5, 65, 500, 25)); //int left, int top, int width, int height
    label_email->setText("pittner@live.com");

    pushButton_close = new QPushButton(this);
    pushButton_close->setGeometry(QRect(45, 120, 50, 25));
    pushButton_close->setText("Close");
    QObject::connect(pushButton_close, SIGNAL(clicked()), this, SLOT(slotCloseAbout()));
}

About::~About()
{}

void About::setpushButton(QPushButton* btn, QRect geometry, QIcon icon, std::string link) {

    btn->setGeometry(geometry); // position x , position y, lenth x, height y
    btn->setIcon(icon);
    btn->setIconSize(QSize(35, 35));

    QString qlink = QString::fromStdString(link);
    QObject::connect(btn, &QPushButton::clicked, this, [=]() {
        slotOpenLink(qlink);
        });
}

void About::slotOpenLink(const QString& link) {
	qDebug() << link;
	QDesktopServices::openUrl(QUrl(link));
}

void About::slotCloseAbout() {
    qDebug() << "close about";
    this->close();
}
