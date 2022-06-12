//
// Created by dubininvyu on 12.06.2022.
//


#pragma once

class Player;

class PlayerLicense {
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
    Player* player;
    bool licenses[License::COUNT];
public:
    PlayerLicense(Player* player);
    ~PlayerLicense();

    void setLicense(const License license, bool value = 0);
    bool isLicense(const License license) const;

    bool isValid(const License license) const;
};

