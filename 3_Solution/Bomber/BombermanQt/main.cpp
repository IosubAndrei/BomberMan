#include <QApplication>   //includ libraria QT Application
#include <QLabel> //folosita pentru text, aici nu o folosesc
#include <QWidget>
#include "mainwindow.h"

int main(int argc, char *argv[]) {

    QApplication a(argc, argv); //definesc obiect cu cele 2 argumente

    MainWindow w;
    w.show();

    return a.exec(); //return



}
