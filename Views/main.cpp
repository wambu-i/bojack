#include "mainwindow.h"
#include <QApplication>

int main(int argc, char *argv[]){
    QApplication bojack(argc, argv);

    MainWindow window;
    window.show();

    return bojack.exec();
}
