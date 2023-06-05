#include <bits/stdc++.h>
using namespace std;

typedef pair<int, int> ii;

int area(ii &A, ii &B, ii &C) {
  int x1 = A.first, y1 = A.second, x2 = B.first, y2 = B.second, x3 = C.first, y3 = C.second;
  return abs((x1*(y2-y3) + x2*(y3-y1) + x3*(y1-y2)));
}

unordered_map<int, double> VAL;

bool cmp(const ii &a, const ii &b) {
  if (a.second != b.second) {
    return a.second < b.second;
  }
  return a.first < b.first;
}

int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(NULL);

  int N, M; cin >> N >> M;
  double a, b;
  vector<ii> V(N + 1);
  vector<bool> removed(N + 1, false);
  for (int i = 0; i <= N; ++i) {
    cin >> a >> b;
    V[i] = make_pair(a, b);
  }

  set<ii, decltype(&cmp)> s(&cmp);
  for (int i = 1; i < N; ++i) {
    VAL[i] = area(V[i - 1], V[i], V[i + 1]);
    s.insert(make_pair(i, VAL[i]));
  }
  // for (auto &k: s) {
  //   cout << k << " " << VAL[k] << ", ";
  // }
  // cout << endl;
  
  for (int i = 0; i < (N - M); ++ i) {
    int index = (*s.begin()).first; s.erase(make_pair(index, VAL[index]));
    cout << index << endl;
    removed[index] = true;
    int left = index - 1;
    while (left > 0) {
      if (!removed[left]) {
        break;
      }
      left--;
    }
    
    int right = index + 1;
    while (right < N) {
      if (!removed[right]) {
        break;
      }
      right++;
    }

    // cout << left << " : ";
    if (left > 0 and !removed[left]) {
      s.erase(make_pair(left, VAL[left]));
      int leftLeft = left - 1;
      while (true) {
        if (!removed[leftLeft]) {
          break;
        }
        leftLeft--;
      }
      int rightRight = left + 1;
      while (true) {
        if (!removed[rightRight]) {
          break;
        }
        rightRight++;
      }
      VAL[left] = area(V[leftLeft], V[left], V[rightRight]);
      s.insert(make_pair(left, VAL[left]));
      // cout << leftLeft << " " << left << " " << rightRight;
    }
    // cout << endl;

    // cout << right << " : ";
    if (right < N and !removed[right]) {
      s.erase(make_pair(right, VAL[right]));
      int leftLeft = right - 1;
      while (true) {
        if (!removed[leftLeft]) {
          break;
        }
        leftLeft--;
      }
      int rightRight = right + 1;
      while (true) {
        if (!removed[rightRight]) {
          break;
        }
        rightRight++;
      }
      VAL[right] = area(V[leftLeft], V[right], V[rightRight]);
      s.insert(make_pair(right, VAL[right]));
      // cout << leftLeft << " " << right << " " << rightRight;
    }
    // cout << endl;
    // for (int i = 0; i < removed.size(); ++i) {
    //   cout << "(" << i << " " << (!removed[i] ? "Y" : "N") << ") ";
    // }
    // cout << endl;
    // for (auto &p: s) {
    //   cout << p.first << " " << p.second << ", ";
    // }
    // cout << endl;
  }
}