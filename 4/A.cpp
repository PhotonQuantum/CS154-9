#include <iostream>
using namespace std;

bool is_leap(int year){
    return ((year % 400 == 0) || (year % 4 == 0 && year % 100 != 0));
}

int main(){
    int months[] = {31, 28, 31, 30, 31, 30 ,31, 31, 30, 31, 30, 31};
    int day_in_week[7] = {}; // first day is sunday

    int n;
    cin >> n;

    int now_year;
    int now_month;
    int now_day = 0;

    for (now_year=0; now_year < n; now_year++){
        for (now_month=0; now_month < 12; now_month++){
            now_day += 13;
            day_in_week[now_day % 7] += 1;
            now_day += ((now_month == 1 && is_leap(1900+now_year))?29:months[now_month]) - 13;
        }
    }

    cout << day_in_week[1] << " " << day_in_week[2] << " " << day_in_week[3] << " " << day_in_week[4] << " " << day_in_week[5] << " " << day_in_week[6] << " " << day_in_week[0];
}
