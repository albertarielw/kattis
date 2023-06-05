#include <bits/stdc++.h>
using namespace std;

int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(NULL);

  string s;
  vector<int> V(26, 0);
  cin >> s;
  for (auto &i: s) {
    V[i - 'a']++;
  }
  int numOdds = 0;
  for (auto &i: V) {
    if (i % 2 == 1) {
      numOdds++;
    }
  }
  if (numOdds <= 1) {
    cout << 0;
  } else {
    cout << (numOdds - 1);
  }
}
