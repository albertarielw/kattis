#include <bits/stdc++.h>

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

// 5.3 Number Theory
/* 
// DONT FORGET TO sieve(10000000); 

typedef long long ll;
typedef vector<int> vi;
typedef vector<ll> vll;
typedef map<int, int> mii;

ll _sieve_size;
bitset<10000010> bs;                             // 10^7 is the rough limit
vll p;                                           // compact list of primes

void sieve(ll upperbound) {                      // range = [0..upperbound]
  _sieve_size = upperbound+1;                    // to include upperbound
  bs.set();                                      // all 1s
  bs[0] = bs[1] = 0;                             // except index 0+1
  for (ll i = 2; i < _sieve_size; ++i) if (bs[i]) {
    // cross out multiples of i starting from i*i
    for (ll j = i*i; j < _sieve_size; j += i) bs[j] = 0;
    p.push_back(i);                              // add prime i to the list
  }
}

bool isPrime(ll N) {                             // good enough prime test
  if (N < _sieve_size) return bs[N];             // O(1) for small primes
  for (int i = 0; i < (int)p.size() && p[i]*p[i] <= N; ++i)
    if (N%p[i] == 0)
      return false;
  return true;                                   // slow if N = large prime
} // note: only guaranteed to work for N <= (last prime in vll p)^2

// second part

vll primeFactors(ll N) {                         // pre-condition, N >= 1
  vll factors;
  for (int i = 0; i < (int)p.size() && p[i]*p[i] <= N; ++i)
    while (N%p[i] == 0) {                        // found a prime for N
      N /= p[i];                                 // remove it from N
      factors.push_back(p[i]);
    }
  if (N != 1) factors.push_back(N);              // remaining N is a prime
  return factors;
}

// third part

// count no. of prime factors eg 60 = 2 x 2 x 3 x 5 has 4
int numPF(ll N) {
  int ans = 0;
  for (int i = 0; i < (int)p.size() && p[i]*p[i] <= N; ++i)
    while (N%p[i] == 0) { N /= p[i]; ++ans; }
  return ans + (N != 1);
}


int numDiffPF(ll N) {
  int ans = 0;
  for (int i = 0; i < p.size() && p[i]*p[i] <= N; ++i) {
    if (N%p[i] == 0) ++ans;                      // count this prime factor
    while (N%p[i] == 0) N /= p[i];               // only once
  }
  if (N != 1) ++ans;
  return ans;
}


ll sumPF(ll N) {
  ll ans = 0;
  for (int i = 0; i < p.size() && p[i]*p[i] <= N; ++i)
    while (N%p[i] == 0) { N /= p[i]; ans += p[i]; }
  if (N != 1) ans += N;
  return ans;
}


// count no. of divisors of integer N eg 60 = {1,2,3,4,5,6,10,12,15,20,30,60} has 12
int numDiv(ll N) {
  int ans = 1;                                   // start from ans = 1
  for (int i = 0; i < (int)p.size() && p[i]*p[i] <= N; ++i) {
    int power = 0;                               // count the power
    while (N%p[i] == 0) { N /= p[i]; ++power; }
    ans *= power+1;                              // follow the formula
  }
  return (N != 1) ? 2*ans : ans;                 // last factor = N^1
}

// sum of divisors
ll sumDiv(ll N) {
  ll ans = 1;                                    // start from ans = 1
  for (int i = 0; i < (int)p.size() && p[i]*p[i] <= N; ++i) {
    ll multiplier = p[i], total = 1;
    while (N%p[i] == 0) {
      N /= p[i];
      total += multiplier;
      multiplier *= p[i];
    }                                            // total for
    ans *= total;                                // this prime factor
  }
  if (N != 1) ans *= (N+1);                      // N^2-1/N-1 = N+1
  return ans;
}

// count integers < N which are relative prime (gcd(a, b) == 1)
ll EulerPhi(ll N) {
  ll ans = N;                                    // start from ans = N
  for (int i = 0; i < (int)p.size() && p[i]*p[i] <= N; ++i) {
    if (N%p[i] == 0) ans -= ans/p[i];            // count unique
    while (N%p[i] == 0) N /= p[i];               // prime factor
  }
  if (N != 1) ans -= ans/N;                      // last factor
  return ans;
}

int main() {
  // first part: the Sieve of Eratosthenes
  sieve(10000000);                               // up to 10^7 (<1s)
  printf("%lld\n", p.back());               // primes.back() = 9999991
  for (int i = p.back()+1; ; ++i)
    if (isPrime(i)) {
      printf("The next prime beyond the last prime generated is %d\n", i);
      break;
    }
  printf("%d\n", isPrime((1LL<<31)-1));          // 8th Mersenne prime
  printf("%d\n", isPrime(136117223861LL));       // 104729*1299709
  printf("\n");

  // second part: prime factors
  vll r;

  r = primeFactors((1LL<<31)-1);                 // Mersenne prime
  printf("%lld\n", (1LL<<31)-1);
  for (auto &pf : r) printf("> %lld\n", pf);
  printf("\n");

  r = primeFactors(136117223861LL);              // large prime factors
  printf("%lld\n", 136117223861LL);
  for (auto &pf : r) printf("> %lld\n", pf);     // 104729*1299709
  printf("\n");

  r = primeFactors(5000000035LL);                // large prime factors
  printf("%lld\n", 5000000035LL);
  for (auto &pf : r) printf("> %lld\n", pf);     // 5*1000000007
  printf("\n");

  r = primeFactors(142391208960LL);              // large composite
  printf("%lld\n", 142391208960LL);
  for (auto &pf : r) printf("> %lld\n", pf);     // 2^10*3^4*5*7^4*11*13
  printf("\n");

  r = primeFactors(100000380000361LL);           // 10000019^2
  printf("%lld\n", 100000380000361LL);
  for (auto &pf : r) printf("> %lld\n", pf);     // fail to factor! (why?)
  printf("\n");

  
  // third part: functions involving prime factors
  printf("numPF(%d) = %d\n", 60, numPF(60));   // 2^2 * 3^1 * 5^1 => 4
  printf("numDiffPF(%d) = %d\n", 60, numDiffPF(60)); // 2^2 * 3^1 * 5^1 => 3
  printf("sumPF(%d) = %lld\n", 60, sumPF(60));   // 2^2 * 3^1 * 5^1 => 2 + 2 + 3 + 5 = 12
  printf("numDiv(%d) = %d\n", 60, numDiv(60)); // 1, 2, 3, 4, 5, 6, 10, 12, 15, 20, 30, 60, 12 divisors
  printf("sumDiv(%d) = %lld\n", 60, sumDiv(60)); // The summation of 12 divisors above is 168
  printf("EulerPhi(%d) = %lld\n", 36, EulerPhi(36)); // 12 integers < 36 are relatively prime with 36
  printf("\n");

  // special cases when N is a prime number
  printf("numPF(%d) = %d\n", 7, numPF(7));     // 7^1 => 1
  printf("numDiffPF(%d) = %d\n", 7, numDiffPF(7)); // 7^1 = 1
  printf("sumPF(%d) = %lld\n", 7, sumPF(7));     // 7^1 => 7
  printf("numDiv(%d) = %d\n", 7, numDiv(7));   // 1 and 7, 2 divisors
  printf("sumDiv(%d) = %lld\n", 7, sumDiv(7));   // 1 + 7 = 8
  printf("EulerPhi(%d) = %lld\n", 7, EulerPhi(7)); // 6 integers < 7 are relatively prime with prime number 7

  return 0;
}


// Probabilistic Prime Testing
// 2.788s in Java

import java.util.Scanner;
import java.math.BigInteger;

class Main {
  public static void main(String[] args) {
    Scanner sc = new Scanner(System.in);
    while (sc.hasNext()) {
      int N = sc.nextInt(); System.out.printf("%d is ", N);
      BigInteger BN = BigInteger.valueOf(N);
      String R = new StringBuffer(BN.toString()).reverse().toString();
      int RN = Integer.parseInt(R);
      BigInteger BRN = BigInteger.valueOf(RN);
      if (!BN.isProbablePrime(10))               // certainty 10 is enough
        System.out.println("not prime.");
      else if ((N != RN) && BRN.isProbablePrime(10))
        System.out.println("emirp.");
      else
        System.out.println("prime.");
    }
  }
}


*/

