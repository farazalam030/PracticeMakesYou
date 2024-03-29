/*
Problem link :https://practice.geeksforgeeks.org/problems/leaders-in-an-array/0

Given an array of positive integers. Your task is to find the leaders in the
array. Note: An element of array is leader if it is greater than or equal to all
the elements to its right side. Also, the rightmost element is always a leader.

Input:
The first line of input contains an integer T denoting the number of test cases.
The description of T test cases follows. The first line of each test case
contains a single integer N denoting the size of array. The second line contains
N space-separated integers A1, A2, ..., AN denoting the elements of the array.

Output:
Print all the leaders.

Constraints:
1 <= T <= 100
1 <= N <= 107
0 <= Ai <= 107

Example:
Input:
3
6
16 17 4 3 5 2
5
1 2 3 4 0
5
7 4 5 7 3
Output:
17 5 2
4 0
7 7 3

Explanation:
Testcase 3: All elements on the right of 7 (at index 0) are smaller than or
equal to 7. Also, all the elements of right side of 7 (at index 3) are smaller
than 7. And, the last element 3 is itself a leader since no elements are on its
right.

** For More Input/Output Examples Use 'Expected Output' option **
Author: vaibhav95

**/
#include <bits/stdc++.h>
using namespace std;
class LeaderinArray {
 public:
  vector<int> leaderinArray(vector<int> &a) {
    int n = a.size();
    if (n == 0) return {};
    vector<int> ret;
    ret.push_back(a[n - 1]);
    int max = a[n - 1];
    for (int i = n - 2; i >= 0; i--) {
      if (max <= a[i]) {
        ret.push_back(a[i]);
        max = a[i];
      }
    }

    return ret;
  }
};

int main() {
  int t;
  cin >> t;
  while (t--) {
    int n;
    cin >> n;
    vector<int> a;
    for (int i = 0; i < n; i++) {
      int tmp;
      cin >> tmp;
      a.push_back(tmp);
    }

    sort(a.begin(), a.end());
    for (auto i : a) {
      cout << i << " ";
    }

    LeaderinArray la;
    vector<int> ret = la.leaderinArray(a);
    for (auto i = ret.rbegin(); i != ret.rend(); i++) {
      cout << *i << " ";
    }
    cout << endl;
  }

  return 0;
}
