#include "widget.h"
#include "ui_widget.h"

Widget::Widget(QWidget *parent)
    : QWidget(parent)
    , ui(new Ui::Widget)
{
    ui->setupUi(this);
    //当qss文件比较多时，通过多次调用loadStyleSheet()函数来设置样式
    this->loadStyleSheet("../test_ui/qss/ui1.qss");
    this->loadStyleSheet("../test_ui/qss/ui2.qss");
}

Widget::~Widget()
{
    delete ui;
}

void Widget::loadStyleSheet(const QString &styleSheetFile)
{
    QFile file(styleSheetFile);
    file.open(QFile::ReadOnly);
    if (file.isOpen())
    {
        QString styleSheet = this->styleSheet();//初次为空
        styleSheet += QLatin1String(file.readAll());//读取样式表文件
        this->setStyleSheet(styleSheet);//把文件内容传参
        file.close();
    }
    else
    {
        QMessageBox::information(this,"tip","cannot find qss file");
    }
}

