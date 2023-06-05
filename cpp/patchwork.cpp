#include <bits/stdc++.h>
using namespace std;

int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(NULL);

  int R, C; cin >> R >> C;
  vector<vector<char> > canvas(R, vector<char>(C, '.'));
  int N, r, c; cin >> N;
  vector<vector<vector<char> > > patterns(N + 5);
  for (int k = 1; k <= N; ++k) {
    cin >> r >> c;
    vector<vector<char> > newPattern(r, vector<char>(c, '.'));
    for (int i = 0; i < r; ++i) {
      for (int j = 0; j < c; ++j) {
        cin >> newPattern[i][j];
      }
    }
    patterns[k] = (newPattern);
  }
  int K, T; cin >> K;
  while (K--) {
    cin >> r >> c >> T;
    auto &p = patterns[T];
    for (int i = 0; i < p.size(); ++i) {
      for (int j = 0; j < p[0].size(); ++j) {
        if (r + i >= R or c + j >= C) {
          continue;
        }
        canvas[r + i][c + j] = p[i][j];
      }
    }
  }

  for (int i = 0; i < R; ++i) {
    for (int j = 0; j < C; ++j) {
      cout << canvas[i][j];
    }
    cout << endl;
  }


}