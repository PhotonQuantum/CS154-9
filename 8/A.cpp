#include <iostream>
#include <cstring>
using namespace std;

bool str_greater(char *str1, char *str2){ // whether str1 > str2
    char *head1=str1;
    char *head2=str2;
    while (true){
        if (*head1 == '\0'){
            return false;
        } else if (*head2 == '\0'){
            return true;
        } else if (*head1 > *head2){
            return true;
        } else if(*head1 < *head2){
            return false;
        }
        head1++;
        head2++;
    }
    cout << "ERROR!";
    return false;
}

int main(){
    char cities[31][31];
    int i;
    for (i=0;i<31;i++){
        cin.getline(cities[i],30);
        if (cities[i][0] == '@'){
            break;
        }
    }
    char tmp[31];
    for (int j=0; j<i-1; j++){
        for (int k=0; k<i-j-1; k++){
            if (str_greater(cities[k], cities[k+1]) == true){
                strcpy(tmp, cities[k]);
                strcpy(cities[k], cities[k+1]);
                strcpy(cities[k+1], tmp);
            }
        }
    }
    for (int j=0; j<i; j++){
        cout << cities[j] << endl;
    }
    return 0;
}
