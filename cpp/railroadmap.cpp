#include <bits/stdc++.h>
using namespace std;

typedef vector<int> vi;
typedef vector<pair<int, int> > vp;
typedef vector<vector<pair<int, int> > > vpp;

int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(NULL);

  int TC, N, M, a, b, c; cin >> TC;
  int prev, next, prevSum, nextSum, poss1, poss2;
  while (TC--) {
    cin >> N >> M;
    vpp AL(N + 1, vp());
    vector<vi> EL, EL2;
    for (int i = 1; i <= M; ++i) {
      cin >> a >> b >> c;
      AL[a].emplace_back(b, c);
      AL[b].emplace_back(a, c);
      EL.push_back({a, b, c});
    } 

    unordered_set<int> start, removed;
    for (int i = 1; i <= N; ++i) {
      if (AL[i].size() == 2) {
        prev = AL[i][0].first;

        next = AL[i][1].first;

        if (AL[prev].size() != 2 or AL[next].size() != 2) {
          start.insert(i);
        }
        removed.insert(i);
      }
    }

    vector<vector<int> > chains;
    while (!start.empty()) {
      int i = *(start.begin());
      prev = AL[i][0].first;
      prevSum = AL[i][0].second;
      next = AL[i][1].first;
      nextSum = AL[i][1].second;
      start.erase(i);
      start.erase(prev);
      start.erase(next);

      if (AL[next].size() != 2) {
        swap(prev, next);
        swap(prevSum, nextSum);
      }

      int startNode = prev, sum = prevSum, endNode;
      // chain.push_back(prev);
      // chain.push_back(i);
      while (AL[i].size() == 2) {
        start.erase(i);
        poss1 = AL[i][0].first;
        prevSum = AL[i][0].second;
        poss2 = AL[i][1].first;
        nextSum = AL[i][1].second;
        if (poss1 != prev) {
          swap(poss1, poss2);
          swap(prevSum, nextSum);
        }
        prev = poss1;
        next = poss2;
        start.erase(i);
        start.erase(next);
        sum += nextSum;
        prev = i;
        i = next;
      }
      endNode = next;
      start.erase(next);
      EL.push_back({startNode, endNode, sum});
    }

    for (auto &edge: EL) {
      if (removed.count(edge[0]) or removed.count(edge[1])) {
        continue;
      }
      EL2.push_back(edge);
    }

    cout << EL2.size() << "\n";
    for (auto &edge: EL2) {
      cout << edge[0] << " " << edge[1] << " " << edge[2] << "\n";
    }
    cout << "\n";

  }
}