#ifndef BOJACK_H
#define BOJACK_H

#include <QMainWindow>
#include "filemenu.h"
#include "editmenu.h"
#include "commandline.h"

QT_BEGIN_NAMESPACE
namespace Ui { class Bojack; }
QT_END_NAMESPACE

class Bojack : public QMainWindow
{
    Q_OBJECT

public:
    Bojack(QWidget *parent = nullptr);
    ~Bojack();

private:
    Ui::Bojack *ui;

    QString title = "Bojack Kills";
    int width = 700, height = 900;

    void setName() {
        this->setWindowTitle(Bojack::title);
    }

    void setUpWindow(QWidget *);
    void createMenuBar();

    // Menus
    QMenuBar *menuBar;
    FileMenu *filemenu;
    EditMenu *editmenu;

    // Objects
    CommandLine *cmd;
};
#endif // BOJACK_H