/* Modified Sieve (for large queries with large range)

int numDiffPFarr[MAX_N+10] = {0};         // e.g., MAX_N = 10^7
for (int i = 2; i <= MAX_N; ++i)
  if (numDiffPFarr[i] == 0)               // i is a prime number
    for (int j = i; j <= MAX_N; j += i)
      ++numDiffPFarr[j];                  // j is a multiple of i

int EulerPhi[MAX_N+10];
for (int i = 1; i <= MAX_N; ++i) EulerPhi[i] = i;
for (int i = 2; i <= MAX_N; ++i)
  if (EulerPhi[i] == i)                  // i is a prime number
    for (int j = i; j <= MAX_N; j += i)
       EulerPhi[j] = (EulerPhi[j]/i) * (i-1);
*/


/* GCD & LCM
int gcd(int a, int b) { return b == 0 ? a : gcd(b, a%b); }
int lcm(int a, int b) { return a / gcd(a, b) * b; }

gcd(a, b, c) = gcd(a, gcd(b, c))
*/

/* Module
((a % m) + m) % m --> ensures +ve modulo

1. (a+b)%m = ((a%m)+(b%m))%m
2. (a-b)%m = ((a%m)-(b%m))%m
3. (axb)%m = ((a%m)x(b%m))%m

(a/b)%m != ((a%m)/(b%m))%m
but
(a/b)%m = (axb^-1) % m

if m is prime:
((a % m)x(b^(m-2) % m)) % m

if m is not a prime but gcd(b, m) = 1
((a % m) ⇥ (b^(T(m) - 1) % m)) % m
T(m) = no. of integers < m which are relative prime to m

Using extended euclid algorithm:
If 25x + 18y = 839 what are x and y? use extended euclid algo


#include <bits/stdc++.h>
using namespace std;

int mod(int a, int m) {                          // returns a (mod m)
  return ((a%m) + m) % m;                        // ensure positive answer
}

// b^p % m (m must be prime)
int modPow(int b, int p, int m) {                // assume 0 <= b < m
  if (p == 0) return 1;
  int ans = modPow(b, p/2, m);                   // this is O(log p)
  ans = mod(ans*ans, m);                         // double it first
  if (p&1) ans = mod(ans*b, m);                  // *b if p is odd
  return ans;                                    // ans always in [0..m-1]
}

int extEuclid(int a, int b, int &x, int &y) {    // pass x and y by ref
  int xx = y = 0;
  int yy = x = 1;
  while (b) {                                    // repeats until b == 0
    int q = a/b;
    tie(a, b) = tuple(b, a%b);
    tie(x, xx) = tuple(xx, x-q*xx);
    tie(y, yy) = tuple(yy, y-q*yy);
  }
  return a;                                      // returns gcd(a, b)
}

int modInverse(int b, int m) {                   // returns b^(-1) (mod m)
  int x, y;
  int d = extEuclid(b, m, x, y);                 // to get b*x + m*y == d
  if (d != 1) return -1;                         // to indicate failure
  // b*x + m*y == 1, now apply (mod m) to get b*x == 1 (mod m)
  return mod(x, m);
}

int main() {
  // Fermat's little theorem, b^-1 = b^{m-2} (mod m)
  printf("%d\n", (27%7 * modPow(3, 5, 7)) % 7);  // example 1, output 2
  printf("%d\n", (27%7 * modPow(4, 5, 7)) % 7);  // example 2, output 5
  printf("%d\n", (520%18 * modPow(25, 16, 18)) % 18); // example 3, wrong answer, doesn't output 10 because 18 is not a prime

  // Using extEuclid
  printf("%d\n", (27%7 * modInverse(3, 7)) % 7); // example 1, output 2
  printf("%d\n", (27%7 * modInverse(4, 7)) % 7); // example 2, output 5
  printf("%d\n", (520%18 * modInverse(25, 18)) % 18); // example 3, output 10
  return 0;
}
*/

