#include <iostream>
using namespace std;

bool validate(int num) {
  int sum=0;
  for (int i = 1; i < num; i++) {
    if (num % i == 0)
      sum += i;
  }
  return (sum == num);
}
int main() {
  int min, max;
  cin >> min >> max;
  for (int i = min; i <= max; i++) {
    if (validate(i))
      cout << i << endl;
  }
  return 0;
}
