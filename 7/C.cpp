#include <iostream>
using namespace std;

int main(){
    int input;
    char ring[80] = {};
    cin >> input;
    ring[input] = -1;
    char *ptr_ring = ring;
    int counter = 0;
    while (true){
        counter = (counter > 3)?1:counter+1;
        if (input == 1) break;
        if (*ptr_ring == -1){
            ptr_ring = ring;
        }
        if (counter % 3 == 0) {
            *ptr_ring = 1;
            input--;
        }
        ptr_ring++;
    }
    ptr_ring = ring;
    while (*ptr_ring != -1){ 
        if (*ptr_ring == 0) break;
        ptr_ring++;
    }
    cout << ptr_ring - ring + 1;
}
