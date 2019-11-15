#include <iostream>

#include <cstring>

using namespace std;

class LongLongInt {

private:
  char *_str;

public:
  LongLongInt(const char *str) {
    _str = new char[strlen(str)];
    for (int i = strlen(str) - 1; i >= 0; i--)
      _str[i] = str[strlen(str) - i - 1];
    _str[strlen(str)] = '\0';
  };

  LongLongInt(const LongLongInt &b) {
    _str = new char[strlen(b._str)];
    strcpy(_str, b._str);
  };

  ~LongLongInt() { delete[] _str; }

  void plus(const LongLongInt a) {
    char *num1, *num2;
    int len1, len2;
    if (strlen(_str) > strlen(a._str)) {
      num1 = _str;
      num2 = a._str;
    } else {
      num2 = _str;
      num1 = a._str;
    }
    len1 = strlen(num1);
    len2 = strlen(num2);
    char *new_num = new char[len1 + 1];
    strcpy(new_num, num1);
    new_num[len1 + 1] = '\0';
    int spare = 0;
    for (int i = 0; i < len1; i++) {
      if (i < len2) {
        new_num[i] = new_num[i] + num2[i] + spare - 48;
      } else {
        new_num[i] = new_num[i] + spare;
      }
      spare = (new_num[i] - 48) / 10;
      new_num[i] = (new_num[i] - 48) % 10 + 48;
    }
    if (spare != 0) {
      new_num[len1] = '1';
    }
    strcpy(_str, new_num);
  }

  void display() {
    for (int i = strlen(_str) - 1; i >= 0; i--) {
      cout << _str[i];
    }
    cout << endl;
  }
};

int main() {

  LongLongInt a("1234567890987654321");

  LongLongInt b("1234567");

  a.display();

  b.display();

  a.plus(b);

  a.display();

  return 0;
}
