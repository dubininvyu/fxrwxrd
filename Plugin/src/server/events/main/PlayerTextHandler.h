//
// Created by dubininvyu on 03.02.2022.
//


#pragma once

#include "PlayerEventHandler.h"

class PlayerTextHandler : public PlayerEventHandler {
private:
protected:
    string text;
public:
    PlayerTextHandler(Player& player, const string& text);
    virtual ~PlayerTextHandler();

    virtual bool execute();

    bool executeLocalChat();
    bool executeAdminChat();
    bool executeGlobalChat();
};