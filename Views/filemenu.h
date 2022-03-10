#ifndef FILEMENU_H
#define FILEMENU_H

#include <QMenu>
#include <QAction>

class MainWindow;

class FileMenu: public QMenu {
    Q_OBJECT

    public:
        FileMenu();
        ~FileMenu();

    private:
       // MainWindow *duplicate = new MainWindow();
        QAction *newTab;
        QAction *newWindow;
        QAction *exitWindow;

        void createMenuBar(FileMenu *);
        void createFileActions();

    private slots:
        void exitBojack();

};

#endif
