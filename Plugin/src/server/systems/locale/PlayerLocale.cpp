//
// Created by dubininvyu on 12.05.2022.
//

#include "PlayerLocale.h"

#include "Exception.h"
#include "WarningLog.h"
#include "LocaleRepository.h"

PlayerLocale::PlayerLocale(Language language) : language(language) {
    LocaleRepository localeRepository(*this);
    enabled = localeRepository.init();
}

PlayerLocale::~PlayerLocale() {

}

void PlayerLocale::setText(Text type, string text) {
    texts.insert(pair<Text, string>(type, text));
}

PlayerLocale& PlayerLocale::getLocale(Language language) {
    static PlayerLocale locales[LANGUAGE_COUNT] {
            PlayerLocale(LANGUAGE_RU),
            PlayerLocale(LANGUAGE_EN),
    };

    if (!locales[language].isEnabled()) { // selected language is disabled
        return locales[LANGUAGE_EN];
    }

    return locales[language];
}

bool PlayerLocale::isEnabled() const {
    return enabled;
}

string PlayerLocale::getName() const {
    return name;
}

void PlayerLocale::setLanguage(Language language) {
    this->language = language;
}

Language PlayerLocale::getLanguage() const {
    return language;
}

string PlayerLocale::getText(Text type) const {
    if (!isEnabled()) {
        WarningLog(__FILE__, __LINE__, "Trying to get locale string, but the locale is disabled").print();
        return "";
    }

    return texts.at(type);
}

string PlayerLocale::operator()(const Text type) {
    return getText(type);
}