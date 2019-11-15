#include <iostream>
#include <string>
#include <cstring>
#include <algorithm>
using namespace std;


class Date
{
public:
    Date(int year = 1900, int month = 1, int day = 1){
        this->_year = year;
        this->_month = month;
        this->_day = day;
    }
    int get_day() const {
        return _day;
    }
    int get_month() const {
        return _month;
    }
    int get_year() const {
        return _year;
    }
    int subtract(const Date d2)
    {
        const int months[]={0, 31, 28, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31};
        int tmp_days = 0;
        int d1_days = 0;
        int d2_days = 0;
        int d2_year=d2.get_year(), d2_month=d2.get_month(), d2_day=d2.get_day();
        bool d1_leap =  _year % 400 == 0 || (_year % 4 == 0 && _year % 100 != 0);
        bool d2_leap = d2_year % 400 == 0 || (d2_year % 4 == 0 && d2_year % 100 != 0);
        for (int i=d2_year; i<_year; i++){
            tmp_days += i % 400 == 0 || ((i % 4 == 0) && (i % 100 != 0)) ?366:365;
                }
        for (int i=1; i<d2_month; i++)
            d2_days += months[i] + (d2_leap && i==2 ?1:0);
        d2_days += d2_day;
        for (int i=1; i<_month; i++)
            d1_days += months[i] + (d1_leap && i==2 ?1:0);
        d1_days += _day;
        tmp_days += d1_days - d2_days;
        return tmp_days;
    }

    Date add_year(int y)
    {
        _year += y;
        bool d1_leap =  _year % 400 == 0 || (_year % 4 == 0 && _year % 100 != 0);
        if (d1_leap == false && _month == 2 && _day == 29) _day = 28;
        return *this;
    }

    Date sub_year(int y)
    {
        _year -= y;
        bool d1_leap =  _year % 400 == 0 || (_year % 4 == 0 && _year % 100 != 0);
        if (d1_leap == false && _month == 2 && _day == 29) _day = 28;
        return *this;
    }

    Date add_month(int m)
    {
        const int months[]={0, 31, 28, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31};
        for (int i = 0; i < m; i++){
        if (_month == 12){
            _year += 1;
            _month = 1;
        } else {
            _month += 1;
        }
        }
        int month_days = months[_month] + (((_year % 400 == 0 || (_year % 4 == 0 && _year % 100 != 0)) && _month == 2)?1:0);
        _day = (month_days < _day) ? month_days : _day;
        return *this;
    }

    Date sub_month(int m)
    {   
        const int months[]={0, 31, 28, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31};
        for (int i = 0; i < m; i++){
        if (_month == 1){
            _year -= 1;
            _month = 12;
        } else {
            _month -= 1;
        }
        }
        int month_days = months[_month] + (((_year % 400 == 0 || (_year % 4 == 0 && _year % 100 != 0)) && _month == 2)?1:0);
        _day = (month_days < _day) ? month_days : _day;
        return *this;
    }

    Date add_day(int d)
    {
        const int months[]={0, 31, 28, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31};
        for (int i=0; i<d; i++){
            int month_days = months[_month] + (((_year % 400 == 0 || (_year % 4 == 0 && _year % 100 != 0)) && _month == 2)?1:0);
            if (_day == month_days){
                _day = 1;
                this->add_month(1);
            } else {
                _day += 1;
            }
        }
        return *this;
    }

    Date sub_day(int d)
    {
        const int months[]={0, 31, 28, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31};
        for (int i=0; i<d; i++){
            if (_day == 1){
                _day = 31;
                this->sub_month(1);
            } else {
                _day -= 1;
            }
        }
        return *this;
    }


    void Display()
    {
        cout << _year << "-" << _month << "-" << _day << endl;
    }
private:
    int _year;
    int _month;
    int _day;

};

int main()
{
    Date d1(2015, 12, 3);

    Date d2(2015, 11, 1);

    cout << d1.subtract(d2)<<endl;

    Date d3(1928, 12, 3);

    Date d4(2018, 11, 11);

    cout<< d4.subtract(d3)<<endl;;

    return 0;

}
