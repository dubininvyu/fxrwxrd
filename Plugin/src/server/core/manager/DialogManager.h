//
// Created by dubininvyu on 10.05.2022.
//

#pragma once

#include "Dialog.h"

#include <list>

using namespace std;

class Player;

class DialogManager {
public:
private:
protected:
    Player* player;

    Dialog* dialog; // current dialog
    list<Dialog*> dialogs;
public:
    DialogManager(Player* player);

    bool showDialog(Dialog* dialog);
    bool removeDialog(Dialog* dialog);
    Dialog* getLastDialog();

    void setDialog(Dialog* dialog);
    Dialog* getDialog();
};