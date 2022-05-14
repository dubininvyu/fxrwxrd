//
// Created by dubininvyu on 10.05.2022.
//

#include "PlayerDialog.h"

PlayerDialog::PlayerDialog(Player* player) : player(player) {

}

bool PlayerDialog::showDialog(Dialog* dialog) {
    dialogs.insert(dialogs.end(), dialog);
    return dialog->show();
}

bool PlayerDialog::removeDialog(Dialog* dialog) {
    dialogs.remove(dialog);
    delete dialog;

    return true;
}

Dialog* PlayerDialog::getLastDialog() {
    if (dialogs.empty()) {
        return nullptr;
    }

    return dialogs.back();
}

void PlayerDialog::setDialog(Dialog* dialog) {
    this->dialog = dialog;
}

Dialog* PlayerDialog::getDialog() {
    return this->dialog;
}