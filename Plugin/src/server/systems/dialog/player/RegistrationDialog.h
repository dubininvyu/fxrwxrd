//
// Created by dubininvyu on 12.05.2022.
//

#pragma once

#include "Dialog.h"
#include "Player.h"
#include <string>

using namespace std;

class Player;

class RegistrationDialog : public Dialog {
private:
    enum Page {
        PAGE_PASSWORD = 0,
        PAGE_SEX,

        COUNT
    };
protected:
    Player::Sex sex;
    string password; // local player's password repository
public:
    RegistrationDialog(Player& player);
    ~RegistrationDialog();

    virtual bool format();

    virtual Result responseStart(const unsigned int response, unsigned int listItem, const string& inputText);
    virtual Result responseEnd(const unsigned int response, unsigned int listItem, const string& inputText);
};

