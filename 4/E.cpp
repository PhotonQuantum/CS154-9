#include <iostream>
using namespace std;

bool validate(int x, int b) {
  int iCvt[15]; // reverted
  int i = 0, j;
  while (x != 0) {
    iCvt[i] = x % b;
    x /= b;
    i++;
  }
  for (j = 0; j < i / 2; j++) {
    if (iCvt[j] != iCvt[i - 1 - j])
      return false;
  }
  return true;
}

void output(int x, int b) {
  int iCvt[15]; // reverted
  int i = 0, j;
  while (x != 0) {
    iCvt[i] = x % b;
    x /= b;
    i++;
  }
  for (j = i - 1; j >= 0; j--) {
    if (iCvt[j] > 9) {
      cout << char(iCvt[j] + 55);
    } else {
      cout << iCvt[j];
    }
  }
}

int main() {
  int b;
  cin >> b;

  int i;
  for (i = 1; i <= 200; i++) {
    if (validate(i * i, b)) {
      output(i, b);
      cout << " ";
      output(i * i, b);
      cout << endl;
    }
  }
  return 0;
}
