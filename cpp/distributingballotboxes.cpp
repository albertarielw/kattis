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

class Compare
{
public:
    bool operator() (pair<ll, ll> &A, pair<ll, ll> &B)
    {
      return A.first * B.second < B.first * A.second;
    }
};

int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(NULL);

  ll N, M, K;
  while (true) {
    cin >> N >> M;
    if (N == -1 and M == -1) {
      break;
    }

    priority_queue<pair<ll, ll>, vector<pair<ll, ll > >, Compare> PQ;
    for (int i = 0; i < N; ++i) {
      cin >> K; PQ.push(make_pair(K, 1));
    }

    M -= N;
    while (M--) {
      auto div = PQ.top(); PQ.pop();
      div.second++;
      PQ.push(div);
    }

    ll p = PQ.top().first, b = PQ.top().second;
    if (p % b == 0) {
      cout << (p / b) << endl;
    } else {
      cout << (p / b + 1) << endl;
    }

    //cout << (PQ.top().first / PQ.top().second) << "\n";


  }

}
