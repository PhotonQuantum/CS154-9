#include <iostream>
using namespace std;
struct date{
    int year;
    int month;
    int day;
};
struct member{
    char name[20];
    date birthday;
    char phone[15];
    char address[80];
};

bool older(member member1, member member2){ // whether member1 is older than member2
    int y1=member1.birthday.year;
    int y2=member2.birthday.year;
    int m1=member1.birthday.month;
    int m2=member2.birthday.month;
    int d1=member1.birthday.day;
    int d2=member2.birthday.day;
    if (y1 != y2) {
        return (y1 < y2)?true:false;
    } else if (m1 != m2){
        return (m1 < m2)?true:false;
    } else if (d1 != d2){
        return (d1 < d2)?true:false;
    } else {
        return false;
    }
}

int main(){
    member book[9];
    int n;
    cin >> n;
    for (int i=0; i<n; i++){
        int y, m, d;
        cin >> book[i].name >> y >> m >> d >> book[i].phone;
        book[i].birthday.year = y;
        book[i].birthday.month = m;
        book[i].birthday.day = d;
        cin.ignore();
        cin.getline(book[i].address, 80);
    }
    member tmp;
    for (int i=0; i<n-1; i++){
        for (int j=0; j<n-i-1; j++){
            if (older(book[j], book[j+1])){
                tmp = book[j];
                book[j] = book[j+1];
                book[j+1] = tmp;
            }
        }
    }
    for (int i=0; i<n; i++){
        cout << book[i].name << " " << book[i].birthday.year << "/" << book[i].birthday.month << "/" << book[i].birthday.day << " " << book[i].phone << " " << book[i].address << endl;
    }
    return 0;
}
