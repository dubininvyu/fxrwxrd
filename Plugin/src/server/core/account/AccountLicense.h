//
// Created by dubininvyu on 12.06.2022.
//


#pragma once

class Account;

class AccountLicense {
public:
    enum License {
        LICENSE_NONE = 0,

        LICENSE_A,
        LICENSE_B,
        LICENSE_C,
        LICENSE_D,
        LICENSE_CE,
        LICENSE_W,
        LICENSE_F,
        LICENSE_T,
        LICENSE_R,

        COUNT
    };
private:
protected:
    Account* account;

    bool licenses[License::COUNT];
public:
    AccountLicense(Account* account);
    ~AccountLicense();

    void setLicense(const License license, const bool value);
    bool isLicense(const License license) const;

    bool isValid(const License license) const;
};

