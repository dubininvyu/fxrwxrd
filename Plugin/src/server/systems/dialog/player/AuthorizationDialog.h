//
// Created by dubininvyu on 12.05.2022.
//

#pragma once

#include "Dialog.h"
#include "Player.h"
#include <string>

using namespace std;

class Player;

class AuthorizationDialog : public Dialog {
public:
    enum Page {
        PAGE_PASSWORD = 0,
        COUNT,

        /* service dialogs */
        PAGE_WRONG_PASSWORD,
    };
private:
    const unsigned int MAX_ATTEMPTS_ENTER_PASSWORD = 3;

protected:
    unsigned int wrongAttemptsCount;
    Page page;

public:
    AuthorizationDialog(Player* player, Page page);
    ~AuthorizationDialog();

    virtual bool format();

    virtual Result responseStart(const unsigned int response, unsigned int listItem, const string& inputText);
    virtual Result responseEnd(const unsigned int response, unsigned int listItem, const string& inputText);
};

