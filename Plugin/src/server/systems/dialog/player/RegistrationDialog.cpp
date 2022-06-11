//
// Created by dubininvyu on 12.05.2022.
//

#include "RegistrationDialog.h"

#include "Player.h"
#include "dialogs.h"
#include "services.h"
#include "repositories.h"

#include <string>

RegistrationDialog::RegistrationDialog(Player* player, Page page) : Dialog(player), page(page) {
    pageCount = Page::COUNT;
}

RegistrationDialog::~RegistrationDialog() {

}

bool RegistrationDialog::format() {
    this->dialog = DIALOG_REGISTRATION;

    PlayerLocale& locale = *player->getLocale();

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
    switch (page) {
        case PAGE_PASSWORD: {
            if (response == BUTTON_RIGHT) {
                return RESULT_REPEAT;
            }

            if (!PlayerPassword::isValid(inputText)) {
                return RESULT_REPEAT;
            }

            break;
        }

        case PAGE_SEX: {
            break;
        }
    }

    return RESULT_CLOSE;
}

Dialog::Result RegistrationDialog::responseEnd(const unsigned int response, unsigned int listItem, const string& inputText) {
    switch (page) {
        case PAGE_PASSWORD: {
            player->getPassword()->setPassword(inputText, false);
            player->getStateMachineManager()->getPlayerAuthentication()->process_event(player_authentication_sm::Next());
            break;
        }

        case PAGE_SEX: {
            player->getSex()->setSex(PersonSex::Sex(response));
            player->getStateMachineManager()->getPlayerAuthentication()->process_event(player_authentication_sm::Next());
            break;
        }
    }

    return RESULT_CLOSE;
}