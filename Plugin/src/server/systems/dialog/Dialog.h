//
// Created by dubininvyu on 12.05.2022.
//

#pragma once

#include <string>
#include <sstream>

class Player;

using namespace std;

class Dialog {
public:
    enum Style {
        STYLE_MSGBOX = 0,
        STYLE_INPUT,
        STYLE_LIST,
        STYLE_PASSWORD,
        STYLE_TABLIST,
        STYLE_TABLIST_HEADERS
    };

    enum Button {
        BUTTON_LEFT = 0,
        BUTTON_RIGHT,
    };

    enum Result {
        RESULT_CLOSE = 0,
        RESULT_REPEAT,
        RESULT_PREV_PAGE,
        RESULT_NEXT_PAGE,
    };

    enum DialogID {
        DIALOG_NOPE = -1,

        DIALOG_AUTHORIZATION,
        DIALOG_REGISTRATION
    };

private:
protected:
    Player* player;

    DialogID dialog;
    Style style;

    string caption;
    string info;

    string button[2];

    unsigned int page;
    unsigned int pageCount;
public:
    Dialog(Player* player);
    Dialog(Player* player, const string& caption, const string& info, const string& button1, const string& button2);
    virtual ~Dialog();

    virtual bool format();

    bool nextPage();
    bool prevPage();
    unsigned int getPage() const;
    unsigned int getPageCount() const;

    bool show();
    void hide();

    virtual Result responseStart(const unsigned int response, unsigned int listItem, const string& inputText) = 0;
    Result response(const unsigned int response, unsigned int listItem, const string& inputText);
    virtual Result responseEnd(const unsigned int response, unsigned int listItem, const string& inputText) = 0;

    void setDialogID(const DialogID dialog);
    DialogID getDialogID() const;

    void setStyle(const Style style);
    Style getStyle() const;

    void setCaption(const string& caption);
    string getCaption() const;

    void setInfo(const string& info);
    string getInfo() const;

    void setButton(const Button index, const string& text);
    string getButton(const Button index) const;
};

