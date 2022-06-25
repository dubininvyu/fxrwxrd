//
// Created by dubininvyu on 07.05.2022.
//

#include "RegistrationConfigService.h"

#include "Server.h"
#include "natives.h"
#include "repositories.h"

RegistrationConfigService::RegistrationConfigService(Server& server) : ServerService(server) {

}

RegistrationConfigService::~RegistrationConfigService() {

}

bool RegistrationConfigService::setupConfig() {
    RegistrationConfigRepository configRepository(Repository::MODE_NOPE);
    return configRepository.load();
}