//
// Created by dubininvyu on 25.06.2022.
//


#pragma once

#include "AccountLocale.h"

class LocaleService {
private:
protected:
    AccountLocale& locale;
public:
    LocaleService(AccountLocale& locale);
    ~LocaleService();

    static size_t loadLocales();
};

