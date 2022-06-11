//
// Created by dubininvyu on 12.05.2022.
//

#pragma once

#include "Dialog.h"
#include "Player.h"
#include "PersonSex.h"

#include <string>

using namespace std;

class Player;

class RegistrationDialog : public Dialog {
public:
    enum Page {
        PAGE_PASSWORD = 0,
        PAGE_SEX,

        COUNT
    };
protected:
    Page page;
public:
    RegistrationDialog(Player* player, Page page);
    ~RegistrationDialog();

    virtual bool format();

    virtual Result responseStart(const unsigned int response, unsigned int listItem, const string& inputText);
    virtual Result responseEnd(const unsigned int response, unsigned int listItem, const string& inputText);
};

