//
// Created by dubininvyu on 03.05.2022.
//


#pragma once

#include "ServerEventHandler.h"

class ServerGameModeExitHandler : public ServerEventHandler {
private:
protected:
public:
    ServerGameModeExitHandler(Server& server);
    virtual ~ServerGameModeExitHandler();

    virtual bool execute();
};

