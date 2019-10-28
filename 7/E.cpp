#include <iostream>
using namespace std;
int ev[] = {8, 7, 3, 4, 9, 6, 2, -1};

char* encrypt(char *input){
    char *p_in = input;
    char *p_out = new char[20];
    char *p_out_init = p_out;
    char c_tmp;
    int *p_ev = ev;
    while (*p_in != '\0'){
        if (*p_ev == -1) p_ev = ev;
        c_tmp = *p_in + *p_ev;
        if (c_tmp > 122) c_tmp -= 91;
        *p_out = c_tmp;
        p_in++;
        p_out++;
        p_ev++;
    }
    *(p_out + 1) = '\0';
    return p_out_init;
}

char* decrypt(char *input){
    char *p_in = input;
    char *p_out = new char[20];
    char *p_out_init = p_out;
    char c_tmp;
    int *p_ev = ev;
    while (*p_in != '\0'){
        if (*p_ev == -1) p_ev = ev;
        c_tmp = *p_in - *p_ev;
        if (c_tmp < 32) c_tmp += 91;
        *p_out = c_tmp;
        p_in++;
        p_out++;
        p_ev++;
    }
    *(p_out + 1) = '\0';
    return p_out_init;
}

int main(){
    char input[20];
    cin >> input;
    char *p_enc;
    char *p_dec;
    p_enc = encrypt(input);
    cout << p_enc << endl;
    p_dec = decrypt(p_enc);
    cout << p_dec << endl;
    delete[] p_enc;
    delete[] p_dec;
}
