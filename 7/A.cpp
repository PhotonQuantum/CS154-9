#include <iostream>
using namespace std;

void delch(char *str, char c){
    char *head = str;
    while (*str != '\0'){
        if (*str != c) {
            *head = *str;
            head++;
        }
        str++;
    }
    *head = '\0';
}

int main(){
    char str[80];
    char c;
    cin.getline(str, 80);
    cin >> c;
    delch(str, c);
    cout << str;
    return 0;
}
