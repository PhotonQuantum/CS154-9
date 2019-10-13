#include <cstring>
#include <iostream>
using namespace std;
struct range {
  int begin;
  int end;
};

void preprocess(char src[], char dest[], int project[]) {
  char *pSrc;
  char *pDest;
  int *pProject;
  int iOldCount = 0;
  pSrc = src;
  pDest = dest;
  pProject = project;
  while (*pSrc != '\0') {
    if (*pSrc >= 'A' && *pSrc <= 'Z') {
      // ok
      *pDest = *pSrc;
      *pProject = iOldCount;
      pProject++;
      pDest++;
    } else if (*pSrc >= 'a' && *pSrc <= 'z') {
      // tolower
      *pDest = *pSrc - 32;
      *pProject = iOldCount;
      pProject++;
      pDest++;
    }
    iOldCount++;
    pSrc++;
  }
  *(pDest + 1) = '\0';
}

bool validate(char *begin, char *end) {
  while (begin < end) {
    if (*begin == *end) {
      begin++;
      end--;
    } else {
      return false;
    }
  }
  return true;
}

struct range search(char src[]) {
  int len = strlen(src);
  char *begin, *end;
  int i;
  struct range rtn;
  for (i = len; i > 1; i--) {
    for (begin = src, end = begin + i; end <= src + len; begin++, end++) {
      if (validate(begin, end)) {
        rtn.begin = begin - src;
        rtn.end = end - src;
        return rtn;
      }
    }
  }
  rtn.begin = rtn.end = 0;
  return rtn;
}

int main() {
  char sOrigin[80], sPre[80];
  cin.getline(sOrigin, 79);

  int iProjection[80];
  int i;
  preprocess(sOrigin, sPre, iProjection);

  struct range rPalin;
  rPalin = search(sPre);
  cout << rPalin.end - rPalin.begin + 1 << endl;

  struct range rOut;
  rOut.begin = iProjection[rPalin.begin];
  rOut.end = iProjection[rPalin.end];
  for (i = rOut.begin; i <= rOut.end; i++) {
    cout << sOrigin[i];
  }
  return 0;
}
