#include <iostream>
#include <random>
#include <cstring>

const char *article[]={"the", "a", "one", "some", "any"};
const char *noun[]={"boy", "girl", "dog", "town", "can"};
const char *verb[]={"drove", "jumped", "ran", "walked", "skipped"};
const char *preposition[]={"to", "from", "under", "overd", "go"};

int randint(int upper){
    return rand()%(upper+1);
}

int main(){
    using namespace std;
    for (int i=0; i<20; i++){
        char tmp[80];
        tmp[0]='\0';
        strcat(tmp, *(article+randint(4)));
        strcat(tmp, " ");
        strcat(tmp, *(noun+randint(4)));
        strcat(tmp, " ");
        strcat(tmp, *(verb+randint(4)));
        strcat(tmp, " ");
        strcat(tmp, *(preposition+randint(4)));
        strcat(tmp, " ");
        strcat(tmp, *(article+randint(4)));
        strcat(tmp, " ");
        strcat(tmp, *(noun+randint(4)));
        tmp[0] = tmp[0] - 32;
        cout << tmp << "." << endl;
    }
    return 0;
}
