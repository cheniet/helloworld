#include "stylesheet.h"

StyleSheet::StyleSheet()
{

}

//一次性设置所有样式
QString StyleSheet::getStyleFile(QString strDirPath)//获取qss文件夹里的所有样式文件
{
    QStringList strListStyleFiles = QDir(strDirPath).entryList(QDir::Files);//获得该目录下的所有文件名称
    qDebug()<<strListStyleFiles;

    if (!strDirPath.endsWith("/"))
    {
        strDirPath.append("/");
    }
    QString strStyle;
    for (auto strFileName : strListStyleFiles)
    {
        QFile fileRead(strDirPath + strFileName);
        //qDebug()<<strDirPath + strFileName;
        if (fileRead.open(QFile::ReadOnly))
        {
            qDebug()<<"open qss file ok";
            strStyle += QLatin1String(fileRead.readAll());
        }
        else
        {
            qDebug()<<"open qss file error";
            QMessageBox::information(this,"tip","cannot find qss file");
        }
        fileRead.close();
    }
    return strStyle;//返回值：所有样式文件里的内容
}

