#ifndef COMMANDLINE_H
#define COMMANDLINE_H

#include <QStaticText>
#include <QLayout>


class CommandLine: public QObject
{
    Q_OBJECT
    public:
        //CommandLine();
        CommandLine(QWidget *);
        void drawLineText(QWidget *);
        QHBoxLayout *returnCmdLayout(QWidget *);
        QHBoxLayout *returnCmdLayout();
        QWidget* returnCmdWidget();
    private:
        QHBoxLayout *layout;
       // void drawLineText();
        //void drawTextLabel();
        //void drawTextBox();
        QWidget *parent;
    private slots:
        //void drawTextLabel(QWidget *widget);
        void drawTextLabel();
    signals:
        void enterPressed();
};

#endif // COMMANDLINE_H
