//
// Created by dubininvyu on 24.06.2022.
//

#pragma once

struct Event {

};

struct Start {

};

struct Next {

};

struct Error {
    /*
     * public data
     */
    enum ErrorType {
        ERROR_NOPE = 0,

        // authorization system
        ERROR_AUTHORIZATION_LOCALE_LOADING,
        ERROR_AUTHORIZATION_PASSWORD_ENTERING,
        ERROR_AUTHORIZATION_ACCOUNT_LOADING,

        // registration system
        ERROR_REGISTRATION_LOCALE_SELECTION,
        ERROR_REGISTRATION_PASSWORD_ENTERING,
        ERROR_REGISTRATION_SEX_ENTERING,
        ERROR_REGISTRATION_AGE_ENTERING,
        ERROR_REGISTRATION_ACCOUNT_CREATING,
    };

    /*
     * fields
     */
    ErrorType errorType;

    /*
     * constructors & destructors
     */
    Error(const ErrorType errorType) : errorType(errorType) {

    }
};