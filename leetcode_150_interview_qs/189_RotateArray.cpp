/*

Given an integer array nums, rotate the array to the right by k steps, where k
is non-negative.



Example 1:

Input: nums = [1,2,3,4,5,6,7], k = 3
Output: [5,6,7,1,2,3,4]
Explanation:
rotate 1 steps to the right: [7,1,2,3,4,5,6]
rotate 2 steps to the right: [6,7,1,2,3,4,5]
rotate 3 steps to the right: [5,6,7,1,2,3,4]
Example 2:

Input: nums = [-1,-100,3,99], k = 2
Output: [3,99,-1,-100]
Explanation:
rotate 1 steps to the right: [99,-1,-100,3]
rotate 2 steps to the right: [3,99,-1,-100]


Constraints:

1 <= nums.length <= 105
-231 <= nums[i] <= 231 - 1
0 <= k <= 105


Follow up:

Try to come up with as many solutions as you can. There are at least three
different ways to solve this problem. Could you do it in-place with O(1) extra
space?
*/

#include <bits/stdc++.h>
using namespace std;

// 2 sols

class Solution {
public:
  void rotate_2(vector<int> &a, int k) {
    int n = a.size();
    k = k % n;
    vector<int> b(a.begin() + (n - k), a.end());
    for (int i = 0; i < n - k; i++) {
      b.push_back(a[i]);
    }
    for (int i = 0; i < n; i++) {
      a[i] = b[i];
    }
  }
  void rotate(vector<int> &nums, int k) {

    int n = nums.size();
    k = k % n;
    reverse(nums.begin(), nums.end() - k);
    reverse(nums.end() - k, nums.end());
    reverse(nums.begin(), nums.end());
  }
};
void printArray(vector<int> &a) {
  for (auto &i : a) {
    cout << i << " ";
  }
  cout << endl;
}
int main(int argc, char const *argv[]) {
  vector<int> a{1, 2, 3, 4, 5, 6, 7};
  int k = 3;
  Solution s;
  s.rotate(a, k);
  printArray(a);

  return 0;
}
