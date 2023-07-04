#include <bits/stdc++.h>
using namespace std;

int main(int argc, char **argv) {
  string a = "baaabbaabbba";
  int n = a.size();
  int cA = 0;
  int cB = 0;
  string r = "";
  for (int i = 0; i < (n); ++i) {
    if (a[i] == 'a') {
      r = r + "a";
      cA = 1;
      while (a[i] == a[i + 1] && a[i] != NULL) {
        cA++;
        i++;
      }
      r = r + to_string(cA);
    }
    if (a[i] == 'b') {
      r = r + "b";
      cB = 1;
      while (a[i] == a[i + 1] && a[i] != NULL) {
        cB++;
        i++;
      }
      r = r + to_string(cB);
    }
  }

  cout << r << endl;
  return 0;
}
