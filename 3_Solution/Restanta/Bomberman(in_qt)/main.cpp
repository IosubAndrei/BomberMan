#include "bomberman_dialog.h"

#include <QApplication>

int main(int argc, char *argv[])
{
    QApplication a(argc, argv);
    Bomberman_dialog w;
    w.show();
    return a.exec();
}