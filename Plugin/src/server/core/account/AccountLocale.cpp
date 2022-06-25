//
// Created by dubininvyu on 12.05.2022.
//

#include "AccountLocale.h"

#include "Exception.h"
#include "LocaleRepository.h"

#include "logs.h"

using namespace std;

vector<AccountLocale*> AccountLocale::locales;

/*
 * constructors & destructors
 */
AccountLocale::AccountLocale(const Language language, const string& name, const bool enabled, const string& author) :
    language(language), name(name), enabled(enabled), author(author) {

    if (!enabled) {
        return;
    }

    LocaleRepository localeRepository(*this);
    size_t nTexts = localeRepository.loadTexts();

    if (!nTexts) {
        this->enabled = false;

        const string text = "Error loading texts for the active locale '" + name + "'";
        ErrorLog(__FILE__, __LINE__, text).print();

        return;
    }

    if (nTexts != (textMax - 2)) {
        const string text =
            "The number of loaded localization texts doesn't match the number of expected ones for the active locale '" + name + "'";
        WarningLog(__FILE__, __LINE__, text).print();

        return;
    }
}

AccountLocale::~AccountLocale() {

}

/*
 * methods
 * static
 */
void AccountLocale::addLocale(const Language language, const string& name, const bool enabled, const string& author) {
    AccountLocale* locale = new AccountLocale(language, name, enabled, author);
    locales.push_back(locale);
}

AccountLocale& AccountLocale::getLocale(const Language language) {
    AccountLocale& locale = *locales.at(language);
    return locale;
}

vector<AccountLocale*>& AccountLocale::getLocales() {
    return locales;
}

/*
 * methods
 * setters & getters
 */
bool AccountLocale::isEnabled() const {
    return enabled;
}

string AccountLocale::getName() const {
    return name;
}

void AccountLocale::setLanguage(const Language language) {
    this->language = language;
}

Language AccountLocale::getLanguage() const {
    return language;
}

void AccountLocale::setAuthor(const string& author) {
    this->author = author;
}

string AccountLocale::getAuthor() const {
    return author;
}

void AccountLocale::setText(const TextType type, const string& text) {
    texts.insert(pair<TextType, string>(type, text));
}

string AccountLocale::getText(const TextType type) const {
    if (!isEnabled()) {
        WarningLog(__FILE__, __LINE__, "Trying to get locale string, but the locale is disabled").print();
        return "TEXT_ERROR";
    }

    auto it = texts.find(type);

    if (it == texts.end()) {
        ErrorLog(__FILE__, __LINE__, "Trying to get locale string, but the string doesn't exist").print();
        return "TEXT_ERROR";
    }

    return it->second;
}

/*
 * methods
 * basic
 */

const TextType AccountLocale::getTextType(const string& value) {
    for (TextType i = TextType(textMin + 1); i != TextType::textMax; i = TextType(i + 1)) {
        if (textsTypes.at(i) != value) {
            continue;
        }

        return i;
    }

    return TEXT_NULL;
}

const string AccountLocale::getTextType(const TextType type) {
    auto it = textsTypes.find(type);

    if (it == textsTypes.end()) {
        const string message = "Error texts types processing: the textsTypes array doesn't include #" + to_string(type) + " value";
        ErrorLog(__FILE__, __LINE__, message).print();
        return "TEXT_NULL";
    }

    return it->second;
}

/*
 * operators
 */

string AccountLocale::operator()(const TextType type) const {
    return getText(type);
}