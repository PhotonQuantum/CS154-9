#include <iostream>
using namespace std;

int fac(int num){
    int answer=1;
    for (int i=2; i<=num; i++)
        answer *= i;
    return answer;
}

int main(){
    int r, n;
    cin >> r >> n;
    cout << fac(n)/(fac(r)*fac(n-r));
    return 0;
}
