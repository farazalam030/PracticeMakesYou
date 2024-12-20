/**
 *
 *
 * Given an unsorted array of size N. Find the first element in array such that
all of its left elements are smaller and all right elements to it are greater
than it.

Note: Left and right side elements can be equal to required element. And extreme
elements cannot be required element.

Input:
The first line of input contains an integer T denoting the number of test cases.
Then T test cases follow. Each test case consists of two lines. First line of
each test case contains an Integer N denoting size of array and the second line
contains N space separated array elements.

Output:
For each test case, in a new line print the required element. If no such element
present in array then print -1.

Constraints:
1 <= T <= 100
3 <= N <= 106
1 <= A[i] <= 106

Example:
Input:
3
4
4 2 5 7
3
11 9 12
6
4 3 2 7 8 9

Output:
5
-1
7
Explanation:
Testcase 1 : Elements on left of 5 are smaller than 5 and on right of it are
greater than 5.

**
 *
*/
#include <bits/stdc++.h>
using namespace std;
class MidSlope {
public:
  void printArray(vector<int> &a) {
    for (auto &i : a) {
      cout << i << " ";
    }
    cout << endl;
  }
  int midSlope(vector<int> &a) {
    int sz = a.size();
    vector<int> leftMaxs(a.begin(), a.end());
    vector<int> rightMins(a.begin(), a.end());
    // leftMaxs[0] = INT_MIN;
    // rightMins[sz - 1] = INT_MAX;
    for (int i = 1; i < sz; i++) {
      leftMaxs[i] = max(a[i - 1], leftMaxs[i - 1]);
      //   rightMins[sz - i - 1] = max(a[sz - i - 1], rightMins[sz - i - 1]);
    }

    for (int i = sz - 2; i >= 0; i--) {
      //   leftMaxs[i] = min(a[i], leftMaxs[i]);
      rightMins[i] = min(a[i + 1], rightMins[i + 1]);
    }
    cout << "originalArray\n";
    printArray(a);

    cout << "LeftMax Array\n";
    printArray(leftMaxs);

    cout << "RightMins Array\n";
    printArray(rightMins);

    for (int i = 0; i < sz; i++) {
      if (a[i] > leftMaxs[i] && a[i] < rightMins[i]) {
        return a[i];
      }
      // return -1;
    }
    return -1;
  }
};

int main() {
  int t;
  //   cin >> t;
  t = 1;
  while (t--) {
    int n;
    // cin >> n;
    vector<int> a{5, 1, 4, 3, 6, 8, 10, 7, 9};
    int tmp;
    // for (int i = 0; i < n; i++) {
    //   cin >> tmp;
    //   a.push_back(tmp);
    // }
    MidSlope ms;
    cout << "result = " << ms.midSlope(a) << endl;
  }
  return 0;
}
