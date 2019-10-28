#include <iostream>
using namespace std;

int max(int arr[], int size) {
  if (size == 1) {
    return *arr;
  } else if (size == 2) {
    return (*arr > *(arr + 1)) ? *arr : *(arr + 1);
  } else if (size % 2 == 0) {
    int left = max(arr, size / 2);
    int right = max(arr + (size / 2), size / 2);
    return (left < right) ? right : left;
  } else {
    int left = max(arr, size / 2 + 1);
    int right = max(arr + (size / 2) + 1, size / 2);
    return (left < right) ? right : left;
  }
}

int main() {
  int n;
  cin >> n;
  int arr[80];
  for (int i = 0; i < n; i++) {
    cin >> arr[i];
  }
  cout << max(arr, n);
  return 0;
}
