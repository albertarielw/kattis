// #include <bits/stdc++.h>
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
/* // 5.2 Ad Hoc

1. Finding pattern or formula
Find number of square integers < N, lower(sqr(N - 1))

2. Base Conversion
– C/C++:
    int v; scanf("%o", &v); // read v in octal
    bitset<32> bin(v); // use bitset
    printf("%s\n", bin.to_string().c_str()); // print in binary
– Python: print("{0:b}".format(int(str(input()), 8))) # octal to binary
- Java
import java.util.Scanner;
import java.math.BigInteger;

class Main {
  public static void main(String[] args) {
    Scanner sc = new Scanner(System.in);         // a few test cases
    while (true) {
      int b = sc.nextInt(); if (b == 0) break;
      BigInteger p = new BigInteger(sc.next(), b); // 2nd parameter
      BigInteger m = new BigInteger(sc.next(), b); // is the base
      System.out.println((p.mod(m)).toString(b)); // print in base b
    }
  }
}

3. Number Systems or Sequences
AP:
Un = a + (a + d) + (a + 2d) + ... + (n - 1)d = a + (n - 1)d
Sn = n * (2a + (n - 1)d) / 2

GP:
Un = a + ar + ar^2 + ... + ar^(n - 1) = a * r^(n - 1)
Sn = a (r ^ n - 1) / (r - 1)


4. Logarithm, Exponentiation or Power
C++: log(a) (badr e), log2(a), log10(a)
Python: log(a, base), log2(a), log10(a)

Tricks:
-log(a) in base(b) = log(a) / lob(b)
-Number of digits in decimals: (int) floor(1 + log10((double) a)), 
-Number of digits in base b: (int) floor(1 + log10((double) a) / log10((double) b))
-a^(1/n) = pow((double) a, 1.0 / (double) n) or exp(log((double) a) * 1.0 / (double) n)

5. Grid
Grid maybe complex but follows primitve rules

6. Polynomial
Represent by storing coefficients (ordered by power)

7. Fraction
Simplify by dividing by GCD
Python:
from fractions import Fraction # Python’s built in
N = int(input())
for _ in range(N):
  frac = Fraction("".join(input().split(" "))) # simplified form
  print(str(frac.numerator) + " / " + str(frac.denominator))

Java:
// 0.212s in Java

import java.util.Scanner;
import java.math.BigInteger;

class Main {
  public static void main(String[] args) {
    Scanner sc = new Scanner(System.in);
    int N = sc.nextInt();
    while (N-- > 0) {                            // we have to use > 0
      BigInteger p = sc.nextBigInteger();
      String ch = sc.next();                     // ignore this char
      BigInteger q = sc.nextBigInteger();
      BigInteger gcd_pq = p.gcd(q);              // wow :)
      System.out.println(p.divide(gcd_pq) + " / " + q.divide(gcd_pq));
    }
  }
}
*/

int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(NULL);

  ll TC, N, M, sumN, sumM, k;
  cin >> TC;
  while (TC--) {
    cin >> N >> M; 
    sumN = 0;
    vector<ll> A(N);
    for (int i = 0; i < N; ++i) {
      cin >> A[i];
      sumN += A[i];
    }

    vector<ll> toCheck;
    for (auto &i: A) {
      if (i * N < sumN) {
        toCheck.push_back(i);
      }
    }

    sumM = 0;
    for (int i = 0; i < M; ++i) {
      cin >> k;
      sumM += k;
    }

    int count = 0;
    for (auto &i: toCheck) {
      if (i * M > sumM) {
        count++;
      }
    }
    cout << count << "\n";
  }
}