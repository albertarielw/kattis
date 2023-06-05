#include <bits/stdc++.h>
using namespace std;

string s;

/*
ababab
012345
0 2 4
i = 0, len = 2

*/

int f() {
  for (int len = 1; len <= s.length(); ++len) {
    if (s.length() % len != 0) {
      continue;
    }
    string toCheck = s.substr(0, len);
    bool found = true;
    for (int idx = 0; idx < s.length(); idx += len) {
      if (toCheck != s.substr(idx, len)) {
        found = false;
        break;
      }
    }
    if (found) {
      return s.length() / len;
    }
  }
  return 1;
}

int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(NULL);

  while (getline(cin, s)) {
    if (s == ".") {
      break;
    }
    cout << f() << endl;
  }

}