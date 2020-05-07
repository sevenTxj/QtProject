#include "mainwindow.h"
#include <QApplication>
#include "addrbook.h"

int main(int argc, char *argv[])
{
    QApplication a(argc, argv);

    AddrBook *addrBook = new AddrBook;
    addrBook->show();

    return a.exec();
}
