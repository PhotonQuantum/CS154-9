#include <iostream>
using namespace std;

int search(int *arr, int n, int key){
    int rtn = -1;
    int *head = arr;
    while (arr - head < n){
        if (*arr == key){
            rtn = arr - head;
            break;
        }
        arr++;
    }
    return rtn;
}

int main(){
    int n;
    int arr[20];
    int key;
    cin >> n;
    for (int i=0; i<n; i++){
        cin >> arr[i];
    }
    cin >> key;
    int result;
    result = search(arr, n, key);
    if (result == -1) {
        cout << "Not Found";
    } else {
        cout << result;
    }
    return 0;
}
