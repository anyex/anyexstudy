/*
 * Date.cpp
 *
 *  Created on: 2010-1-23
 *      Author: kwarph
 */
#include <iostream>
#include <cstdio>

#include "Date.h"

Date::Date(int year, int month, int day) :
    _time() {
    _time.tm_year = year - 1900;
    _time.tm_mon = month - 1;
    _time.tm_mday = day;
    refresh();
}

Date Date::today() {
    time_t n = time(0);
    tm* t = localtime(&n);
    return Date(t->tm_year + 1900, t->tm_mon + 1, t->tm_mday);
}

int Date::get(const Field& field) const {
    switch (field) {
    case YEAR:
        return _time.tm_year + 1900;
    case MONTH:
        return _time.tm_mon + 1;
    case DAY_OF_MONTH:
        return _time.tm_mday;
    default:
        return 0;
    }
}

Date& Date::set(const int& value, const Field& field) {
    switch (field) {
    case YEAR:
        _time.tm_year = value - 1900;
        break;
    case MONTH:
        _time.tm_mon = value - 1;
        break;
    case DAY_OF_MONTH:
        _time.tm_mday = value;
        break;
    default:
        break;
    }

    refresh();
    return *this;
}

Date& Date::addDay(const int& day) {
    _time.tm_mday += day;
    refresh();
    return *this;
}

Date& Date::addMonth(const int& month) {
    _time.tm_mon += month;
    refresh();
    return *this;
}

Date& Date::addYear(const int& year) {
    _time.tm_year += year;
    refresh();
    return *this;
}

int Date::diff(const Date& other) {
    time_t df = mktime(&_time) - mktime(&other._time);
    return df / 86400;
}

inline void Date::refresh() {
    time_t n = mktime(&_time);
    _time = *localtime(&n);
}

std::string Date::toString() {
    //    char str[11];
    //    std::strftime();

    char str[11];
    std::strftime(str, sizeof(str), "%F", &_time);

    //    std::sprintf(str, "%04d-%02d-%02d", _time.tm_year + 1900, _time.tm_mon + 1,
    //            _time.tm_mday);
    //    char* str = asctime(&_time);
    return str;
}

std::ostream& operator<<(std::ostream& os, const Date& d) {
    char str[11];
    std::strftime(str, sizeof(str), "%F", &d._time);
    return os << str;
}
