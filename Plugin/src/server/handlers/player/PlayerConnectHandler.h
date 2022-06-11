//
// Created by dubininvyu on 03.05.2022.
//

#pragma once

#include "PlayerEventHandler.h"

class PlayerConnectHandler : public PlayerEventHandler {
private:
protected:
public:
    PlayerConnectHandler(Player* player);
    virtual ~PlayerConnectHandler();

    virtual bool execute();
};