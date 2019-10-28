#include <iostream>
#include <cstring>
using namespace std;

int main(){
    char unit_from, unit_to;
    int number;
    for (int i = 0; i < 2; i++){
        cin.ignore(10, ' ');
    }
    cin >> unit_to;
        cin.ignore(10, ' ');
    for (int i = 0; i < 2; i++){
        cin.ignore(10, ' ');
    }
    cin >> number;
    cin.ignore(3);
    cin >> unit_from;
    double std_number;
    switch (unit_from){
        case 'l':
            std_number = number;
            break;
        case 'n':
            std_number = number * 10;
            break;
        case 'c':
            std_number = number * 100;
            break;
        case 't':
            std_number = number * 1000;
            break;
    }
    double out_number;
    switch (unit_to){
        case 'i':
            out_number = std_number * 0.0394;
            break;
        case 'f':
            out_number = std_number / 1000 * 3.28;
            break;
        case 'y':
            out_number = std_number / 1000 * 1.0936;
            break;
    }
    cout << out_number;
}
