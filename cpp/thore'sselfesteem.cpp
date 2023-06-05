#include <bits/stdc++.h>
using namespace std;

const int MAX_N = 105;
string arr[MAX_N], s;
int N, R;

int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(NULL);

  s = "ThoreHusfeldt";
  cin >> N;
  for (int i = 0; i < N; ++i) {
    cin >> arr[i];
    if (arr[i] == "ThoreHusfeldt") {
      R = i;
    }
  }
  
  if (R == 0) {
    cout << "Thore is awesome";
    return 0;
  } 

  for (int i = 0; i < R; ++i) {
    if (arr[i].find("ThoreHusfeld") == 0) {
      cout << "Thore sucks";
      return 0;
    }
  }

  for (int i = 1; i <= s.length(); ++i) {
    string substring = s.substr(0, i);
    // cout << substring << endl;
    bool found = false;
    for (int i = 0; i < R; ++i) {
      if (arr[i].find(substring) == 0) {
        found = true;
        break;
      }
    }

    if (!found) {
      cout << substring;
      return 0;
    }
  }
}