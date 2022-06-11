//
// Created by dubininvyu on 03.05.2022.
//

#pragma once

#include "ServerEventHandler.h"

class ServerGameModeInitHandler : public ServerEventHandler {
private:
protected:
public:
    ServerGameModeInitHandler(Server& server);
    virtual ~ServerGameModeInitHandler();

    virtual bool execute();
};

