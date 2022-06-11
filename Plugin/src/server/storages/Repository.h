//
// Created by dubininvyu on 10.05.2022.
//

#pragma once

class Repository {
public:
    enum Mode {
        MODE_NOPE = 1 << 0,

        MODE_READ = 1 << 1,
        MODE_WRITE = 1 << 2,

        MODE_READ_ALL = 1 << 3,
        MODE_WRITE_ALL = 1 << 4,

        MODE_READ_ONLY = (MODE_READ & ~MODE_WRITE),
        MODE_WRITE_ONLY = (~MODE_READ & MODE_WRITE),

        MODE_READ_WRITE = (MODE_READ | MODE_WRITE),
        MODE_WRITE_READ = MODE_READ_WRITE,
    };
private:
protected:
    Repository();
public:
    virtual ~Repository();
};

