//
// Created by dubininvyu on 07.05.2022.
//

#pragma once

#include "ServerService.h"
#include "Server.h"

class RconConfigService : public ServerService {
private:
protected:
public:
    RconConfigService(Server& server);
    virtual ~RconConfigService();

    bool setupConfig();
};

