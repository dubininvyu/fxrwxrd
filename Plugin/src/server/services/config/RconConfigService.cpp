//
// Created by dubininvyu on 07.05.2022.
//

#include "RconConfigService.h"

#include "Server.h"
#include "natives.h"
#include "InfoLog.h"
#include "RconConfigRepository.h"

typedef RconConfig::Param Param;

RconConfigService::RconConfigService(Server& server) : ServerService(server) {

}

RconConfigService::~RconConfigService() {

}

bool RconConfigService::setupConfig() {
    RconConfigRepository rconConfigRepository(Repository::MODE_READ_ALL);

    RconConfig* rconConfig = Server::getInstance().getRconConfig();

    for (Param i = Param(Param::PARAM_RCON_START + 1); i != Param::PARAM_RCON_END; i = Param(i + 1)) {
        Param configParam = static_cast<Param>(i);
        string value = rconConfigRepository.getParam(configParam);
        rconConfig->setParam(configParam, value);
    }

    InfoLog(__FILE__, __LINE__, "Server configurations are set successfully").print();
    return true;
}