#include <iostream>
#include <sstream>
#include <algorithm> // max/min_element O(N), upper/lower_bound O(Log N), sort/partial_sort, find O(N), fill, swap
#include <numeric> // for accumulate
#include <vector> // begin, end, empty, size, V1.swap(V2) O(1), erase(it) O(K), insert(it, val) 
#include <string.h> // memset(V, val, sizeof(V))
#include <string> // stoi
#include <list> // begin, end, empty, erase, size, insert(it, val), push_back/front, pop_back/front
#include <stack> // push, top, size, empty, pop
#include <queue> // push, front, back, size, empty, pop PQ: top
#include <deque> // push_front/back, pop_front/back, []
#include <map>  // begin, end, size. find, COUNT O(Log N)
#include <unordered_map> // find O(1), COUNT O(N)
#include <set> // begin, end, size. find, COUNT O(Log N)
#include <unordered_set>// find O(1), COUNT O(N)
#include <tuple> // get<i>(T)
#include <limits.h>
#include <iomanip>
// #include <bits/stdc++.h>
using namespace std;

typedef long long ll;

int depth = 0;
int seq(vector<int> V) {
  bool allSame = true;
  for (int i = 1; i < V.size(); ++i) {
    if (V[0] != V[i]) {
      allSame = false;
      break;
    }
  }

  if (allSame) {
    return V[0];
  }

  vector<int> newV;
  for (int i = 1; i < V.size(); ++i) {
    newV.push_back(V[i] - V[i - 1]);
  } 

  depth++;
  return V[V.size() - 1] + seq(newV);
}


int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(NULL);

  int n; cin >> n;
  vector<int> V(n);
  for (int i = 0; i < n; ++i) {
    cin >> V[i];
  }
  int ans = seq(V);
  cout << depth <<  " " << ans;
}