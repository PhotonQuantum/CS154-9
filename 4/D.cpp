#include <iostream>
using namespace std;

int main() {
  int n, k;
  cin >> n >> k;
  int *lamp = new int[n];
  int *person = new int[k];

  int i, j;
  for (i = 0; i < k; i++) {
    for (j = 0; j < n; j++) {
      if ((j + 1) % (i + 1) == 0)
        lamp[j] = (lamp[j] == 1) ? 0 : 1;
    }
  }

  for (i = 0; i < n; i++)
    if (lamp[i] == 1) cout << i + 1 << " ";
}
