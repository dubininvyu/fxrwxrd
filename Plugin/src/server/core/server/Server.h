//
// Created by dubininvyu on 01.05.2022.
//

#pragma once

#include "configs.h"
#include "defines.h"

#include <map>
#include <string>
#include <variant>

using namespace std;

class Server {
public:
private:
protected:
    bool enabled;

    RconConfig* rconConfig;
    RegistrationConfig* registrationConfig;

    Server();
public:
	~Server();

	/*
	 * methods
	 * static
	 */
	static Server& getInstance();

	/*
	 * methods
	 * setters & getters
	 */
	void setEnabled(const bool enabled);
	bool isEnabled() const;

	/*
	 * methods
	 * server params
	 */
	RconConfig* getRconConfig();
	RegistrationConfig* getRegistrationConfig();
};