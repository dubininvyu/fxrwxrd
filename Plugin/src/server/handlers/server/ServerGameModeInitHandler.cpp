//
// Created by dubininvyu on 03.05.2022.
//

#include "ServerGameModeInitHandler.h"

#include "logs.h"
#include "services.h"

#include "boost/format.hpp"

using namespace std;
using namespace boost;

ServerGameModeInitHandler::ServerGameModeInitHandler(Server& server) : ServerEventHandler(server) {

}

ServerGameModeInitHandler::~ServerGameModeInitHandler() {

}

bool ServerGameModeInitHandler::execute() {
    InfoLog(__FILE__, __LINE__, "The server of Fxrwxrd project is loaded").print();

    bool success = true;

    format fmt;

    /*
     * server
     */
    ServerConfigService serverConfigService(server);
    serverConfigService.setupConfig();

    /*
     * server
     * config
     */
    RconConfigService rconConfigService(server);
    rconConfigService.setupConfig();

    RegistrationConfigService registrationConfigService(server);
    registrationConfigService.setupConfig();

    /*
     * locales
     */
    size_t locales = LocaleService::loadLocales();
    if (!locales) {
        success &= false;
    }

    /*
     * vehicles
     * models
     */
    size_t nModels = VehicleModelService::loadModels();
    if (nModels) {
        fmt = format("Vehicles models loaded successfully (%d pcs)") % nModels;
        InfoLog(__FILE__, __LINE__, fmt.str()).print();
    }
    else {
        success &= false;

        fmt = format("Vehicles models were not loaded");
        WarningLog(__FILE__, __LINE__, fmt.str()).print();
    }

    /*
     * vehicles
     */
    size_t nVehicles = VehicleDataService::loadVehicles();
    if (nVehicles) {
        fmt = format("Vehicles loaded successfully (%d pcs)") % nVehicles;
        InfoLog(__FILE__, __LINE__, fmt.str()).print();
    }
    else {
        success &= false;

        fmt = format("Vehicles were not loaded");
        WarningLog(__FILE__, __LINE__, fmt.str()).print();
    }

    /*
     * server mode
     */
    if (!success) {
        const string message = "The server has been put into inactive mode due to the presence of init errors";
        WarningLog(__FILE__, __LINE__, message).print();
    }

    Server::getInstance().setEnabled(success);

    return true;
}