// 5.4 Combinatorics
/*
1. Fib
See formula for Fib below
Binet's Formula: Fn = (((1 + sqrt(5)) / 2)^n - ((1 - sqrt(5)) / 2)^n) / sqrt(5)

Zeckendorf’s theorem: every positive integer can be written in a unique way as a sum of
one or more distinct Fibonacci numbers such that the sum does not include any two consecutive 
Fibonacci numbers. For any given positive integer, a representation that satisfies Zeckendorf’s 
theorem can be found by using a Greedy algorithm: choose the largest possible Fibonacci 
number at each step

Another property is the Pisano Period where the last one/last two/last three/last four digit(s) of 
a Fibonacci number repeats with a period of 60/300/1 500/15 000, respectively.

2. Binom Coeff
See formula for C below

3. Catalan Numbers
See formula for Cat below



#include <bits/stdc++.h>
using namespace std;

typedef long long ll;

const int MAX_N = 100010;
const int p = 1e9+7;                             // p is a prime > MAX_N

ll mod(ll a, int m) {                            // returns a (mod m)
  return ((a%m) + m) % m;                        // ensure positive answer
}

ll modPow(ll b, int p, int m) {                  // assume 0 <= b < m
  if (p == 0) return 1;
  ll ans = modPow(b, p/2, m);                    // this is O(log p)
  ans = mod(ans*ans, m);                         // double it first
  if (p&1) ans = mod(ans*b, m);                  // *b if p is odd
  return ans;                                    // ans always in [0..m-1]
}

ll inv(ll a) {                                   // Fermat's little theorem
  return modPow(a, p-2, p);                      // modPow in Section 5.8
}                                                // that runs in O(log p)

ll fact[MAX_N], invFact[MAX_N];

ll C(int n, int k) {                             // O(log p)
  if (n < k) return 0;                           // clearly
  return (((fact[n] * inv(fact[k])) % p) * inv(fact[n-k])) % p;
  // return (((fact[n] * invFact[k]) % p) * invFact[n-k]) % p; // O(1)
}

ll Fib[MAX_N], Cat[MAX_N];

int main() {
  Fib[0] = 0;                                    // the first
  Fib[1] = 1;                                    // two terms of Fibonacci
  for (int i = 2; i < MAX_N; ++i)                // O(MAX_N) pre-processing
    Fib[i] = (Fib[i-1] + Fib[i-2]) % p;          // Fib[i] in [0..p-1]
  cout << Fib[100000] << "\n";                   // the answer is 911435502

  fact[0] = 1;
  for (int i = 1; i < MAX_N; ++i)                // O(MAX_N) pre-processing
    fact[i] = (fact[i-1]*i)% p;                  // fact[i] in [0..p-1]

  // invFact[MAX_N-1] = inv(fact[MAX_N-1]);         // one O(log p)
  // for (int i = MAX_N-2; i >= 0; --i)             // O(MAX_N) pre-processing
  //   invFact[i] = (invFact[i+1]*(i+1)) % p;
  cout << C(100000, 50000) << "\n";              // the answer is 149033233

  Cat[0] = 1;
  for (int n = 0; n < MAX_N-1; ++n)              // O(MAX_N * log p)
    Cat[n+1] = ((4*n+2)%p * Cat[n]%p * inv(n+2)) % p;
  cout << Cat[100000] << "\n";                   // the answer is 945729344

  return 0;
}
*/

