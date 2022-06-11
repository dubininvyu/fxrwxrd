//
// Created by dubininvyu on 03.05.2022.
//

#pragma once

#include "EventHandler.h"
#include "Server.h"

class ServerEventHandler : public EventHandler {
private:
protected:
    Server& server;

    ServerEventHandler(Server& server);
public:
    virtual ~ServerEventHandler() = 0;
};

