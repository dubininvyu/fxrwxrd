//
// Created by dubininvyu on 03.05.2022.
//

#include "ServerGameModeExitHandler.h"

#include "natives.h"
#include "services.h"
#include "InfoLog.h"

#include <iostream>

using namespace std;

ServerGameModeExitHandler::ServerGameModeExitHandler(Server& server) : ServerEventHandler(server) {

}

ServerGameModeExitHandler::~ServerGameModeExitHandler() {

}

bool ServerGameModeExitHandler::execute() {
    InfoLog(__FILE__, __LINE__, "The server of Fxrwxrd project is unloaded").print();

    return true;
}