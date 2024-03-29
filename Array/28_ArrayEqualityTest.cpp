/*

Given two arrays A and B of equal size N, the task is to find if given arrays
are equal or not. Two arrays are said to be equal if both of them contain same
set of elements, arrangements (or permutation) of elements may be different
though. Note : If there are repetitions, then counts of repeated elements must
also be same for two array to be equal.

Input:
The first line of input contains an integer T denoting the no of test cases.
Then T test cases follow.  Each test case contains 3 lines of input. The first
line contains an integer N denoting the size of the array. The second line
contains element of array A[]. The third line contains elements of the array
B[].

Output:
For each test case, print 1 if the arrays are equal else print 0.

Constraints:
1<=T<=100
1<=N<=107
1<=A[],B[]<=1018

Example:
Input:
2
5
1 2 5 4 0
2 4 5 0 1
3
1 2 5
2 4 15

Output:
1
0

Explanation:
Testcase1:
Input : A[] = {1, 2, 5, 4, 0}; B[] = {2, 4, 5, 0, 1};
Output : 1

Testcase2:
Input : A[] = {1, 2, 5}; B[] = {2, 4, 15};
Output : 0
 


** For More Input/Output Examples Use 'Expected Output' option **
Author: Shubham Joshi 1
*/
#include <bits/stdc++.h>
using namespace std;

class ArrayEquality {
public:
  int isEqualArray(vector<int> &a, vector<int> &b) {
    int an = a.size();
    int bn = b.size();
    if (an != bn)
      return 0;
    unordered_map<int, int> mmap;
    for (int i = 0; i < an; i++) {
      if (mmap.find(a[i]) == mmap.end()) {
        mmap[a[i]] = 1;
      } else
        mmap[a[i]]++;
    }
    for (int i = 0; i < bn; i++) {
      if (mmap.find(b[i]) == mmap.end()) {
        return 0;
      }
      mmap[b[i]]--;
    }

    for (auto j : mmap) {
      if (j.second != 0)
        return 0;
    }
    return 1;
  }
};

int main(int argc, const char **argv) {
  int t;
  cin >> t;
  while (t--) {
    int n;
    cin >> n;
    vector<int> a;
    vector<int> b;

    int x;
    for (int i = 0; i < n; i++) {
      cin >> x;
      a.push_back(x);
    }
    for (int i = 0; i < n; i++) {
      cin >> x;
      b.push_back(x);
    }
    ArrayEquality ae;
    cout << ae.isEqualArray(a, b) << endl;
  }

  return 0;
}