//
// Created by dubininvyu on 10.05.2022.
//

#include "JsonRepository.h"

JsonRepository::JsonRepository(const string& filePath) :
    Repository(), filePath(filePath), file(ifstream(filePath)), json() {

}

JsonRepository::~JsonRepository() {
    if (file.is_open()) {
        file.close();
    }
}

bool JsonRepository::isKeyExist(json::json_pointer& jsonPointer) const {
    if (json.empty()) {
        throw Exception(__FILE__, __LINE__, "Couldn't get JSON value: JSON object is empty");
    }

    return json.contains(jsonPointer);
}