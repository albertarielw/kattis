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

int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(NULL);

  ll N, K, S; cin >> N >> K;
  vector<ll> houses(N + 1, -1);
  for (int i = 0; i < K; ++i) {
    cin >> S;
    houses[S] = S;
  }

  ll lastSafe = -1;
  for (int i = N; i >= 1; --i) {
    if (houses[i] == i) {
      lastSafe = i;
    } else {
      houses[i] = lastSafe;
    }
  }


  ll ans = 0;
  for (int i = 1; i <= N; ++i) {
    // cout << i << " ";
    ll possibleHouses = N - i;
    if (houses[i] == i) {
      possibleHouses++;
    }
    if (houses[i] == -1) {
      continue;
    }
    
    if (houses[i] == i or houses[i] == i + 1) {
      // cout << possibleHouses << endl;
      ans += possibleHouses;
    } else {
      ll unsafeHouses = houses[i] - i - 1;
      // cout << (possibleHouses - unsafeHouses) << endl;
      ans += possibleHouses - unsafeHouses;
    }
  }
  cout << ans;


}