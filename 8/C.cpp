#include <iostream>
#include <cstring>
using namespace std;

char *mystrrchr(char *str, char ch){
    char *tail = str + strlen(str) - 1;
    for (char *head = tail; head >= str; head--){
        if (*head == ch){
            return head;
        }
    }
    return NULL;
}

int main(){
    char input[80];
    char ch;
    cin.getline(input, 80);
    cin >> ch;
    char *ptr = mystrrchr(input, ch);
    if (ptr != NULL){
        while (*ptr != '\0'){
            cout << *ptr;
            ptr++;
        }
    } else {
        cout << "NULL";
    }
    return 0;
}
