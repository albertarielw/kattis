#include <bits/stdc++.h>
using namespace std;

const int MAX_N = 100010;
int C[MAX_N][26], N;
string s;

void init() {
  for (int i = 0; i < N; ++i) {
    C[i][s[i] - 'a'] = 1;
    for (int j = 0; j < 26; ++j) {
      if (i > 0) {
        C[i][j] += C[i - 1][j];
      }
    }
    

  }
}

bool solve(int n) {
  vector<int> check(26);
  // cout << n << endl;
  for (int i = 0; i < 26; ++i) {
    check[i] = C[n - 1][i];
    // cout << check[i] << " ";
  }
  // cout << endl;
  int prev, val;
  for (int i = n - 1 + n; i < N; i += n) {
    prev = i - n;
    for (int j = 0; j < 26; ++j) {
      val = C[i][j] - C[prev][j];
      if (val != check[j]) {
        return false;
      }
    }
  }
  return true;
}

int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(NULL);

  cin >> s;
  if (s.length() % 2) {
    cout << -1;
    return 0;
  } 
  N = s.length();

  init();
  // for (int i = 0; i )

  int granularity = 1;
  bool found = false;
  while (true) {
    if (granularity > (s.length() / 2)) {
      break;
    }
    if (s.length() % granularity != 0) {
      granularity++;
      continue;
    }

    if (solve(granularity)) {
      // cout << "FOUND";
      // cout << granularity << endl;
      found = true;
      break;
    }
    granularity++;
  }

  if (found) {
    // cout << granularity << endl;
    cout << s.substr(0, granularity);
  } else {
    cout << -1;
  }

}