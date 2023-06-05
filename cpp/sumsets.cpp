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
using namespace std;

typedef long long ll;

const int MAX_N = 4010;
ll nums[MAX_N];

int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(NULL);

  int N; cin >> N;
  if (N < 4) {
    cout << "no solution";
    return 0;
  }
  for (int i = 0; i < N; ++i) {
    cin >> nums[i];
  }
  unordered_map<ll, vector<pair<int, int> > > memo;
  for (int i = 0; i < N; ++i) {
    for (int j = i + 1; j < N; ++j) {
      if (i != j) {
        ll sum = nums[i] + nums[j];
        memo[sum].push_back(make_pair(i, j));
      }
    }
  }

  ll d = LLONG_MIN;
  ll lookFor, currD; 
  int i2, j2;
  for (int i = 0; i < N; ++i) {
    currD = nums[i];
    for (int j = 0; j < N; ++j) {
      if (i != j) {
        lookFor = currD - nums[j];
        bool found = false;
        if (memo.find(lookFor) != memo.end()) {
          for (auto &p: memo[lookFor]) {
            i2 = p.first, j2 = p.second;
            if (i2 != i and i2 != j and j2 != i and j2 != j) {
              d = max(d, currD);
              found = true;
              break;
            }
          }
        }
        if (found) {
          break;
        }
      }
    }
  }
  if (d == LLONG_MIN) {
    cout << "no solution";
  } else {
    cout << d;
  }
  

  return 0;
}
