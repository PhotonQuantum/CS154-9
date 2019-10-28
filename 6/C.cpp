#include <cmath>
#include <iostream>
using namespace std;

bool is_prime(int num) {
  if (num < 4) {
    return (num > 1);
  } else if (num % 2 == 0 || num % 3 == 0) {
    return false;
  } else {
    int end = floor(sqrt(num));
    for (int i = 5; i <= end; i++) {
      if (num % i == 0 || num % (i + 2) == 0)
        return false;
    }
  }
  return true;
}

int main() {
  int min, max;
  cin >> min >> max;
  int count = 0;
  for (int i = min; i <= max; i++) {
    if (is_prime(i))
      count++;
  }
  cout << count;
  return 0;
}
