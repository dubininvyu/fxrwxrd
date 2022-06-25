//
// Created by dubininvyu on 22.06.2022.
//


#pragma once

#include "AdminCommand.h"

class CreateVehicleCommand : public AdminCommand {
private:
protected:
public:
    CreateVehicleCommand(Player* player, const string& params);

    virtual bool execute();
};
