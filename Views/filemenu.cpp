#include "filemenu.h"

FileMenu::FileMenu(){
    this->setTitle(tr("&File Menu"));
    this->createFileActions();
    this->createMenuBar(this);
}

void FileMenu::createMenuBar(FileMenu *fileOption) {
    fileOption->addAction(newWindow);
    fileOption->addAction(newTab);
    fileOption->addAction(exitWindow);
}

void FileMenu::createFileActions() {
    newTab = new QAction(tr("&New Tab"), this);
    newTab->setShortcut(tr("Ctrl+Shift+N"));
    newTab->setStatusTip(tr("Create a new Bojack tab"));
    /* connect(newFolder, &QAction::triggered, this, &FileMenu::openNewFolder);
 */
    newWindow = new QAction(tr("&New Window"), this);
    newWindow->setShortcut(tr("Ctrl+N"));
    newWindow->setStatusTip("Open a new MTX window");
    //connect(newWindow,&QAction::triggered, this, &FileMenu::openNewWindow);

    exitWindow = new QAction(tr("&Exit"), this);
    exitWindow->setShortcut(tr("Shift+C"));
    exitWindow->setStatusTip("Exit MTX");
    connect(exitWindow, &QAction::triggered, this, &FileMenu::exitBojack);
}


void FileMenu::exitBojack() {
    exit(EXIT_SUCCESS);
}

FileMenu::~FileMenu() {
    delete newTab;
    delete newWindow;
    delete exitWindow;
}

