//
// Created by dubininvyu on 01.05.2022.
//

#include "SQLResult.h"

SQLResult::SQLResult(MYSQL_RES *result) : result(result) {

}

SQLResult::SQLResult(const SQLResult& result) : SQLResult(result.result) {

}

SQLResult::operator bool() {
    return result;
}

SQLResult::operator MYSQL_RES*() {
    return result;
}

void SQLResult::free() {
    if (!result) {
        return;
    }

    mysql_free_result(result);
    result = nullptr;
}

int SQLResult::getNumRows() {
    return mysql_num_rows(result);
}

int SQLResult::getNumFields() {
    return mysql_num_fields(result);
}

MYSQL_ROW SQLResult::fetchRow() {
    return mysql_fetch_row(result);
}

MYSQL_FIELD* SQLResult::fetch(const string& name) {
    mysql_field_seek(result, 0);

    MYSQL_FIELD *field;

    while ((field = fetchField())) {

        if (field->name != name) {
            continue;
        }

        return field;
    }

    return nullptr;
}

MYSQL_FIELD* SQLResult::fetchField() {
    return mysql_fetch_field(result);
}