/*


Max length chainSubmissions: 22568   Accuracy: 43.55%   Difficulty: Medium  
Marks: 4
        

Problems
You are given N pairs of numbers. In every pair, the first number is always
smaller than the second number. A pair (c, d) can follow another pair (a, b) if
b < c. Chain of pairs can be formed in this fashion. Your task is to complete
the function maxChainLen which returns an integer denoting the longest chain
which can be formed from a given set of pairs.

Input:
The first line of input contains an integer T denoting the no of test cases then
T test cases follow .Then T test cases follow . The first line of input contains
an integer N denoting the no of pairs . In the next line are 2*N space separated
values denoting N pairs.

Output:
For each test case output will be the length of the longest chain formed.

Constraints:
1<=T<=100
1<=N<=100

Example(To be used only for expected output):
Input
2
5
5  24 39 60 15 28 27 40 50 90
2
5 10 1 11

Output
3
1
​
Explanation
(i) the given pairs are {{5, 24}, {39, 60}, {15, 28}, {27, 40}, {50, 90} },the
longest chain that can be formed is of length 3, and the chain is {{5, 24}, {27,
40}, {50, 90}} (ii) The max length chain possible is only of length one.


Note:The Input/Ouput format and Example given are used for system's internal
purpose, and should be used by a user for Expected Output only. As it is a
function problem, hence a user should not read any input from stdin/console. The
task is to complete the function specified, and not to write the full code.

** For More Input/Output Examples Use 'Expected Output' option **


*/

#include <bits/stdc++.h>
using namespace std;

int main(int argc, const char **argv) {
  int a[10] = {5, 24, 39, 60, 15, 28, 27, 40, 50, 90};
  sort(a, a + 10);
  for (auto i : a)
    cout << i << ", ";
  cout << endl;
  return 0;
}