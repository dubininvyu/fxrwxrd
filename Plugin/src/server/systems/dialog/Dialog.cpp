//
// Created by dubininvyu on 12.05.2022.
//

#include "Dialog.h"
#include "Player.h"
#include "Color.h"
#include "natives.h"

Dialog::Dialog(Player& player) : Dialog(player, "", "", "", "") {

}

Dialog::Dialog(Player& player, const string& caption, const string& info, const string& button1, const string& button2) :
        player(player), caption(caption), info(info), button{button1, button2} {

    page = 0;
    pageCount = 0;
}

Dialog::~Dialog() {

}

bool Dialog::format() {
    /*stringstream captionText;
    captionText << '{' << hex << int(Color::getDialogColor(this->type)) << '}' << this->caption;
    this->caption = captionText.str();*/
    return true;
}

bool Dialog::show() {
    player.getDialog()->setDialog(this);

    format();

    return api_server::native::ShowPlayerDialog(
            player.getID(),
            dialog,
            style,
            caption.c_str(),
            info.c_str(),
            button[BUTTON_LEFT].c_str(),
            button[BUTTON_RIGHT].c_str()
    );
}

void Dialog::hide() {
    api_server::native::ShowPlayerDialog(player.getID(), DIALOG_NOPE, STYLE_MSGBOX, "", "", "", "");
}

Dialog::Result Dialog::response(const unsigned int response, unsigned int listItem, const string& inputText) {
    Result result = responseStart(response, listItem, inputText);

    if (result == RESULT_PREV_PAGE) {
        result = (prevPage()) ? (RESULT_REPEAT) : (RESULT_CLOSE);
    }
    else if (result == RESULT_NEXT_PAGE) {
        result = (nextPage()) ? (RESULT_REPEAT) : (RESULT_CLOSE);
    }

    if (result == RESULT_CLOSE) {
        result = responseEnd(response, listItem, inputText);
    }

    return result;
}

bool Dialog::nextPage() {
    page++;

    if (page >= pageCount) {
        page = pageCount-1;
        return false;
    }

    return true;
}

bool Dialog::prevPage() {
    page--;

    if (page < 0) {
        page = 0;
        return false;
    }

    return true;
}

unsigned int Dialog::getPage() const {
    return page;
}

unsigned int Dialog::getPageCount() const {
    return pageCount;
}

void Dialog::setDialogID(const DialogID dialog) {
    this->dialog = dialog;
}

Dialog::DialogID Dialog::getDialogID() const {
    return this->dialog;
}

void Dialog::setStyle(const Style style) {
    this->style = style;
}

Dialog::Style Dialog::getStyle() const {
    return this->style;
}

void Dialog::setCaption(const string& caption) {
    this->caption = caption;
}

string Dialog::getCaption() const {
    return this->caption;
}

void Dialog::setInfo(const string& info) {
    this->info = info;
}

string Dialog::getInfo() const {
    return this->info;
}

void Dialog::setButton(const Dialog::Button index, const string& text) {
    this->button[index] = text;
}

string Dialog::getButton(const Dialog::Button index) const {
    return this->button[index];
}