// 5.5 Probability
/*
2 Possible solutions:
1. Closed form formula
2. Complete search/ DP (normally n <= 20)
Dearrangement Formula with DP: An = (n-1) x (An-1 + An-2)

Monty Hall
Stay: (NCARS/(NCARS + NCOWS))
Switch: ((NCARS - 1)/(NCARS + NCOW S - NSHOW - 1))
*/

// 5.6 Cycle Finding
/*

// Pseudo-Random Numbers

#include <bits/stdc++.h>
using namespace std;

typedef pair<int, int> ii;

int Z, I, M;

int f(int x) { return (Z*x + I) % M; }

ii floydCycleFinding(int x0) {                   // f(x) is defined above
  // 1st part: finding k*mu, hare h's speed is 2x tortoise t's
  int t = f(x0), h = f(f(x0));                   // f(x0) is after x0
  while (t != h) { t = f(t); h = f(f(h)); }
  // 2nd part: finding mu, hare h and tortoise t move at the same speed
  int mu = 0; h = x0;
  while (t != h) { t = f(t); h = f(h); ++mu; }
  // 3rd part: finding lambda, hare h moves, tortoise t stays
  int lambda = 1; h = f(t);
  while (t != h) { h = f(h); ++lambda; }
  return {mu, lambda}; // mu is smallest index and lambda is smallest length
}

int main() {
  freopen("in.txt", "r", stdin);
  int caseNo = 0, L;
  while (scanf("%d %d %d %d", &Z, &I, &M, &L), (Z || I || M || L)) {
    
    auto [mu, lambda] = floydCycleFinding(L);
    printf("Case %d: %d\n", ++caseNo, lambda);
    return 0;
  }
  return 0;
}
*/

