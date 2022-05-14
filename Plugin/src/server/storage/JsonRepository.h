//
// Created by dubininvyu on 10.05.2022.
//

#pragma once

#include "Repository.h"
#include "json-parser/json.hpp"
#include "Exception.h"

#include <string>
#include <fstream>

using namespace std;
using namespace nlohmann;

class JsonRepository : public Repository {
private:
protected:
    string filePath;
    ifstream file;
    json json;

    JsonRepository(const string& filePath);
public:
    virtual ~JsonRepository();

    bool isKeyExist(json::json_pointer& jsonPointer) const;
};

