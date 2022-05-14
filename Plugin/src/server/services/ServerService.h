//
// Created by dubininvyu on 07.05.2022.
//

#pragma once

#include "Service.h"
#include "Server.h"

class ServerService : public Service {
private:
protected:
    Server& server;

    ServerService(Server& server);
public:
    virtual ~ServerService() = 0;
};

