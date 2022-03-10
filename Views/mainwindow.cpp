#include "mainwindow.h"
#include "ui_mainwindow.h"

MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
{
    ui->setupUi(this);
    setUp(ui->centralwidget);
}

MainWindow::~MainWindow()
{
    delete ui;
}

void MainWindow::setUp(QWidget *widget) {
    // set black background colour;
    QPalette palette = widget->palette();
    palette.setColor(QPalette::Window, Qt::black);
    widget->setAutoFillBackground(true);
    widget->setPalette(palette);

    // set font family and size.
    QFont font("Ubuntu Mono", 10, QFont::Thin, false);
    widget->setFont(font);
}
