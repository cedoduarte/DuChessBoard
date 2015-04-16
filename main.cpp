#include "Widget.h"
#include "DuDefines.h"
#include <QApplication>

int main(int argc, char *argv[])
{
    QApplication a(argc, argv);
    a.setApplicationName(APP_NAME);
    a.setApplicationVersion(APP_VER);
    a.setOrganizationDomain(ORG_DOM);
    a.setOrganizationName(ORG_NAME);
    a.setStyle("fusion");
    Widget w;
    w.showMaximized();
    return a.exec();
}
