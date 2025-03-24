#include <iostream>
using namespace std;

class Date {
private:
    int year;
    int month;
    int day;

    static bool is_leap(int y) {
        return (y % 4 == 0 && y % 100 != 0) || (y % 400 == 0);
    }

    static int get_month_days(int m, int y) {
        if (m == 2) {
            return is_leap(y) ? 29 : 28;
        }
        static int days[] = {31, 28, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31};
        return days[m - 1];
    }

public:
    Date() : year(2023), month(5), day(20) {}
    Date(int y, int m, int d) : year(y), month(m), day(d) {}
    
    void Set(int y, int m, int d) {
        year = y;
        month = m;
        day = d;
    }

    int toDays() const {
        int total = 0;
        for (int y = 1; y < year; ++y) {
            total += 365;
            if (is_leap(y)) {
                total += 1;
            }
        }
        for (int m = 1; m < month; ++m) {
            total += get_month_days(m, year);
        }
        total += day;
        return total;
    }

    static Date fromDays(int days) {
        int y = 1;
        while (true) {
            int days_in_y = is_leap(y) ? 366 : 365;
            if (days > days_in_y) {
                days -= days_in_y;
                y++;
            } else {
                break;
            }
        }
        int m = 1;
        for (; m <= 12; ++m) {
            int month_days = get_month_days(m, y);
            if (days <= month_days) {
                break;
            }
            days -= month_days;
        }
        return Date(y, m, days);
    }

    friend ostream& operator<<(ostream& os, const Date& d);

    Date operator+(int n) const {
        return fromDays(toDays() + n);
    }

    Date operator-(int n) const {
        return fromDays(toDays() - n);
    }

    int operator-(const Date& other) const {
        return this->toDays() - other.toDays();
    }
};

ostream& operator<<(ostream& os, const Date& d) {
    os << d.year << '/' << d.month << '/' << d.day;
    return os;
}

int main() {
    Date d1;
    cout << "Show object d1:" << d1 << endl;
    int year, month, day;
    cin >> year >> month >> day;
    Date d2(year, month, day);
    cout << "Show object d2:" << d2 << endl;
    cin >> year >> month >> day;
    d1.Set(year, month, day);
    cout << "Reset and Show object d1:" << d1 << endl;
    int n;
    n = d2 - d1;
    cout << d2 << " - " << d1 << " = " << n << endl;
    cin >> n;
    cout << d1 << " + " << n << " = ";
    Date d3 = d1 + n;
    cout << d3 << endl;
    cout << d1 << " - " << n << " = ";
    d1 = d1 - n;
    cout << d1 << endl;
    return 0;
}