// 5.7 Game Theory
/*
Decision Tree exploration with recrusive backtracking/ complete search/ DP
*/

// 5.8 Matrix
/*
1. Fib n
fib(p) = | 1 1 | p = | f
         | 1 0 |     | fib(p)

2. All paths of length k using AM^k

3. General formula

Given:
aXn+1 + bXn = Xn+2
aXb + bXn-1 = Xn+1

| a b |^n x | X1 | = | Xn+1 |
| 1 0 |     | X0 |   | Xn   |

Can be extended to 3x3, 4,4, ... nxn

// Modular Fibonacci

#include <bits/stdc++.h>
using namespace std;

typedef long long ll;

ll MOD;

const int MAX_N = 2;                             // 2x2 for Fib matrix

struct Matrix { ll mat[MAX_N][MAX_N]; };         // we return a 2D array

ll mod(ll a, ll m) { return ((a%m)+m) % m; }     // ensure positive answer

Matrix matMul(Matrix a, Matrix b) {              // normally O(n^3)
  Matrix ans;                                    // but O(1) as n = 2
  for (int i = 0; i < MAX_N; ++i)
    for (int j = 0; j < MAX_N; ++j)
      ans.mat[i][j] = 0;
  for (int i = 0; i < MAX_N; ++i)
    for (int k = 0; k < MAX_N; ++k) {
      if (a.mat[i][k] == 0) continue;            // optimization
      for (int j = 0; j < MAX_N; ++j) {
        ans.mat[i][j] += mod(a.mat[i][k], MOD) * mod(b.mat[k][j], MOD);
        ans.mat[i][j] = mod(ans.mat[i][j], MOD); // modular arithmetic
      }
    }
  return ans;
}

Matrix matPow(Matrix base, int p) {              // normally O(n^3 log p)
  Matrix ans;                                    // but O(log p) as n = 2
  for (int i = 0; i < MAX_N; ++i)
    for (int j = 0; j < MAX_N; ++j)
      ans.mat[i][j] = (i == j);                  // prepare identity matrix
  while (p) {                                    // iterative D&C version
    if (p&1)                                     // check if p is odd
      ans = matMul(ans, base);                   // update ans
    base = matMul(base, base);                   // square the base
    p >>= 1;                                     // divide p by 2
  }
  return ans;
}

int main() {
  int n, m;
  while (scanf("%d %d", &n, &m) == 2) {
    Matrix ans;                                  // Fibonaccci matrix
    ans.mat[0][0] = 1;  ans.mat[0][1] = 1;
    ans.mat[1][0] = 1;  ans.mat[1][1] = 0;
    MOD = 1;
    for (int i = 0; i < m; ++i)                  // set MOD = 2^m
      MOD *= 2;
    ans = matPow(ans, n);                        // O(log n) 
    printf("%lld\n", ans.mat[0][1]);             // this if fib(n) % MOD
  }
  return 0;
}
*/

typedef long long ll;
typedef vector<int> vi;
typedef vector<ll> vll;
typedef map<int, int> mii;

ll _sieve_size;
bitset<10000010> bs;                             // 10^7 is the rough limit
vll p;                                           // compact list of primes

void sieve(ll upperbound) {                      // range = [0..upperbound]
  _sieve_size = upperbound+1;                    // to include upperbound
  bs.set();                                      // all 1s
  bs[0] = bs[1] = 0;                             // except index 0+1
  for (ll i = 2; i < _sieve_size; ++i) if (bs[i]) {
    // cross out multiples of i starting from i*i
    for (ll j = i*i; j < _sieve_size; j += i) bs[j] = 0;
    p.push_back(i);                              // add prime i to the list
  }
}

