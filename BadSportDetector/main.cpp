#include "widget.h"

#include <QApplication>

int main(int argc, char *argv[])
{
    QApplication a(argc, argv);
    QApplication::setOrganizationName("Zerkalo2147");
    QApplication::setApplicationVersion("1.1.1");
    QApplication::setApplicationName(QObject::tr("GTAOL恶意值查询工具"));
    Widget w;
    w.show();
    return a.exec();
}
