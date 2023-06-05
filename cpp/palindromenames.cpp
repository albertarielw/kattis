#include <bits/stdc++.h>
using namespace std;


/*
ababab
012345
0 2 4
i = 0, len = 2

*/

string s, L, R;

int ans = INT_MAX, curr;

// abcde
// 012

void f() {
  for (int i = s.length() / 2; i < s.length(); ++i) {
    
    L = s.substr(0, i);
    reverse(L.begin(), L.end());
    R = s.substr(i, s.length());
    if (R.length() <= L.length()) {
      while (R.length() < L.length()) {
        R += "$";
      }
      curr = 0;
      for (int j = 0; j < L.length(); ++j) {
        if (R[j] != L[j]) {
          curr++;
        }
      }
      ans = min(ans, curr);
      // cout << L << " " << R << " " << curr << endl;
    }

    
    R = s.substr(i + 1, s.length());
    while (R.length() < L.length()) {
      R += "$";
    }
    curr = 0;
    for (int j = 0; j < L.length(); ++j) {
      if (R[j] != L[j]) {
        curr++;
      }
    }
    // cout << L << " " << R << " " << curr << endl;
    ans = min(ans, curr);
  }
}

int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(NULL);

  cin >> s;
  if (s.length() == 1) {
    cout << 0;
    return 0;
  }

  f();
  // reverse(s.begin(), s.end());
  // f();
  cout << ans;
}