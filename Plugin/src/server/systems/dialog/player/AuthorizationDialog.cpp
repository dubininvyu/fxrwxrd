//
// Created by dubininvyu on 12.05.2022.
//

#include "natives.h"

#include "Player.h"
#include "dialogs.h"
#include "services.h"
#include "repositories.h"

AuthorizationDialog::AuthorizationDialog(Player& player) : Dialog(player) {
    pageCount = Page::COUNT;

    wrongAttemptsCount = 0;
}

AuthorizationDialog::~AuthorizationDialog() {

}

bool AuthorizationDialog::format() {
    this->dialog = DIALOG_AUTHORIZATION;

    PlayerLocale& locale = *player.getLocale();

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
    if (page == PAGE_PASSWORD) {
        if (response == BUTTON_RIGHT) {
            return RESULT_REPEAT;
        }

        if (!PlayerPassword::isValid(inputText)) {
            wrongAttemptsCount++;
            return RESULT_REPEAT;
        }

        return RESULT_NEXT_PAGE;
    }

    if (page == PAGE_WRONG_PASSWORD) {
        if (response == BUTTON_RIGHT) {
            return RESULT_REPEAT;
        }

        if (!PlayerPassword::isValid(inputText)) {
            wrongAttemptsCount++;
            return RESULT_REPEAT;
        }

        return RESULT_CLOSE;
    }

    return RESULT_NEXT_PAGE;
}

Dialog::Result AuthorizationDialog::responseEnd(const unsigned int response, unsigned int listItem, const string& inputText) {
    PlayerAuthorizationService authorizationService(player);
    bool result = authorizationService.endAuthorization();

    if (result) { // it's okay
        return RESULT_CLOSE;
    }

    wrongAttemptsCount++;

    if (wrongAttemptsCount == MAX_ATTEMPTS_ENTER_PASSWORD) {
        player.sendMessage(player.getLocale()->getText(TEXT_ERROR));
        return RESULT_CLOSE;
    }

    return RESULT_REPEAT;
}