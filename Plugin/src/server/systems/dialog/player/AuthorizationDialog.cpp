//
// Created by dubininvyu on 12.05.2022.
//

#include "natives.h"

#include "Player.h"
#include "dialogs.h"
#include "services.h"
#include "repositories.h"

AuthorizationDialog::AuthorizationDialog(Player* player, Page page) : Dialog(player), page(page) {
    pageCount = Page::COUNT;

    wrongAttemptsCount = 0;
}

AuthorizationDialog::~AuthorizationDialog() {

}

bool AuthorizationDialog::format() {
    this->dialog = DIALOG_AUTHORIZATION;

    PlayerLocale& locale = *player->getLocale();

    switch (page) {
        case PAGE_PASSWORD:
            this->style = STYLE_PASSWORD;
            this->caption = locale(TEXT_DLG_AUTH_PASS_CAPTION);
            this->info = locale(TEXT_DLG_AUTH_PASS_INFO);
            this->button[BUTTON_LEFT] = locale(TEXT_DONE);
            this->button[BUTTON_RIGHT] = locale(TEXT_NULL);
            break;

        case PAGE_WRONG_PASSWORD:
            this->style = STYLE_PASSWORD;
            this->caption = locale(TEXT_DLG_AUTH_PASS_WRONG_CAPTION) + to_string(wrongAttemptsCount);
            this->info = locale(TEXT_DLG_AUTH_PASS_WRONG_INFO);
            this->button[BUTTON_LEFT] = locale(TEXT_DONE);
            this->button[BUTTON_RIGHT] = locale(TEXT_NULL);
            break;
    }

    return Dialog::format();
}

Dialog::Result AuthorizationDialog::responseStart(const unsigned int response, unsigned int listItem, const string& inputText) {
    switch (page) {
        case PAGE_PASSWORD: {
            if (response == BUTTON_RIGHT) {
                return RESULT_REPEAT;
            }

            if (!PlayerPassword::isValid(inputText)) {
                wrongAttemptsCount++;
                return RESULT_REPEAT;
            }

            break;
        }

        case PAGE_WRONG_PASSWORD: {
            if (response == BUTTON_RIGHT) {
                return RESULT_REPEAT;
            }

            if (!PlayerPassword::isValid(inputText)) {
                wrongAttemptsCount++;
                return RESULT_REPEAT;
            }

            break;
        }
    }

    return RESULT_CLOSE;
}

Dialog::Result AuthorizationDialog::responseEnd(const unsigned int response, unsigned int listItem, const string& inputText) {
    switch (page) {
        case PAGE_PASSWORD: {
            PlayerAuthenticationService authenticationService(player);
            unsigned int accountID = authenticationService.getUIDByPassword(inputText);

            if (!accountID) {
                wrongAttemptsCount++;

                if (wrongAttemptsCount == MAX_ATTEMPTS_ENTER_PASSWORD) {
                    player->sendMessage(player->getLocale()->getText(TEXT_ERROR));
                    return RESULT_CLOSE;
                }

                return RESULT_REPEAT;
            }

            player->setUID(accountID);
            player->getPassword()->setPassword(inputText, false);
            player->getStateMachineManager()->getPlayerAuthentication()->process_event(player_authentication_sm::Next());

            break;
        }
    }

    return RESULT_CLOSE;
}