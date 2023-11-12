/*
    Given a date, return the corresponding day of the week for that date.
    The input is given as three integers representing the day, month and year respectively.
    Return the answer as one of the following values {"Sunday", "Monday", "Tuesday", "Wednesday", "Thursday", "Friday", "Saturday"}.

    Example 1:

    Input: day = 31, month = 8, year = 2019
    Output: "Saturday"

    Example 2:

    Input: day = 18, month = 7, year = 1999
    Output: "Sunday"

    Example 3:

    Input: day = 15, month = 8, year = 1993
    Output: "Sunday"
*/


class Solution {
public:
    string dayOfTheWeek(int day, int month, int year) {
        tm timeinfo = {0};
        timeinfo.tm_year = year - 1900;
        timeinfo.tm_mon = month - 1;
        timeinfo.tm_mday = day;
        mktime(&timeinfo);

        char weekDay[10];
        strftime(weekDay,10,"%A",&timeinfo);
        return weekDay;
    }
};
