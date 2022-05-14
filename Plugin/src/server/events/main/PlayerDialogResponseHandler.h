//
// Created by dubininvyu on 03.05.2022.
//


#pragma once

#include "PlayerEventHandler.h"

class PlayerDialogResponseHandler : public PlayerEventHandler {
private:
protected:
    int dialogID;
    int response;
    int item;
    string text;
public:
    PlayerDialogResponseHandler(Player& player, const int dialogID, const int response, const int item, const string& text);
    virtual ~PlayerDialogResponseHandler();

    virtual bool execute();
};