//
// Created by dubininvyu on 10.05.2022.
//

#pragma once

#include "MySQLRepository.h"

#include "Server.h"

#include <any>
#include <map>

using namespace std;

class ServerRconConfigRepository : public MySQLRepository {
private:
protected:
    static const string CONFIG_PATH;
    static const string CONFIG_NAME;

    typedef map<string, string> map_params;
    static map_params params;
public:
    ServerRconConfigRepository(Mode mode = MODE_READ);
    virtual ~ServerRconConfigRepository();

    virtual bool preload();

    string getParam(Server::CONFIG_PARAM param);
    string getDefaultParam(Server::CONFIG_PARAM param);
};

