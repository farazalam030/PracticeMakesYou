/*
Reverse Bits
Given a 32 bit number x, reverse its binary form and print the answer in
decimal.

Input:
The first line of input consists T denoting the number of test cases. T
testcases follow. Each test case contains a single 32 bit integer

Output:
For each test case, in a new line, print the reverse of integer.

Constraints:
1 <= T <= 100
0 <= x <= 4294967295

Example:
Input:
2
1
5
Output:
2147483648
2684354560
4294967295‬

Explanation:
Testcase1:
00000000000000000000000000000001 =1
10000000000000000000000000000000 =2147483648
*/

#include <bits/stdc++.h>
using namespace std;

unsigned int reverseBits_naive(unsigned int n) {
  unsigned int ans = 0;
  unsigned int shiftsz = sizeof(unsigned int) * 8 - 1;
  while (n && shiftsz >= 0) {
    if (n & 1) {
      ans = ans | (1 << shiftsz);
    }
    n = n >> 1;
    shiftsz--;
  }
  return ans;
}

unsigned int reverseBits_fastLookUp(unsigned int n) {
  unsigned int lookup[256] = {
      0x0,  0x80, 0x40, 0xc0, 0x20, 0xa0, 0x60, 0xe0, 0x10, 0x90, 0x50, 0xd0,
      0x30, 0xb0, 0x70, 0xf0, 0x8,  0x88, 0x48, 0xc8, 0x28, 0xa8, 0x68, 0xe8,
      0x18, 0x98, 0x58, 0xd8, 0x38, 0xb8, 0x78, 0xf8, 0x4,  0x84, 0x44, 0xc4,
      0x24, 0xa4, 0x64, 0xe4, 0x14, 0x94, 0x54, 0xd4, 0x34, 0xb4, 0x74, 0xf4,
      0xc,  0x8c, 0x4c, 0xcc, 0x2c, 0xac, 0x6c, 0xec, 0x1c, 0x9c, 0x5c, 0xdc,
      0x3c, 0xbc, 0x7c, 0xfc, 0x2,  0x82, 0x42, 0xc2, 0x22, 0xa2, 0x62, 0xe2,
      0x12, 0x92, 0x52, 0xd2, 0x32, 0xb2, 0x72, 0xf2, 0xa,  0x8a, 0x4a, 0xca,
      0x2a, 0xaa, 0x6a, 0xea, 0x1a, 0x9a, 0x5a, 0xda, 0x3a, 0xba, 0x7a, 0xfa,
      0x6,  0x86, 0x46, 0xc6, 0x26, 0xa6, 0x66, 0xe6, 0x16, 0x96, 0x56, 0xd6,
      0x36, 0xb6, 0x76, 0xf6, 0xe,  0x8e, 0x4e, 0xce, 0x2e, 0xae, 0x6e, 0xee,
      0x1e, 0x9e, 0x5e, 0xde, 0x3e, 0xbe, 0x7e, 0xfe, 0x1,  0x81, 0x41, 0xc1,
      0x21, 0xa1, 0x61, 0xe1, 0x11, 0x91, 0x51, 0xd1, 0x31, 0xb1, 0x71, 0xf1,
      0x9,  0x89, 0x49, 0xc9, 0x29, 0xa9, 0x69, 0xe9, 0x19, 0x99, 0x59, 0xd9,
      0x39, 0xb9, 0x79, 0xf9, 0x5,  0x85, 0x45, 0xc5, 0x25, 0xa5, 0x65, 0xe5,
      0x15, 0x95, 0x55, 0xd5, 0x35, 0xb5, 0x75, 0xf5, 0xd,  0x8d, 0x4d, 0xcd,
      0x2d, 0xad, 0x6d, 0xed, 0x1d, 0x9d, 0x5d, 0xdd, 0x3d, 0xbd, 0x7d, 0xfd,
      0x3,  0x83, 0x43, 0xc3, 0x23, 0xa3, 0x63, 0xe3, 0x13, 0x93, 0x53, 0xd3,
      0x33, 0xb3, 0x73, 0xf3, 0xb,  0x8b, 0x4b, 0xcb, 0x2b, 0xab, 0x6b, 0xeb,
      0x1b, 0x9b, 0x5b, 0xdb, 0x3b, 0xbb, 0x7b, 0xfb, 0x7,  0x87, 0x47, 0xc7,
      0x27, 0xa7, 0x67, 0xe7, 0x17, 0x97, 0x57, 0xd7, 0x37, 0xb7, 0x77, 0xf7,
      0xf,  0x8f, 0x4f, 0xcf, 0x2f, 0xaf, 0x6f, 0xef, 0x1f, 0x9f, 0x5f, 0xdf,
      0x3f, 0xbf, 0x7f, 0xff};

  unsigned int ret = 0;
  ret = ((lookup[n & 0xff]) << 24) | ((lookup[(n >> 8) & 0xff]) << 16) |
        ((lookup[(n >> 16) & 0xff]) << 8) | ((lookup[(n >> 24) & 0xff]));

  return ret;
}

int main(int argc, char const *argv[]) {

  unsigned int n = 1;

  while (n) {
    cin >> n;
    unsigned int nn = n;
    unsigned int ans = reverseBits_naive(n);
    cout << hex << "num = " << nn << "\n ans = " << ans << endl;
#if 0
    cout << "unsigned int lookuptable[256] = {";
    for (int i = 0; i <= 255; i++) {
      cout << hex << "0x" << (reverseBits_naive(i) >> 24);
      if (i != 255)
        cout << ", ";
      //   cout << hex << "0x" << (i) << " -> 0x" << reverseBits_naive(i) << "\n
      //   ";
    }
    cout << "};" << endl;
#endif
    unsigned int retr = (unsigned int)reverseBits_fastLookUp(n);
    cout << hex << "lookup_ans = 0x" << retr << endl;
  }
  return 0;
}
