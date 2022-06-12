//
// Created by dubininvyu on 01.05.2022.
//

#pragma once

#include "Person.h"

#include "Admin.h"

#include "PlayerLocale.h"
#include "PlayerPassword.h"
#include "PlayerLicense.h"

#include "managers.h"

#include "texts.h"
#include "Dialog.h"

#include <list>

class Player : public Person {
public:
    static const unsigned int MAX_LENGTH_SERIAL;
private:
protected:
    unsigned int uid;
    static Player* players[];

    /* main */
    Admin* admin;
    PlayerPassword* password;
    PlayerLocale* locale;
    PlayerLicense* license;

    DialogManager* dialogManager;
    StateMachineManager* stateMachineManager;

    /* others */
public:
    Player();
    Player(unsigned int playerID);
    virtual ~Player();

    /* main */
    static Player* create(int playerID);
    static Player* get(int playerID);
    void remove() const;

    static unsigned int getCount();

    bool isValid() const;
    static bool isValid(unsigned int playerID);

    /* setters & getters */
    void setUID(const unsigned int uid);
    unsigned int getUID() const;

    /* main */
    Admin* getAdmin();
    PlayerPassword* getPassword();

    void setLocale(Language language);
    PlayerLocale* getLocale() const;

    PlayerLicense* getLicense();

    /* managers */
    DialogManager* getDialogManager();
    StateMachineManager* getStateMachineManager();

    /* others */

    /* functions */
    void init();

    /* natives */
    bool sendMessage(Text text) const;
    bool sendMessage(const string& message) const;
    static bool sendMessageToAll(Text text);
    static bool sendMessageToAll(const string& message);

};