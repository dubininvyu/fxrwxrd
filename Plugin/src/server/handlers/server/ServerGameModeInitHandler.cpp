//
// Created by dubininvyu on 03.05.2022.
//

#include "ServerGameModeInitHandler.h"

#include "services.h"
#include "InfoLog.h"

#include "boost/format.hpp"

using namespace std;
using namespace boost;

ServerGameModeInitHandler::ServerGameModeInitHandler(Server& server) : ServerEventHandler(server) {

}

ServerGameModeInitHandler::~ServerGameModeInitHandler() {

}

bool ServerGameModeInitHandler::execute() {
    InfoLog(__FILE__, __LINE__, "The server of Fxrwxrd project is loaded").print();

    // server
    ServerConfigService configService(server);
    configService.setupRconConfig();
    configService.setupGameModeConfig();

    // vehicles
    size_t nVehicles = VehicleDataService::loadVehicles();
    if (nVehicles) {
        format fmt = format("Vehicles loaded successfully (%d pcs.)")
                     % nVehicles;

        InfoLog(__FILE__, __LINE__, fmt.str()).print();
    }

    return true;
}