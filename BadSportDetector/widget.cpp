#include "widget.h"
#include "ui_widget.h"
#include "MemoryUtil.h"
#include <QMessageBox>
Widget::Widget(QWidget *parent)
    : QWidget(parent)
    , ui(new Ui::BadSportDetector)
{
    //this->setFixedSize(320,480);
    ui->setupUi(this);

}

Widget::~Widget()
{
    delete ui;
}

bool Widget::readBadSportValue() {
    gtaHandle = MemoryUtil::getProcessHandle(&pid);
    if (!gtaHandle) {
        QMessageBox::critical(nullptr, QString(), tr("GTA5未在运行中，请以管理员身份运行本程序,启动或重启游戏后再次尝试！"));
        return false;
    }
    int offsets[5] = { 0xDC8, 0x118, 0x18, 0xB0, 0xA08 };
    static DWORD64 ptr;
    static float Value = 0;
    ReadProcessMemory(gtaHandle,
                      (LPCVOID)((DWORD64)MemoryUtil::getProcessModuleHandle(pid, L"GTA5.exe") + 0x02EF5880),
                      &ptr, sizeof(DWORD64), 0);
    for (int i = 0; i < sizeof(offsets) / sizeof(offsets[0]) - 1; i++) {
        ReadProcessMemory(gtaHandle, (LPCVOID)(ptr + offsets[i]), &ptr, sizeof(DWORD64), 0);
    }
    ReadProcessMemory(gtaHandle, (LPCVOID)(ptr + offsets[4]), &Value, 4, 0);
    BadSportValue = Value;
    return true;
}
void Widget::on_pushBtnRefresh_clicked()
{
    if(readBadSportValue()){
        ui->labBadSportValue->setText(QString::number(BadSportValue));
        ui->labBadSportValue->setAlignment(Qt::AlignCenter);
        if(BadSportValue <= 20){
            ui->labBadSportValue->setStyleSheet("color:green;");
        }else if(BadSportValue < 40){
            ui->labBadSportValue->setStyleSheet("color:darkorange;");
        }else{
            ui->labBadSportValue->setStyleSheet("color:red;");
        }
    }
}

void Widget::on_pushBtnAbout_clicked()
{
    QMessageBox::about(this,QString(),license);
}



