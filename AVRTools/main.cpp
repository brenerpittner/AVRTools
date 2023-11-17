#include "app.h"

int main(int argc, char* argv[])
{
    QApplication a(argc, argv);
    a.setWindowIcon(QIcon(ICON_APP));
    //a.setApplicationName(APP_NAME);
    //a.setOrganizationName(ORG_NAME);
    //a.setApplicationVersion(DEFAULT_VERSION);

    App w;
    w.setWindowTitle(QString::fromStdString(FULLNAME) + STRING_SPACE + DEFAULT_VERSION);
    w.show();

    return a.exec();
}