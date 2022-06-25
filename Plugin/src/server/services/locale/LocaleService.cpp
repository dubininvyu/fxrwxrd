//
// Created by dubininvyu on 25.06.2022.
//

#include "LocaleService.h"
#include "LocaleRepository.h"

LocaleService::LocaleService(AccountLocale& locale) : locale(locale) {

}

LocaleService::~LocaleService() {

}

size_t LocaleService::loadLocales() {
    return LocaleRepository::loadLocales();
}