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

    const AccountLocale& locale = *player->getAccount()->getLocale();

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
        case PAGE_PASSWORD:
        case PAGE_WRONG_PASSWORD: {
            if (response == BUTTON_RIGHT) {
                return RESULT_REPEAT;
            }

            if (!AccountPassword::isValid(inputText)) {
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
        case PAGE_PASSWORD:
        case PAGE_WRONG_PASSWORD: {
            PlayerAuthenticationService authenticationService(player);
            bool isValid = authenticationService.isRegisteredByPassword(inputText);

            if (!isValid) {
                wrongAttemptsCount++;

                if (wrongAttemptsCount == MAX_ATTEMPTS_ENTER_PASSWORD) {
                    PlayerAuthorizationStateMachine* stateMachine = player->getStateMachineManager()->getPlayerAuthorization();
                    stateMachine->process_event(Error(Error::ERROR_AUTHORIZATION_PASSWORD_ENTERING));
                    return RESULT_CLOSE;
                }

                return RESULT_REPEAT;
            }

            player->getAccount()->getPassword()->setPassword(inputText, false);
            player->getStateMachineManager()->getPlayerAuthorization()->process_event(Next());

            break;
        }
    }

    return RESULT_CLOSE;
}