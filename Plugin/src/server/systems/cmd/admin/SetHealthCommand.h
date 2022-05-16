//
// Created by dubininvyu on 13.05.2022.
//

#pragma once

#include "AdminCommand.h"

class SetHealthCommand : public AdminCommand {
private:
protected:
    int playerID;
    float health;

    bool isHealth;
    bool isPlayerID;
public:
    SetHealthCommand(Player& player, const string& params);

    virtual bool execute();

    // =====
    bool fail();
    void split();
    bool prepare();

    bool setEveryoneHealth(const float health);
    bool setPlayerHealth(Player* player, const float health);
};
