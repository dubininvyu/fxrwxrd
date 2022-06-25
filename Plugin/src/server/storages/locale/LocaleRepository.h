//
// Created by dubininvyu on 10.05.2022.
//

#pragma once

#include "AccountLocale.h"
#include "MySQLRepository.h"

class LocaleRepository : MySQLRepository {
private:
protected:
    AccountLocale& locale;
public:
    LocaleRepository(AccountLocale& locale);
    ~LocaleRepository();

    virtual bool preload();

    virtual size_t loadTexts();
    static size_t loadLocales();
};

