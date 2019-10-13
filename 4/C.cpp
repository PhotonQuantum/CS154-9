#include <iostream>
using namespace std;

int main() {
  int i, j, k;
  int m, n;
  cin >> m >> n;

  int **arr = new int *[m];
  for (i = 0; i < m; i++) {
    arr[i] = new int[n];
    for (j = 0; j < n; j++) {
      cin >> arr[i][j];
    }
  }

  int target;
  int r, c;
  int targetr = -1, targetc = -1, targetv = -1;
  bool found = false;
  for (i = 0; i < m; i++) {
    target = arr[i][0];
    r = i;
    c = 0;
    for (j = 0; j < n; j++) {
      if (arr[i][j] > target) {
        target = arr[i][j];
        c = j;
      }
    }

    found = true;
    for (j = 0; j < m; j++) {
      if (arr[j][c] < target) {
        found = false;
        break;
      }
    }
    if (found) {
      if (targetr == r && targetc == c) {
        targetr = targetc = -1;
        break;
      } else {
        targetr = r;
        targetc = c;
        targetv = target;
      }
    }
  }
  if (targetr != -1 && targetc != -1) {
    cout << "mat[" << targetr << "][" << targetc << "]=" << targetv;
  } else {
    cout << "Not Found";
  }
  return 0;
}
