#include <iostream>
using namespace std;

void swap(int *xp, int *yp) {
  int tmp = *xp;
  *xp = *yp;
  *yp = tmp;
}

int main() {
  int n;
  int *arr;

  cin >> n;
  arr = new int[n];

  int i, j;
  for (i = 0; i < n; i++) {
    cin >> arr[i];
  }

  for (i = 0; i < n; i++) {
    for (j = 0; j < n - i; j++) {
      if (arr[j] < arr[j + 1])
        swap(&arr[j], &arr[j + 1]);
    }
  }

  for (i = 0; i < n - 1; i++)
    cout << arr[i] << " ";
  cout << arr[n - 1];
  return 0;
}
