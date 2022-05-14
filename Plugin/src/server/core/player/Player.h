//
// Created by dubininvyu on 01.05.2022.
//

#pragma once

#include "Person.h"

#include "PlayerLocale.h"
#include "PlayerDialog.h"

#include "texts.h"
#include "Dialog.h"

#include <list>

class Player : public Person {
public:
    static const unsigned int MAX_LENGTH_IP;
    static const unsigned int MAX_LENGTH_SERIAL;
    static const unsigned int MIN_LENGTH_PASSWORD;
    static const unsigned int MAX_LENGTH_PASSWORD;
private:
protected:
    unsigned int uid;
    static Player* players[];

    /* main */
    PlayerLocale* locale;
    PlayerDialog* dialog;

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
    void setLocale(Language language);
    PlayerLocale* getLocale();

    PlayerDialog* getDialog();

    /* others */

    /* functions */
    void init();

    /* natives */
    bool sendMessage(Text text);
    bool sendMessage(const string& message);
    static bool sendMessageToAll(Text text);
    static bool sendMessageToAll(const string& message);

};