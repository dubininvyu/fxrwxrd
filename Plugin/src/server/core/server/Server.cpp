//
// Created by dubininvyu on 01.05.2022.
//

#include "Server.h"

#include "natives.h"

using namespace std;

/*
 * constructor & destructors
 */
Server::Server() : enabled(false) {
    rconConfig = new RconConfig();
    registrationConfig = new RegistrationConfig();
}

Server::~Server() {
    delete rconConfig;
    delete registrationConfig;
}

/*
 * methods
 * static
 */

Server& Server::getInstance() {
	static Server server;
	return server;
}

/*
 * methods
 * setters & getters
 */
void Server::setEnabled(const bool enabled) {
    this->enabled = enabled;
}

bool Server::isEnabled() const {
    return enabled;
}

/*
 * methods
 * server params
 */
RconConfig* Server::getRconConfig() {
    return rconConfig;
}

RegistrationConfig* Server::getRegistrationConfig() {
    return registrationConfig;
}