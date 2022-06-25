//
// Created by dubininvyu on 18.06.2022.
//

#pragma once

#include <boost/mpl/size_t.hpp>

using namespace std;

class Account;

typedef size_t level_t;

class AccountLevel {
private:
protected:
    Account* account;
    level_t level;
public:
    AccountLevel(Account* account);
    ~AccountLevel();

    void increase();
    void decrease();

    void setLevel(const level_t level);
    void syncLevel();
    level_t getLevel() const;

    operator level_t() const;
};

