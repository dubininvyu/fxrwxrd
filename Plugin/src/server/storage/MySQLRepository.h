//
// Created by dubininvyu on 10.05.2022.
//

#pragma once

#include "Repository.h"
#include "MySQLConnector.h"

class MySQLRepository : public Repository {
private:
protected:
    MySQLRepository();
public:
    virtual ~MySQLRepository();
};

