//
// Created by dubininvyu on 10.05.2022.
//

#include "Repository.h"

#include "logs.h"

Repository::Repository(Mode mode) : mode(mode) {

    if (mode & MODE_READ_ALL) {
        preload();
    }
}

Repository::~Repository() {

}

bool Repository::preload() {
    return true;
}