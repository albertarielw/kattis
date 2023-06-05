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

#define LSOne(S) ((S) & -(S)) 

#define isOn(S, j) (S & (1<<j))
#define setBit(S, j) (S |= (1<<j))
#define clearBit(S, j) (S &= ~(1<<j))
#define toggleBit(S, j) (S ^= (1<<j))
#define lowBit(S) (S & (-S))
#define setAll(S, n) (S = (1<<n)-1)

#define modulo(S, N) ((S) & (N-1))   // returns S % N, where N is a power of 2
#define isPowerOfTwo(S) (!(S & (S-1)))
#define nearestPowerOfTwo(S) (1<<lround(log2(S)))
#define turnOffLastBit(S) ((S) & (S-1))
#define turnOnLastZero(S) ((S) | (S+1))
#define turnOffLastConsecutiveBits(S) ((S) & (S+1))
#define turnOnLastConsecutiveZeroes(S) ((S) | (S-1))

void printSet(int vS) {                         // in binary representation
  printf("S = %2d = ", vS);
  stack<int> st;
  while (vS)
    st.push(vS%2), vS /= 2;
  while (!st.empty())                         // to reverse the print order
    printf("%d", st.top()), st.pop();
  printf("\n");
}

int f(int initial, int &target, vector<vector<string> > &AL, unordered_map<int, int> &memo, unordered_map<string, int> &price) {
  if (memo.find(initial) != memo.end()) {
    return memo[initial];
  }

  if (initial == target) {
    return 0;
  }

  int save = initial;
  int idx;
  for (int i = 0; i < 10; ++i) {
    if (!isOn(save, i)) {
      idx = i;
      break;
    }
  }
  // cout << idx << endl;
  // printSet()

  int res = INT_MAX;
  for (auto &cat: AL[idx]) {
    int newInitial = save;
    for (auto &c: cat) {
      setBit(newInitial, c - 'a');
    }
    // cout << cat << " : ";
    // printSet(newInitial);
    res = min(res, price[cat] + f(newInitial, target, AL, memo, price));
  }
  memo[save] = res;
  return res;
  // return 0;
}


int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(NULL);

  int N; cin >> N;
  int cost; string cat;

  unordered_map<string, int> price;
  vector<vector<string> > AL(10, vector<string>());
  unordered_map<int, int> memo;
  int target = 0, initial;
  for (int i = 0; i < 10; ++i) {
    setBit(target, i);
  }
  initial = target;

  // set<char> s;

  for (int i = 0; i < N; ++i) {
    cin >> cost >> cat;
    if (price.find(cat) != price.end()) {
      if (cost < price[cat]) {
        price[cat] = cost;
      }
    } else {
      price[cat] = cost;
    }
    
    
    for (auto &c: cat) {
      AL[c - 'a'].push_back(cat);
      if (isOn(initial, c - 'a')) {
        toggleBit(initial, c - 'a');
      }
      // s.insert(c);
    }
  }

  // cout << s.size();
  // cout << endl;

  // printSet(target);
  // printSet(initial);

  // for (int i = 0; i < AL.size(); ++i) {
  //   char c = ('a' + i);
  //   cout << (c) << " : ";
  //   for (auto &s: AL[i]) {
  //     cout << s << " ";
  //   }
  //   cout << endl;
  // }

  // for (auto &[k, v]: price) {
  //   cout << k << " " << v << endl;
  // }
  cout << f(initial, target, AL, memo, price);
  return 0;
}