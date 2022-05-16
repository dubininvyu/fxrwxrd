//
// Created by dubininvyu on 13.05.2022.
//

#pragma once

#include "AdminCommand.h"

class GotoCommand : public AdminCommand {
private:
protected:
public:
    GotoCommand(Player& player, const string& params);

    virtual bool execute();
};
