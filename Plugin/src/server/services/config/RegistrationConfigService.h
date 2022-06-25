//
// Created by dubininvyu on 07.05.2022.
//

#pragma once

#include "ServerService.h"
#include "Server.h"

class RegistrationConfigService : public ServerService {
private:
protected:
public:
    RegistrationConfigService(Server& server);
    virtual ~RegistrationConfigService();

    bool setupConfig();
};

