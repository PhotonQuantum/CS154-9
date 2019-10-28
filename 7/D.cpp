#include <iostream>
using namespace std;
int days[] = {31, 28, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31};
char name[][4] = {"Jan", "Feb", "Mar", "Apr", "May", "Jun", "Jul", "Aug", "Sep", "Oct", "Nov", "Dec"};

int main(){
    int input;
    cin >> input;
    int day;
    if (input > 365 || input < 1){
        cout << "NULL";
        return 0;
    }
    for (int i = 0; i < 12; i++){
        if (input <= days[i]) {
            cout << name[i];
            day = input;
            break;
        } else {
            input -= days[i];
        }
    }
    cout << " " << day;
    return 0;
}

