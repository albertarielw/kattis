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
#include <cstdio>
#include <cmath>
using namespace std;

typedef long long ll;

int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(NULL);

  int N, T, c, t; cin >> N >> T;
  vector<int> V(T + 1, 0);
  priority_queue<pair<int, int> > pq;
  for (int i = 0; i < N; ++i) {
    cin >> c >> t;
    pq.push(make_pair(c, t));
  }

  while (!pq.empty()) {
    c = pq.top().first, t = pq.top().second; pq.pop();
    for (int i = t; i >= 0; --i) {
      if (V[i] == 0) {
        V[i] = c;
        break;
      }
    }
  }

  int ans = 0;
  for (auto &i: V) {
    ans += i;
  }
  cout << ans;

}
