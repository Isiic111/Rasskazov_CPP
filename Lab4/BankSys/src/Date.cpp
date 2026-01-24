#include "Date.h"
#include <sstream>
#include <iomanip>

Date::Date() : day(1), month(1), year(2000) {}

Date::Date(int d, int m, int y) : day(d), month(m), year(y) {
    if (!isValidDate(d, m, y)) {
        day = 1; month = 1; year = 2000;
    }
}

bool Date::isValidDate(int d, int m, int y) const {
    if (y < 1900 || y > 2100) return false;
    if (m < 1 || m > 12) return false;
    
    int daysInMonth[] = {31, 28, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31};
    
    // Проверка високосного года
    if ((y % 4 == 0 && y % 100 != 0) || (y % 400 == 0)) {
        daysInMonth[1] = 29;
    }
    
    return (d >= 1 && d <= daysInMonth[m-1]);
}

void Date::setDate(int d, int m, int y) {
    if (isValidDate(d, m, y)) {
        day = d; month = m; year = y;
    }
}

std::string Date::toString() const {
    std::ostringstream oss;
    oss << std::setw(2) << std::setfill('0') << day << "."
        << std::setw(2) << std::setfill('0') << month << "."
        << year;
    return oss.str();
}

Date Date::getCurrentDate() {
    std::time_t t = std::time(nullptr);
    std::tm* now = std::localtime(&t);
    return Date(now->tm_mday, now->tm_mon + 1, now->tm_year + 1900);
}

std::ostream& operator<<(std::ostream& os, const Date& date) {
    os << date.toString();
    return os;
}