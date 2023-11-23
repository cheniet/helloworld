#include "widget.h"
#include "form.h"
#include "stylesheet.h"
#include <QApplication>
#include <QMovie>
#include <QLabel>
#include <QTime>

int main(int argc, char *argv[])
{
    QApplication a(argc, argv);

#if 0
    //方式一：QSplashScreen 静态图片(png、jpg等格式)
    //创建启动动画类实例
    QSplashScreen splash(QPixmap("C:/Users/10600/Pictures/imgs/p1.png")); //文件绝对路径 也可以使用相对路径
    splash.showMessage(QStringLiteral("正在初始化..."));//消息提示
    splash.show(); //显示

    a.processEvents(); //保证先完成启动画面的绘制显示，再执行后面的w显示

    //主界面显示
    MainWindow w;
    w.show();

    splash.finish(&w); //结束
#endif

#if 1
    //方式二：QMovie 动态图片(gif格式)
    //QMovie movie("C:/Users/10600/Pictures/tai.gif");
    QMovie movie("../test_ui/open.gif");
    QLabel label;

    label.setGeometry(300, 300, 500, 500);
    label.setMovie(&movie);
    label.setScaledContents(true); //自动适应窗口大小
    label.setWindowFlags(Qt::FramelessWindowHint); //去除边框

    movie.start();
    label.show();

    //延迟5秒
    QTime t;
    t.start();
    while(t.elapsed() < 5000)//5s
    {
        QApplication::processEvents();
    }

    //主界面显示
    Widget w;
    w.show();
    label.close();
    return a.exec();
#endif


#if 0
    //方式三：QAxWidget 视频(swf格式)
    QTextCodec *codec = QTextCodec::codecForName("GB2312"); //文本为GB2312编码
    QTextCodec::setCodecForLocale(codec); //设置本地编码

    QAxWidget flash;
    flash.resize(800,600); //设置该控件的初始大小
    flash.setControl(QString::fromUtf8("{d27cdb6e-ae6d-11cf-96b8-444553540000}")); //设定控制器
    flash.dynamicCall("LoadMovie(long,string)", 0, "C:/Users/10600/Videos/2.swf"); //文件绝对路径 也可以使用相对路径
    flash.setWindowFlags(Qt::FramelessWindowHint); //去除边框
    flash.show();

    //延迟5秒
    QTime t;
    t.start();
    while(t.elapsed() < 5000)
    {
        QApplication::processEvents();
    }
#endif

    //    Widget w;
    //    w.show();

    //    Form m;
    //    m.show();
    //    StyleSheet m_style;
    //    QString str_style=m_style.getStyleFile("../test_ui/qss");//qss样式文件的相对路径
    //    qApp->setStyleSheet(str_style);
    //    return a.exec();//循环等待，处理队列中的事件
}
