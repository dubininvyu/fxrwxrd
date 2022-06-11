//
// Created by dubininvyu on 10.05.2022.
//

#include "DialogManager.h"

DialogManager::DialogManager(Player* player) : player(player) {

}

bool DialogManager::showDialog(Dialog* dialog) {
    dialogs.insert(dialogs.end(), dialog);
    return dialog->show();
}

bool DialogManager::removeDialog(Dialog* dialog) {
    dialogs.remove(dialog);
    delete dialog;

    return true;
}

Dialog* DialogManager::getLastDialog() {
    if (dialogs.empty()) {
        return nullptr;
    }

    return dialogs.back();
}

void DialogManager::setDialog(Dialog* dialog) {
    this->dialog = dialog;
}

Dialog* DialogManager::getDialog() {
    return this->dialog;
}