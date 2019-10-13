#include <iostream>
using namespace std;

int main(){
    int i, j;
    int R;
    cin >> R;

    int **arr = new int*[R];
    for (i=0; i<R; i++){
        arr[i] = new int[R];
        for (j=0; j<i+1; j++){
            cin >> arr[i][j];
        }
    }

    for (i=R-2; i>=0; i--){
        for (j=0; j<=i; j++){
            arr[i][j] += (arr[i+1][j] > arr[i+1][j+1])?arr[i+1][j]:arr[i+1][j+1];
        }
    }

    cout << arr[0][0];
    return 0;
}
