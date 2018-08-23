/*
 * Date.h
 *
 *  Created on: 2010-1-23
 *      Author: kwarph
 */

#ifndef DATE_H_
#define DATE_H_

#include <string>
#include <ctime>
#include <ostream>

class Date {
public:
    enum Field {
        YEAR, MONTH, DAY_OF_MONTH
    };

    Date(int year = 0, int month = 0, int day = 0);

    int get(const Field& field) const;
    // same as:
    // int getDay() const;
    // int getMonth() const;
    // int getYear() const;

    Date& set(const int& value, const Field& field);
    // same as:
    // int setDay(const int& value);
    // int setMonth(const int& value);
    // int setYear(const int& value);

    Date& addDay(const int& day);
    Date& addMonth(const int& month);
    Date& addYear(const int& year);

    // return days between this and other
    int diff(const Date& other);

    std::string toString();

    static Date today();

    friend std::ostream& operator<<(std::ostream& os, const Date& d);

    // Other functions ...

private:
    inline void refresh();

private:
    mutable std::tm _time;
};

#endif /* DATE_H_ */
