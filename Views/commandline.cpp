#include <QPainter>
#include <QWidget>
#include <QLabel>
#include "commandline.h"

CommandLine::CommandLine()
{

}

void CommandLine::drawLineText(QWidget *widget) {
    QPainter *painter = new QPainter(widget);
    //QPainter::drawStaticText(QPoint(0, 0), QStaticText("->"));
    //painter->drawStaticText(QPoint(0, 0), QStaticText("->"));
    QLabel *label = new QLabel(widget);
    label->setText(" ->");
    label->show();
}
