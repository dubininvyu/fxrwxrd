//
// Created by dubininvyu on 12.05.2022.
//

#include "RegistrationDialog.h"

#include "Player.h"
#include "AccountLocale.h"

#include "machines.h"

#include <string>
#include <vector>

RegistrationDialog::RegistrationDialog(Player* player, Page page) : Dialog(player), page(page) {
    pageCount = Page::COUNT;
}

RegistrationDialog::~RegistrationDialog() {

}

bool RegistrationDialog::format() {
    this->dialog = DIALOG_REGISTRATION;

    const AccountLocale& locale = *player->getAccount()->getLocale();

    switch (page) {
        case PAGE_LOCALE: {
            this->style = STYLE_TABLIST_HEADERS;
            this->caption = locale(TEXT_DLG_REG_LOCALE_CAPTION);
            this->button[BUTTON_LEFT] = locale(TEXT_DONE);
            this->button[BUTTON_RIGHT] = locale(TEXT_NULL);

            string text;

            vector<AccountLocale*>& locales = AccountLocale::getLocales();
            size_t nLocales = locales.size();

            AccountLocale* locale = player->getAccount()->getLocale();

            string name = locale->getText(TEXT_LOCALE_CAPTION_NAME);
            string enabled = locale->getText(TEXT_LOCALE_CAPTION_ENABLED);
            string author = locale->getText(TEXT_LOCALE_CAPTION_AUTHOR);

            static string enables[] = {
                "{FF0000}" + locale->getText(TEXT_DISABLED) + "{FFFFFF}",
                "{00FF00}" + locale->getText(TEXT_ENABLED) + "{FFFFFF}"
            };

            text = name + "\t\t" + enabled + "\t\t" + author + "\n";

            for (size_t i = 0; i < nLocales; i++) {
                text += locales.at(i)->getName() + "\t\t";
                text += enables[locales.at(i)->isEnabled()] + "\t\t";
                text += locales.at(i)->getAuthor();

                text += "\n";
            }

            this->info = text;

            break;
        }

        case PAGE_PASSWORD: {
            this->style = STYLE_PASSWORD;
            this->caption = locale(TEXT_DLG_REG_PASS_CAPTION);
            this->info = locale(TEXT_DLG_REG_PASS_INFO);
            this->button[BUTTON_LEFT] = locale(TEXT_DONE);
            this->button[BUTTON_RIGHT] = locale(TEXT_PREV);
            break;
        }

        case PAGE_SEX: {
            this->style = STYLE_MSGBOX;
            this->caption = locale(TEXT_DLG_REG_SEX_CAPTION);
            this->info = locale(TEXT_DLG_REG_SEX_INFO);
            this->button[BUTTON_LEFT] = locale(TEXT_SEX_MAN);
            this->button[BUTTON_RIGHT] = locale(TEXT_SEX_WOMAN);
            break;
        }

        case PAGE_AGE: {
            this->style = STYLE_LIST;
            this->caption = locale(TEXT_DLG_REG_AGE_CAPTION);
            this->button[BUTTON_LEFT] = locale(TEXT_DONE);
            this->button[BUTTON_RIGHT] = locale(TEXT_PREV);

            string text = "";

            if (player->getSex()->isMale()) {
                text += locale(TEXT_AGE_MALE_YOUNG) + "\n";
                text += locale(TEXT_AGE_MALE_ADULT) + "\n";
                text += locale(TEXT_AGE_MALE_ELDERLY) + "\n";
            }
            else {
                text += locale(TEXT_AGE_FEMALE_YOUNG) + "\n";
                text += locale(TEXT_AGE_FEMALE_ADULT) + "\n";
                text += locale(TEXT_AGE_FEMALE_ELDERLY) + "\n";
            }

            this->info = text;

            break;
        }
    }

    return Dialog::format();
}

Dialog::Result RegistrationDialog::responseStart(const unsigned int response, unsigned int listItem, const string& inputText) {
    switch (page) {
        case PAGE_LOCALE: {
            if (response == BUTTON_RIGHT) {
                return RESULT_REPEAT;
            }

            break;
        }

        case PAGE_PASSWORD: {
            if (response == BUTTON_RIGHT) {
                page = PAGE_LOCALE;
                return RESULT_REPEAT;
            }

            if (!AccountPassword::isValid(inputText)) {
                return RESULT_REPEAT;
            }

            break;
        }

        case PAGE_SEX: {
            break;
        }

        case PAGE_AGE: {
            break;
        }
    }

    return RESULT_CLOSE;
}

Dialog::Result RegistrationDialog::responseEnd(const unsigned int response, unsigned int listItem, const string& inputText) {
    switch (page) {
        case PAGE_LOCALE: {

            Language language = Language(listItem);

            AccountLocale& locale = AccountLocale::getLocale(language);
            if (!locale.isEnabled()) {
                return RESULT_REPEAT;
            }

            player->getAccount()->setLocale(language);
            player->getStateMachineManager()->getPlayerRegistration()->process_event(Next());
            break;
        }

        case PAGE_PASSWORD: {
            player->getAccount()->getPassword()->setPassword(inputText, false);
            player->getStateMachineManager()->getPlayerRegistration()->process_event(Next());
            break;
        }

        case PAGE_SEX: {
            player->getSex()->setSex(PersonSex::Sex(response));
            player->getStateMachineManager()->getPlayerRegistration()->process_event(Next());
            break;
        }

        case PAGE_AGE: {
            player->getAge()->setAge(PersonAge::Age(listItem));
            player->getStateMachineManager()->getPlayerRegistration()->process_event(Next());
            break;
        }
    }

    return RESULT_CLOSE;
}