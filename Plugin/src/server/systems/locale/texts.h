//
// Created by dubininvyu on 12.05.2022.
//

#pragma once

enum Text {
    /* =============== short =============== */
    TEXT_YES = 0,
    TEXT_NO,
    TEXT_OK,

    TEXT_CANCEL,
    TEXT_CLOSE,
    TEXT_PREV,
    TEXT_NEXT,

    TEXT_HAVE,
    TEXT_HAVE_NOT,

    TEXT_EXIST,
    TEXT_EXIST_NOT,

    TEXT_CONNECTED,
    TEXT_CONNECTED_NOT,

    TEXT_DONE,
    TEXT_DONE_NOT,

    TEXT_SEX_MAN,
    TEXT_SEX_WOMAN,

    TEXT_NULL,

    /* global */
    TEXT_INFO,
    TEXT_ERROR,
    TEXT_WARNING,

    /* dialogs */
    TEXT_DLG_AUTH_PASS_CAPTION,
    TEXT_DLG_AUTH_PASS_INFO,
    TEXT_DLG_AUTH_PASS_WRONG_CAPTION,
    TEXT_DLG_AUTH_PASS_WRONG_INFO,

    TEXT_DLG_REG_PASS_CAPTION,
    TEXT_DLG_REG_PASS_INFO,
    TEXT_DLG_REG_SEX_CAPTION,
    TEXT_DLG_REG_SEX_INFO,
    TEXT_DLG_REG_FAILED_CAPTION,
    TEXT_DLG_REG_FAILED_INFO,

    /* commands */
    TEXT_UNKNOWN_COMMAND,

    TEXT_COUNT
};