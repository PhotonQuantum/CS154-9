#include <iostream>
using namespace std;

int calc(int num1, int num2, char opt){
    switch (opt){
        case ('+'):
            return num1+num2;
        case ('-'):
            return num1-num2;
        case ('*'):
            return num1*num2;
        case ('/'):
            return num1/num2;
    }
    return -1;
}

int main(){
    int num1, num2;
    char opt;
    cin.ignore(5);
    cin >> num1 >> opt >> num2;
    cout << calc(num1, num2, opt);
    return 0;
}
