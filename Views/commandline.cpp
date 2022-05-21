#include <QPainter>
#include <QWidget>
#include <QLabel>
#include <QLineEdit>
#include "bojack.h"
#include "commandline.h"
#include <iostream>

CommandLine::CommandLine(QWidget *widget)
{
    parent = new QWidget();
}

void CommandLine::drawLineText(QWidget *widget) {
    QWidget *cmd = new QWidget;
    QLabel *label = new QLabel(cmd);
    label->setText(" ->");

    QHBoxLayout *layout = new QHBoxLayout(cmd);
    layout->addWidget(label);
    cmd->setLayout(layout);
    cmd->show();
}

QHBoxLayout* CommandLine::returnCmdLayout(QWidget *widget) {
    QLabel *label = new QLabel(widget);
    label->setText("->");
    QLineEdit *line = new QLineEdit(widget);
    line->setCursorMoveStyle(Qt::LogicalMoveStyle);
    line->setEchoMode(QLineEdit::Normal);
    line->setFrame(false);
    connect(line, &QLineEdit::returnPressed, this, &CommandLine::drawTextLabel);
    QHBoxLayout *layout = new QHBoxLayout(widget);
    layout->addWidget(label);
    layout->addWidget(line);
    //widget->show();
    return layout;
}

QHBoxLayout* CommandLine::returnCmdLayout() {
    QLabel *label = new QLabel(parent);
    label->setText("->");
    QLineEdit *line = new QLineEdit(parent);
    line->setCursorMoveStyle(Qt::LogicalMoveStyle);
    line->setEchoMode(QLineEdit::Normal);
    line->setFrame(false);
    connect(line, &QLineEdit::returnPressed, this, &CommandLine::drawTextLabel);
    QHBoxLayout *layout = new QHBoxLayout(parent);
    layout->addWidget(label);
    layout->addWidget(line);
    //widget->show();
    return layout;
}

QWidget* CommandLine::returnCmdWidget() {
    QWidget *parent = new QWidget();
    QLabel *label = new QLabel(parent);
    label->setText("->");
    QLineEdit *line = new QLineEdit(parent);
    line->setCursorMoveStyle(Qt::LogicalMoveStyle);
    line->setEchoMode(QLineEdit::Normal);
    line->setFrame(false);
    connect(line, &QLineEdit::returnPressed, this, &CommandLine::drawTextLabel);
    //QHBoxLayout *layout = new QHBoxLayout(parent);
    //layout->addWidget(label);
    //layout->addWidget(line);
    //widget->show();
    //parent->show();
    return parent;
}
void CommandLine::drawTextLabel() {
    std::cout << "I'm doing this" << std::endl;
    emit enterPressed();
}
