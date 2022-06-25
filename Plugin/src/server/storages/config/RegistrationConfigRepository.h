//
// Created by dubininvyu on 10.05.2022.
//

#pragma once

#include "MySQLRepository.h"

#include <any>
#include <map>

using namespace std;

class RegistrationConfigRepository : public MySQLRepository {
private:
protected:
public:
    RegistrationConfigRepository(Mode mode = MODE_NOPE);
    virtual ~RegistrationConfigRepository();

    virtual bool preload();

    bool load();
};

