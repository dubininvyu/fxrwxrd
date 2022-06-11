//
// Created by dubininvyu on 10.05.2022.
//

#pragma once

#include "PlayerLocale.h"
#include "MySQLRepository.h"

class LocaleRepository : MySQLRepository {
private:
protected:
    PlayerLocale& locale;
public:
    LocaleRepository(PlayerLocale& locale);
    ~LocaleRepository();

    bool init();
};

