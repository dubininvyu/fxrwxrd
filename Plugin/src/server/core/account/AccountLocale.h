//
// Created by dubininvyu on 12.05.2022.
//

#pragma once

#include "texts.h"
#include "languages.h"

#include <map>
#include <string>
#include <vector>

using namespace std;

typedef size_t locale_t;

class AccountLocale {
private:
protected:
    bool enabled;
    string name;
    string author;

    Language language;

    static vector<AccountLocale*> locales;

    typedef map<TextType, string> texts_t;
    texts_t texts;

    typedef map<TextType, string> texts_types_t;
    static const texts_types_t textsTypes;

    AccountLocale(const Language language, const string& name, const bool enabled, const string& author);
    ~AccountLocale();
public:
    /*
     * methods
     * static
     */
    static void addLocale(const Language language, const string& name, const bool enabled, const string& author);
    static AccountLocale& getLocale(const Language language);
    static vector<AccountLocale*>& getLocales();

    /*
     * methods
     * setters & getters
     */
    bool isEnabled() const;
    string getName() const;

    void setLanguage(const Language language);
    Language getLanguage() const;

    void setAuthor(const string& author);
    string getAuthor() const;

    void setText(const TextType type, const string& text);
    string getText(const TextType type) const;

    /*
     * methods
     * basic
     */
    static const TextType getTextType(const string& value);
    static const string getTextType(const TextType type);

    /*
     * operators
     */
    string operator()(const TextType type) const;
};

