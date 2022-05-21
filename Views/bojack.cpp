#include <QLabel>
#include <QMessageBox>
#include "bojack.h"
#include "commandline.h"
#include "ui_bojack.h"

Bojack::Bojack(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::Bojack)
{
    this->setCentralWidget(parent);
    ui->setupUi(this);
    this->resize(Bojack::width, Bojack::height);
    this->setUpWindow(ui->centralwidget);
    this->createMenuBar();

    this->cmd = new CommandLine(ui->centralwidget);
    //this->cmd->drawLineText(ui->centralwidget);
    //auto layout = this->cmd->returnCmdLayout();
    QHBoxLayout *layout = new QHBoxLayout(ui->centralwidget);
    layout->addWidget(this->cmd->returnCmdWidget());
    connect(this->cmd, SIGNAL(enterPressed()), this, SLOT(drawTextLabel()));
    ui->centralwidget->setLayout(layout);
    //ui->centralwidget->show();
}

void Bojack::drawTestText() {
    QMessageBox::information(this, "TEST", "1", QMessageBox::Ok);
}

Bojack::~Bojack()
{
    delete ui;
}
void Bojack::drawTextLabel() {
    QLabel *label = new QLabel(this->ui->centralwidget);
    label->setText("first line\nsecond line");
    label->show();
}
void Bojack::setUpWindow(QWidget *widget) {
    QPalette palette = widget->palette();
    palette.setColor(QPalette::Window, Qt::black);
    widget->setAutoFillBackground(true);
    widget->setPalette(palette);

        // set font family and size.
    QFont font("Ubuntu Mono", 12, QFont::Thin, false);
    widget->setFont(font);
}

void Bojack::createMenuBar() {
    filemenu = new FileMenu;
    editmenu = new EditMenu;
    //aboutmenu = new AboutMenu;
    menuBar = new QMenuBar(nullptr);

    this->menuBar->addMenu(filemenu);
    this->menuBar->addMenu(editmenu);
    //this->menuBar->addMenu(aboutmenu);
}
