#include <bits/stdc++.h>

using namespace std;

// vector<string> split_string(string);

// Complete the minimumBribes function below.
void minimumBribes(vector<int> q) {
  int n = q.size();
  int bribes = 0;
  int bribePerPerson;
  for (int i = 0; i < n; i++) {
    if (q[i] - i - 1 > 2) {
      cout << "Too chaotic\n";
      return;
    }
    for (int j = q[i] - 2; j < i; j++) {
      if (q[j] > q[i]) bribes++;
    }
  }

  cout << bribes << "\n";
}

int main() {
  int t;

  vector<int> q{2, 1, 5, 3, 4};

  minimumBribes(q);

  return 0;
}
#if 0
vector<string> split_string(string input_string) {
    string::iterator new_end = unique(input_string.begin(), input_string.end(), [] (const char &x, const char &y) {
        return x == y and x == ' ';
    });

    input_string.erase(new_end, input_string.end());

    while (input_string[input_string.length() - 1] == ' ') {
        input_string.pop_back();
    }

    vector<string> splits;
    char delimiter = ' ';

    size_t i = 0;
    size_t pos = input_string.find(delimiter);

    while (pos != string::npos) {
        splits.push_back(input_string.substr(i, pos - i));

        i = pos + 1;
        pos = input_string.find(delimiter, i);
    }

    splits.push_back(input_string.substr(i, min(pos, input_string.length()) - i + 1));

    return splits;
}
#endif