bool isPrime(ll N) {                             // good enough prime test
  if (N < _sieve_size) return bs[N];             // O(1) for small primes
  for (int i = 0; i < (int)p.size() && p[i]*p[i] <= N; ++i)
    if (N%p[i] == 0)
      return false;
  return true;                                   // slow if N = large prime
} // note: only guaranteed to work for N <= (last prime in vll p)^2

// second part

vll primeFactors(ll N) {                         // pre-condition, N >= 1
  vll factors;
  for (int i = 0; i < (int)p.size() && p[i]*p[i] <= N; ++i)
    while (N%p[i] == 0) {                        // found a prime for N
      N /= p[i];                                 // remove it from N
      factors.push_back(p[i]);
    }
  if (N != 1) factors.push_back(N);              // remaining N is a prime
  return factors;
}

// third part

// count no. of prime factors eg 60 = 2 x 2 x 3 x 5 has 4
int numPF(ll N) {
  int ans = 0;
  for (int i = 0; i < (int)p.size() && p[i]*p[i] <= N; ++i)
    while (N%p[i] == 0) { N /= p[i]; ++ans; }
  return ans + (N != 1);
}


int numDiffPF(ll N) {
  int ans = 0;
  for (int i = 0; i < p.size() && p[i]*p[i] <= N; ++i) {
    if (N%p[i] == 0) ++ans;                      // count this prime factor
    while (N%p[i] == 0) N /= p[i];               // only once
  }
  if (N != 1) ++ans;
  return ans;
}


ll sumPF(ll N) {
  ll ans = 0;
  for (int i = 0; i < p.size() && p[i]*p[i] <= N; ++i)
    while (N%p[i] == 0) { N /= p[i]; ans += p[i]; }
  if (N != 1) ans += N;
  return ans;
}


// count no. of divisors of integer N eg 60 = {1,2,3,4,5,6,10,12,15,20,30,60} has 12
int numDiv(ll N) {
  int ans = 1;                                   // start from ans = 1
  for (int i = 0; i < (int)p.size() && p[i]*p[i] <= N; ++i) {
    int power = 0;                               // count the power
    while (N%p[i] == 0) { N /= p[i]; ++power; }
    ans *= power+1;                              // follow the formula
  }
  return (N != 1) ? 2*ans : ans;                 // last factor = N^1
}

// sum of divisors
ll sumDiv(ll N) {
  ll ans = 1;                                    // start from ans = 1
  for (int i = 0; i < (int)p.size() && p[i]*p[i] <= N; ++i) {
    ll multiplier = p[i], total = 1;
    while (N%p[i] == 0) {
      N /= p[i];
      total += multiplier;
      multiplier *= p[i];
    }                                            // total for
    ans *= total;                                // this prime factor
  }
  if (N != 1) ans *= (N+1);                      // N^2-1/N-1 = N+1
  return ans;
}

// count integers < N which are relative prime (gcd(a, b) == 1)
ll EulerPhi(ll N) {
  ll ans = N;                                    // start from ans = N
  for (int i = 0; i < (int)p.size() && p[i]*p[i] <= N; ++i) {
    if (N%p[i] == 0) ans -= ans/p[i];            // count unique
    while (N%p[i] == 0) N /= p[i];               // prime factor
  }
  if (N != 1) ans -= ans/N;                      // last factor
  return ans;
}

int mod(int a, int m) {                          // returns a (mod m)
  return ((a%m) + m) % m;                        // ensure positive answer
}

// b^p % m (m must be prime)
int modPow(int b, int p, int m) {                // assume 0 <= b < m
  if (p == 0) return 1;
  int ans = modPow(b, p/2, m);                   // this is O(log p)
  ans = mod(ans*ans, m);                         // double it first
  if (p&1) ans = mod(ans*b, m);                  // *b if p is odd
  return ans;                                    // ans always in [0..m-1]
}

int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(NULL);

  // sieve(10000000);
  ll TC; cin >> TC;
  while (TC--) {
    ll N; cin >> N;
    ll prev = 1, K;
    for (int i = 0; i < N; ++i) {
      cin >> K;
      if (prev <= 1000000000) {
        prev = lcm(prev, K);
      }
    }
      if (prev <= 1000000000) {
        cout << prev << "\n";
      } else {
        cout << "More than a billion.\n";
      }
  }

}