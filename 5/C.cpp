#include <iostream>
using namespace std;

int main() {
  char arr[80];
  int n;
  cin >> n;
  cin.ignore();

  int i, j;
  int echar = 0, nchar = 0, achar = 0;
  char *p;
  for (i = 0; i < n; i++) {
    cin.getline(arr, 79);
    p = arr;
    while (*p != '\0') {
      if (('A' <= *p && *p <= 'Z') || ('a' <= *p && *p <= 'z'))
        echar += 1;
      if ('0' <= *p && *p <= '9')
        nchar += 1;
      if (33 <= *p && *p <= 126) {
        achar += 1;
      }
      p++;
    }
  }
  cout << echar << " " << nchar << " " << achar - echar - nchar;
  return 0;
}
