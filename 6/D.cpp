#include <iostream>
using namespace std;

void printInt(int n, int base) {
  char output[80] = {}; // reversed
  char *ptr = output;
  while (n != 0) {
    *ptr = (n % base < 10) ? char(n % base + 48) : char(n % base + 55);
    n /= base;
    ptr++;
  }
  ptr--;
  while ((ptr + 1) != output) {
    cout << *ptr;
    ptr--;
  }
}

int main() {
  int n, base;
  cin >> n >> base;
  printInt(n, base);
  return 0;
}
