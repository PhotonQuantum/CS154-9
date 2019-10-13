#include <cstring>
#include <iostream>
using namespace std;

int main() {
  int index;
  int result;
  char input[80];
  char target;
  cin.getline(input, 79);
  cin >> target;

  char *p = input;
  index = 0;
  while (*p != '\0') {
    if (*p == target)
      result = index;
    index++;
    p++;
  }
  cout << result;
  return 0;
}
