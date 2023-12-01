#ifndef WIDGET_H
#define WIDGET_H

#include <QWidget>
#include <windows.h>
#include <QApplication>
QT_BEGIN_NAMESPACE
namespace Ui {
class BadSportDetector;
}
QT_END_NAMESPACE

class Widget : public QWidget
{
    Q_OBJECT

public:
    Widget(QWidget *parent = nullptr);
    ~Widget();

private slots:
    void on_pushBtnRefresh_clicked();

    void on_pushBtnAbout_clicked();

private:
    Ui::BadSportDetector *ui;

    bool readBadSportValue();
    float BadSportValue = -1;

    DWORD pid = 0;

    HANDLE gtaHandle = NULL;

    QString license = "<h3>" + QApplication::applicationDisplayName()
                      + " v" + QApplication::applicationVersion() + "</h3>"
                      + "<p>" + tr("本工具只读取内存，没有任何修改内存行为。") + "</p>"
                      + "<p>" + tr("请以管理身份运行本程序！请在进入在线战局后刷新！") + "</p>"
                      + "<p>" + tr("作者：") +"<a href='https://github.com/Zerkalo2147'>" +tr("<b>%1</b>").arg(QApplication::organizationName())  +"</a>"+ "</p>"
                      + "<p>" + tr("特别感谢：") + "<a href='https://github.com/SkyD666'>" +tr("<b>SkyD666</b>")+ "</a>"+tr("提供大量技术支持！") + "</p>"
                      + "<p>" + "<a href='https://github.com/Zerkalo2147/GTAOL-BadSportDetector'>" +tr("<b>软件源码</b>")+ "</a>" + "</p>"
                      + "<p>" + tr("感谢所有参与测试的朋友们！") + "</p>";
};
#endif // WIDGET_H
