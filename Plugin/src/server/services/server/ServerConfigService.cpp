//
// Created by dubininvyu on 07.05.2022.
//

#include "ServerConfigService.h"

#include "Server.h"
#include "natives.h"
#include "InfoLog.h"

ServerConfigService::ServerConfigService(Server& server) : ServerService(server) {

}

ServerConfigService::~ServerConfigService() {

}

bool ServerConfigService::setupConfig() {
    api_server::native::EnableStuntBonusForAll(false); // disable stunt bonuses
    api_server::native::ShowNameTags(false); // disable name tags
    api_server::native::UsePlayerPedAnims(); // use standard player walking animation
    api_server::native::ShowPlayerMarkers(true); // enable player markers
    api_server::native::DisableInteriorEnterExits(); // disable interiors' enters and exists

    InfoLog(__FILE__, __LINE__, "Game mode configurations are set successfully").print();
    return true;
}