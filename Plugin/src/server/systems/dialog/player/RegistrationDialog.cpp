//
// Created by dubininvyu on 12.05.2022.
//

#include "RegistrationDialog.h"

#include "dialogs.h"
#include "services.h"
#include "repositories.h"

#include <string>

RegistrationDialog::RegistrationDialog(Player& player) : Dialog(player) {
    pageCount = Page::COUNT;
}

RegistrationDialog::~RegistrationDialog() {

}

bool RegistrationDialog::format() {
    this->dialog = DIALOG_REGISTRATION;

    PlayerLocale& locale = *player.getLocale();

    switch (page) {
        case PAGE_PASSWORD:
            this->style = STYLE_PASSWORD;
            this->caption = locale(TEXT_DLG_REG_PASS_CAPTION);
            this->info = locale(TEXT_DLG_REG_PASS_INFO);
            this->button[BUTTON_LEFT] = locale(TEXT_DONE);
            this->button[BUTTON_RIGHT] = locale(TEXT_NULL);
            break;

        case PAGE_SEX:
            this->style = STYLE_MSGBOX;
            this->caption = locale(TEXT_DLG_REG_SEX_CAPTION);
            this->info = locale(TEXT_DLG_REG_SEX_INFO);
            this->button[BUTTON_LEFT] = locale(TEXT_SEX_MAN);
            this->button[BUTTON_RIGHT] = locale(TEXT_SEX_WOMAN);
            break;
    }

    return Dialog::format();
}

Dialog::Result RegistrationDialog::responseStart(const unsigned int response, unsigned int listItem, const string& inputText) {
    Result result = RESULT_NEXT_PAGE;

    if (page == PAGE_PASSWORD) {
        if (response == BUTTON_RIGHT) {
            return RESULT_REPEAT;
        }

        if (inputText.length() < 6) {
            return RESULT_REPEAT;
        }

        password = inputText;
    }

    if (page == PAGE_SEX) {
        sex = Player::Sex(response);
    }

    return result;
}

Dialog::Result RegistrationDialog::responseEnd(const unsigned int response, unsigned int listItem, const string& inputText) {
    PlayerRegistrationService registrationService(player);
    bool success = registrationService.finishRegistration(password, sex);

    if (success) {
        PlayerAuthenticationService authenticationService(player);
        authenticationService.startAuthentication();
        return RESULT_CLOSE;
    }

    // the authorization process failed
    player.sendMessage(player.getLocale()->getText(TEXT_ERROR));

    return RESULT_CLOSE;
}