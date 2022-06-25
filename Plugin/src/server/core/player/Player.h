//
// Created by dubininvyu on 01.05.2022.
//

#pragma once

#include "Person.h"

#include "Account.h"
#include "Admin.h"
#include "RconAdmin.h"

#include "managers.h"

#include "texts.h"
#include "Dialog.h"

#include <list>

class Player : public Person {
public:
    static const unsigned int MAX_LENGTH_SERIAL;
private:
protected:
    static size_t count;
    static Player* players[];

    /* main */
    Account* account;
    Admin* admin;
    RconAdmin* rconAdmin;

    DialogManager* dialogManager;
    StateMachineManager* stateMachineManager;

    /* others */
    bool authorized;
public:
    Player();
    Player(const personID_t id, const bool active);
    virtual ~Player();

    /* main */
    static Player* create(const personID_t id);
    static Player* get(const personID_t id);
    void remove() const;

    static const size_t getCount();

    bool isValid() const;
    static bool isValid(const personID_t id);

    void call(const function<void(Player*)> f);
    static void callEveryone(const function<void(Player*)> f);

    /* setters & getters */


    /* main */
    Account* getAccount();
    Admin* getAdmin();
    RconAdmin* getRconAdmin();

    /* managers */
    DialogManager* getDialogManager();
    StateMachineManager* getStateMachineManager();

    /* others */
    void setAuthorized(const bool isAuthorized);
    bool isAuthorized() const;

    /* functions */
    void init();

    /* natives */
    bool sendMessage(TextType text) const;
    bool sendMessage(const string& message) const;
    static bool sendMessageToAll(TextType text);
    static bool sendMessageToAll(const string& message);

};