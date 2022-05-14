//
// Created by dubininvyu on 07.05.2022.
//

#include "ServerConfigService.h"

#include "Server.h"
#include "natives.h"
#include "InfoLog.h"
#include "ServerRconConfigRepository.h"

ServerConfigService::ServerConfigService(Server& server) : ServerService(server) {

}

ServerConfigService::~ServerConfigService() {

}

bool ServerConfigService::setupRconConfig() {
    ServerRconConfigRepository rconConfigRepository(Repository::MODE_READ_ALL);

    for (size_t i = Server::PARAM_RCON_START+1; i < Server::PARAM_RCON_END; i++) {
        Server::CONFIG_PARAM configParam = static_cast<Server::CONFIG_PARAM>(i);
        string value = rconConfigRepository.getParam(configParam);
        Server::getInstance().setParam(configParam, value);
    }

    InfoLog(__FILE__, __LINE__, "Server configurations are set successfully").print();
    return true;
}

bool ServerConfigService::setupGameModeConfig() {
    api_server::native::EnableStuntBonusForAll(false); // disable stunt bonuses
    api_server::native::ShowNameTags(false); // disable name tags
    api_server::native::UsePlayerPedAnims(); // use standard player walking animation
    api_server::native::ShowPlayerMarkers(true); // enable player markers
    api_server::native::DisableInteriorEnterExits(); // disable interiors' enters and exists

    InfoLog(__FILE__, __LINE__, "Game mode configurations are set successfully").print();
    return true;
}