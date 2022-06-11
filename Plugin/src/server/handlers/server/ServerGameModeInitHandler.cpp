//
// Created by dubininvyu on 03.05.2022.
//

#include "ServerGameModeInitHandler.h"

#include "natives.h"
#include "services.h"
#include "InfoLog.h"

#include <iostream>

using namespace std;

ServerGameModeInitHandler::ServerGameModeInitHandler(Server& server) : ServerEventHandler(server) {

}

ServerGameModeInitHandler::~ServerGameModeInitHandler() {

}

bool ServerGameModeInitHandler::execute() {
    InfoLog(__FILE__, __LINE__, "The server of Fxrwxrd project is loaded").print();

    ServerConfigService configService(server);
    configService.setupRconConfig();
    configService.setupGameModeConfig();

    return true;
}