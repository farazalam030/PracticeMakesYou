/*
 *
 * Sum of minimum and maximum elements of all subarrays of size k.
Given an array of both positive and negative integers, the task is to compute
sum of minimum and maximum elements of all sub-array of size k.

Examples:

Input : arr[] = {2, 5, -1, 7, -3, -1, -2}
        K = 4
Output : 18
Explanation : Subarrays of size 4 are :
     {2, 5, -1, 7},   min + max = -1 + 7 = 6
     {5, -1, 7, -3},  min + max = -3 + 7 = 4
     {-1, 7, -3, -1}, min + max = -3 + 7 = 4
     {7, -3, -1, -2}, min + max = -3 + 7 = 4
     Sum of all min & max = 6 + 4 + 4 + 4
                          = 18
 *
 * */

#include <bits/stdc++.h>
using namespace std;

int main(int argc, char **argv) {
  vector<int> a = {2, 5, -1, 7, -3, -1, -2};
  int k = 4;  // window size;
  int sum = 0;
  int n = a.size();
  deque<int> sQ(k), gQ(k);
  int i = 0;
  for (i = 0; i < k; i++) {
    while (!(sQ.empty()) && a[sQ.back()] >= a[i]) {
      sQ.pop_back();
    }

    while (!(gQ.empty()) && a[gQ.back()] <= a[i]) {
      gQ.pop_back();
    }
    sQ.push_back(i);
    gQ.push_back(i);
  }

  for (; i < n; i++) {
    sum += a[sQ.front()] + a[gQ.front()];

    while (!(sQ.empty()) && sQ.front() <= i - k) {
      sQ.pop_front();
    }

    while (!(gQ.empty()) && gQ.front() <= i - k) {
      gQ.pop_front();
    }

    while (!(sQ.empty()) && a[sQ.back()] >= a[i]) {
      sQ.pop_back();
    }

    while (!(gQ.empty()) && a[gQ.back()] <= a[i]) {
      gQ.pop_back();
    }
    sQ.push_back(i);
    gQ.push_back(i);
  }

  sum += a[sQ.front()] + a[gQ.front()];

  cout << "\n sum = " << sum << endl;

  return 0;
}
