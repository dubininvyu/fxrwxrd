//
// Created by dubininvyu on 07.05.2022.
//

#pragma once

#include "ServerService.h"
#include "Server.h"

class ServerConfigService : public ServerService {
private:
protected:
public:
    ServerConfigService(Server& server);
    virtual ~ServerConfigService();

    bool setupConfig();
};

