//
// Created by dubininvyu on 10.05.2022.
//

#pragma once

#include "MySQLRepository.h"
#include "RconConfig.h"

#include <any>
#include <map>

using namespace std;

typedef RconConfig::Param Param;

class RconConfigRepository : public MySQLRepository {
private:
protected:
    static const string CONFIG_PATH;
    static const string CONFIG_NAME;

    typedef map<string, string> map_params;
    static map_params params;
public:
    RconConfigRepository(Mode mode = MODE_NOPE);
    virtual ~RconConfigRepository();

    virtual bool preload();

    string getParam(Param param);
    string getDefaultParam(Param param);
};

