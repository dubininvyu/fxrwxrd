//
// Created by dubininvyu on 17.06.2022.
//


#pragma once

#include "AccountLevel.h"
#include "AccountLicense.h"
#include "AccountLocale.h"
#include "AccountPassword.h"

class Player;

typedef size_t accountID_t;

class Account {
public:
    static const accountID_t MIN_ID = 1;
    static const accountID_t MAX_ID = 1000000;
    static const accountID_t INVALID_ID = 0;
private:
protected:
    Player* player;
    accountID_t id;

    AccountLevel* level;
    AccountLicense* license;
    AccountLocale* locale;
    AccountPassword* password;
public:
    /*
     * constructors & destructors
     */
    Account(Player* player);
    ~Account();

    /*
     * methods
     * static
     */
    static bool const isValid(const accountID_t accountID);

    /*
     * methods
     * setters & getters
     */
    void setID(const accountID_t id);
    accountID_t getID() const;

    void setLocale(const Language language);
    AccountLocale* getLocale();

    Player* getPlayer();

    AccountLevel* getLevel();
    AccountLicense* getLicense();
    AccountPassword* getPassword();
};

