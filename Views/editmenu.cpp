#include "editmenu.h"

EditMenu::EditMenu() {
    this->setTitle(tr("&Edit"));
    this->createActions();
    this->createMenuOption(this);
}
EditMenu::~EditMenu() {
    delete cutOption;
    delete copyOption;
    delete pasteOption;
}

void EditMenu::createMenuOption(EditMenu *editOption) {
    editOption->addAction(cutOption);
    editOption->addAction(copyOption);
    editOption->addAction(pasteOption);
}

void EditMenu::createActions() {
    cutOption = new QAction(tr("&Cut"), this);
    cutOption->setShortcut(tr("Ctrl+X"));
    cutOption->setStatusTip(tr("Cut"));

    copyOption = new QAction(tr("&Copy"), this);
    copyOption->setShortcut(tr("Ctrl+C"));
    copyOption->setStatusTip(tr("Copy"));

    pasteOption = new QAction(tr("&Paste"));
    pasteOption->setShortcut(tr("Ctrl+P"));
    pasteOption->setStatusTip(tr("Paste"));
}
