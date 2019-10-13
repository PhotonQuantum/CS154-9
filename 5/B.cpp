#include <iostream>
using namespace std;

int main() {
  int table[127] = {};
  char input[80];
  cin.getline(input, 79);

  char *p = input;
  while (*p != '\0') {
    table[*p] += 1;
    p++;
  }
  int i;
  for (i = 126; i >= 32; i--){
    if (table[i] > 0) cout << char(i);
  }
  return 0;
}
