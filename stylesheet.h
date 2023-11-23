#ifndef STYLESHEET_H
#define STYLESHEET_H

#include <QWidget>
#include <QDir>
#include <QMessageBox>
#include <QDebug>

class StyleSheet: public QWidget
{
public:
    StyleSheet();
    QString getStyleFile(QString strDirPath);
};

#endif // STYLESHEET_H
