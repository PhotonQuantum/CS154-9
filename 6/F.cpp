#include <algorithm>
#include <iostream>
using namespace std;
struct swim {
  int *begin;
  int *end;
  int time = 0;
};

// oops i forgot that only the right ptr is moving. can be refracted to loop
// algorithm
swim swim_func(swim swim_param) {
  int t1, t2;
  swim swim_rtn;
  if ((swim_param.end - swim_param.begin) == 1) {
    swim_rtn.time = swim_param.time + *swim_param.begin + *swim_param.end;
    return swim_rtn;
  } else if ((swim_param.end - swim_param.begin) == 2) {
    swim_rtn.time = swim_param.time + *swim_param.begin +
                    *(swim_param.begin + 1) + *swim_param.end;
    return swim_rtn;
  } else {
    t1 = 2 * *(swim_param.begin + 1) + *swim_param.begin + *swim_param.end;
    t2 = 2 * *swim_param.begin + *swim_param.end + *(swim_param.end - 1);
    swim swim_mid;
    swim_mid.time = swim_param.time + min(t1, t2);
    swim_mid.begin = swim_param.begin;
    swim_mid.end = swim_param.end - 2;
    return swim_func(swim_mid);
  }
}

int main() {
  int n;
  cin >> n;
  int arr[100];
  for (int i = 0; i < n; i++)
    cin >> arr[i];
  sort(arr, arr + n);
  swim swim_quest;
  swim_quest.begin = arr;
  swim_quest.end = arr + n - 1;
  swim swim_ans = swim_func(swim_quest);
  cout << swim_ans.time;
}
