#include "bojack.h"

#include <QApplication>

int main(int argc, char *argv[])
{
    QApplication a(argc, argv);
    Bojack w;
    w.show();
    return a.exec();
}
