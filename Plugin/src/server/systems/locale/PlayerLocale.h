//
// Created by dubininvyu on 12.05.2022.
//

#pragma once

#include "texts.h"
#include "languages.h"

#include <map>
#include <string>

using namespace std;

class PlayerLocale {
private:
protected:
    bool enabled;
    string name;
    string author;

    Language language;
    map<Text, string> texts;

    PlayerLocale(Language language);
    ~PlayerLocale();
public:
    static PlayerLocale& getLocale(Language language);

    bool isEnabled() const;
    string getName() const;

    void setLanguage(Language language);
    Language getLanguage() const;

    void setText(Text type, string text);
    string getText(Text type) const;

    string operator()(const Text type);
};

