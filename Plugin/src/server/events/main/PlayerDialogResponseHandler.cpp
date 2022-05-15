//
// Created by dubininvyu on 03.05.2022.
//

#include "PlayerDialogResponseHandler.h"

#include "Player.h"
#include "Dialog.h"

PlayerDialogResponseHandler::PlayerDialogResponseHandler(Player& player, const int dialogID, const int response, const int item, const string& text) :
        PlayerEventHandler(player), dialogID(dialogID), response(response), item(item), text(text) {
}

PlayerDialogResponseHandler::~PlayerDialogResponseHandler() {

}

bool PlayerDialogResponseHandler::execute() {
    Dialog* currentDialog = player.getDialog()->getLastDialog();

    if (!currentDialog) {
        return true;
    }

    Dialog::Result result = currentDialog->response(!response, item, text);

    if (result == Dialog::RESULT_REPEAT) {
        currentDialog->show();
        return true;
    }

    if (result == Dialog::RESULT_CLOSE) {
        player.getDialog()->removeDialog(currentDialog);

        if (player.getDialog()->getDialog() != currentDialog) {
            return true;
        }

        currentDialog = player.getDialog()->getLastDialog();
        if (currentDialog) {
            currentDialog->show();
        }

        player.getDialog()->setDialog(currentDialog);
        return true;
    }

    return true;
}