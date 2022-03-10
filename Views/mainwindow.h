#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>

#include "filemenu.h"
#include "editmenu.h"
#include "aboutmenu.h"

class QString;

class FileMenu;
class EditMenu;
class AboutMenu;

namespace Ui {
class MainWindow;
}

class MainWindow : public QMainWindow {
    Q_OBJECT

public:
    explicit MainWindow(QWidget *parent = 0);

    ~MainWindow();

private:
    Ui::MainWindow *ui;
    QString main_title = "Bojack Kills";

    int width;
    int height;

    FileMenu *filemenu;
    EditMenu *editmenu;
    AboutMenu *aboutmenu;
    MainWindow *duplicate;

    void setName() {
        this->setWindowTitle(MainWindow::main_title);
    };

    void resizeMainWindow();
    void setUp(QWidget *);

private slots:
    //void openNewWindow();

};

#endif
