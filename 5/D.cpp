#include <cstring>
#include <iostream>
using namespace std;

int findarr(char source[][80], int length, char target[80]) {
  int i;
  for (i = 0; i < length; i++) {
    if (strcmp(source[i], target) == 0)
      return i;
  }
  return -1;
}

void append(char src, char dest[80]) {
  char *ptr;
  ptr = dest;
  while (*ptr != '\0')
    ptr++;
  *ptr = src;
  *(ptr + 1) = '\0';
}

int main() {
  char input[2][80];
  cin.getline(input[0], 79);
  cin.getline(input[1], 79);

  char *ptr;
  int i;
  int k;
  char lWords[30][80];
  int lCount[30] = {};
  int iLength = 0;
  char tmpbuff[80] = {'\0'};
  for (i = 0; i < 2; i++) {
    ptr = input[i];
    while (*ptr != '\0') {
      if (*ptr == ':' || *ptr == ',') {
        // do nothing.
      } else if (*ptr == ' ' || *ptr == '.') {
        // seperate word
        k = findarr(lWords, iLength, tmpbuff);
        if (k == -1) {
          iLength++;
          strcpy(lWords[iLength - 1], tmpbuff);
          lCount[iLength - 1]++;
        } else {
          lCount[k]++;
        }
        tmpbuff[0] = '\0';
      } else if (*ptr >= 65 && *ptr <= 90) {
        append(*ptr + 32, tmpbuff);
      } else {
        append(*ptr, tmpbuff);
      }
      ptr++;
    }
    if (tmpbuff[0] != '\0') {
      k = findarr(lWords, iLength, tmpbuff);
      if (k == -1) {
        iLength++;
        strcpy(lWords[iLength - 1], tmpbuff);
        lCount[iLength - 1]++;
      } else {
        lCount[k]++;
      }
      tmpbuff[0] = '\0';
    }
  }
  int j;
  for (i = 0; i < iLength; i++) {
    cout << lWords[i];
    for (j = 0; j < 10 - strlen(lWords[i]); j++)
      cout << " ";
    cout << lCount[i] << endl;
  }

  return 0;
}
