#include <iostream>
using namespace std;

int minlen(char *str[], int n){
    int min_count = 100;
    for (int i=0; i<n; i++){
        int counter = 0;
        char *ptr = str[i];
        while (*ptr != '\0'){
            counter++;
            ptr++;
        }
        min_count = (counter < min_count)?counter:min_count;
    }
    return min_count;
}

int main(){
    int n;
    char *input[5];
    cin >> n;
    for (int i=0; i<n; i++){
        input[i] = new char[30];
        cin >> input[i];
    }
    cout << minlen(input, n);
    for (int i=0; i<n; i++){
        delete[] input[i];
    }
    return 0;
}

