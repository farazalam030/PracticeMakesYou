
// priority_queue::emplace
#include <bits/stdc++.h>
using namespace std;
void hashingUtil(vector<int> &a, map<int, int> &mp) {
  for (auto i : a) {
    if (mp.find(i) == mp.end()) {
      mp[i] = 1;
    } else
      mp[i]++;
  }
}

// bool Mycompare(int l, int r) {}

void displayMap(map<int, pair<int, bool>> &oldMAp, bool flag, bool all) {
  for (auto i : oldMAp) {
    if ((!(i.second.second) ^ flag) || all)
      cout << "{" << i.first << "-->" << (bool)(i.second.second) << "} ";
  }
  cout << endl;
}
int main() {
  vector<int> a; //{1, 5, 4, 3, 2, 6};
  for (int i = 1; i <= 20; i++) {
    a.push_back(i);
  }

  map<int, pair<int, bool>> oldMAp;
  for (auto i : a) {
    oldMAp[i] = {i, false};
  }

  for (auto i = oldMAp.begin(); i != oldMAp.end(); i++) {
    if (i->first & 0x1) {
      i->second.second = true;
    }
  }

  for (auto i = oldMAp.begin(); i != oldMAp.end(); i++) {
    if (i->second.second) {
      oldMAp.erase(i);
    }
  }

  // displayMap(oldMAp, true, false);
  // cout << "-------------------------------------" << endl;
  // displayMap(oldMAp, false, false);
  cout << "\n-----------------All "
          "keys---------------------------------------------------------"
       << endl;
  displayMap(oldMAp, false, true);



  return 0;
}
