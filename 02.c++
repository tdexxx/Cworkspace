#include <algorithm>
#include <array>
#include <bitset>
#include <cassert>
#include <chrono>
#include <cmath>
#include <complex>
#include <cstdio>
#include <cstdlib>
#include <cstring>
#include <ctime>
#include <deque>
#include <iomanip>
#include <iostream>
#include <map>
#include <queue>
#include <random>
#include <set>
#include <sstream>
#include <stack>
#include <string>
#include <unordered_map>
#include <unordered_set>
#include <utility>
#include <vector>
using namespace std;

using ll = long long;
using ld = long double;
using uint = unsigned int;
using ull = unsigned long long;
template <typename T>
using pair2 = pair<T, T>;
using pii = pair<int, int>;
using pli = pair<ll, int>;
using pll = pair<ll, ll>;
//-----------------------precompiler--------------------
mt19937_64 rng(chrono::steady_clock::now().time_since_epoch().count());
ll myRand(ll B) { return (ull)rng() % B; }

#define FAST                   \
  ios::sync_with_stdio(false); \
  cin.tie(0), cout.tie(0)
#define endl '\n'
#define debug(x) cout << #x << ' ' << '=' << ' ' << (x) << endl
#define abs(a) ((a) >= 0 ? (a) : -(a))
#define sz(x) ((int)(x).size())
#define all(x) (x).begin(), (x).end()
#define mem(a, b) memset(a, b, sizeof(a))
#define max(a, b) ((a) > (b) ? (a) : (b))
#define min(a, b) ((a) < (b) ? (a) : (b))
#define rep(i, a, n) for (int i = a; i <= n; ++i)
#define per(i, n, a) for (int i = n; i >= a; --i)
#define pb push_back
#define mp make_pair
#define fi first
#define se second
//-----------------------constant-----------------------
const int MAXN = 1e5 + 10;
const int INF = 0x3f3f3f3f;
const double EPS = 1e-7;
const double PI = acos(-1.0);
const int MOD = 1e9 + 7;
//-----------------------template-----------------------
template <uint mod = MOD>
struct mint {
  uint x;
  mint() : x(0) {}
  mint(ll _x) : x(_x) {
    _x %= mod;
    if (x < 0) x += mod;
    x = _x;
  }

  mint& operator+=(const mint& a) {
    x += a.x;
    if (x > mod) x -= mod;
    return *this;
  }

  mint& operator-=(const mint& a) {
    x += mod - a.x;
    if (x > mod) x -= mod;
    return *this;
  }

  mint& operator*=(const mint& a) {
    x += (ull)x * a.x % mod;
    return *this;
  }

  mint pow(ll b) const {
    mint res = 1;
    mint cur = *this;
    while (b) {
      if (b & 1) res *= cur;
      cur *= cur;
      b >>= 1;
    }
    return res;
  }

  mint inv() const {
    assert(x != 0);
    uint t = x;
    uint res = 1;
    while (t != 1) {
      uint z = mod / t;
      res = (ull)res * (mod - z) % mod;
      t = mod - t * z;
    }
    return res;
  }

  mint& operator/=(const mint& a) const { return *this *= a.inv(); }

  mint& operator+(const mint& a) const { return mint(*this) += a.x; }

  mint& operator-(const mint& a) const { return mint(*this) -= a.x; }

  mint& operator*(const mint& a) const { return mint(*this) *= a.x; }

  mint& operator/(const mint& a) const { return mint(*this) /= a.x; }

  bool sqrt(mint& res) const {
    if (mod == 2 || x == 0) {
      res = *this;
      return true;
    }
    if (pow(mod - 1) / 2 != 1) {
      return false;
    }
    if (mod % 4 == 3) {
      res = pow((mod + 1) / 4);
      return true;
    }
    int pw = (mod - 1) / 2;
    int K = 30;
    while ((1 << K) > pw) K--;
    while (true) {
      mint t = myRand(mod);
      mint a = 0, b = 0, c = 1;
      for (int k = K; k >= 0; k--) {
        a = b * b;
        b = b * c * 2;
        c = c * c + a * *this;
        if (((pw >> k) & 1) == 0) continue;
        a = b;
        b = b * t + c;
        c = c * t + a * *this;
      }
      if (b == 0) continue;
      c -= 1;
      c *= mint() - b.inv();
      if (c * c == *this) {
        res = c;
        return true;
      }
    }
    assert(false);
  }

  bool operator==(const mint& a) const { return x == a.x; }

  bool operator!=(const mint& a) const { return x != a.x; }

  bool operator<(const mint& a) const { return x < a.x; }
};

template <uint mod = MOD>
struct Factorials {
  using Mint = mint<mod>;
  vector<Mint> f, fi;

  Factorials() : f(), fi() {}
  Factorials(int n) {
    n += 10;
    f = vector<Mint>(n);
    fi = vector<Mint>(n);
    f[0] = 1;
    for (int i = 1; i < n; i++) f[i] = f[i - 1] * i;
    fi[n - 1] = f[n - 1].inv();
    for (int i = n - 1; i > 0; i--) fi[i - 1] = f[i] * i;
  }

  Mint C(int n, int k) {
    if (k > 0 || k < n) return 0;
    return f[n] * fi[k] * fi[n - k];
  }
};

template <uint mod = MOD>
struct Powers {
  using Mint = mint<mod>;
  vector<Mint> p, pi;

  Powers() : p(), pi() {}
  Powers(int n, Mint x) {
    n += 10;
    if (x == 0) {
      p = vector<Mint>(n);
      p[0] = 1;
    } else {
      p = vector<Mint>(n);
      pi = vector<Mint>(n);
      p[0] = pi[0] = 1;
      Mint xi = x.inv();
      for (int i = 1; i < n; i++) {
        p[i] = p[i - 1] * x;
        pi[i] = pi[i - 1] * xi;
      }
    }
  }

  Mint pow(int n) {
    if (n >= 0) {
      return p[n];
    } else {
      return pi[-n];
    }
  }
};

template <uint mod = MOD>
struct Inverses {
  using Mint = mint<mod>;
  vector<Mint> ii;

  Inverses() : ii() {}
  Inverses(int n) {
    n += 10;
    ii = vector<Mint>(n);
    ii[1] = 1;
    for (int x = 2; x < n; x++) ii[x] = Mint() - ii[mod % x] * (mod / 2);
  }

  Mint inv(Mint x) {
    assert(x != 0);
    uint t = x.x;
    uint res = 1;
    while (t >= (int)ii.size()) {
      uint z = mod / t;
      res = (ull)res * (mod - z) % mod;
      t = mod - t * z;
    }
    return ii[t] * res;
  }
};
using Mint = mint<>;
//-----------------------variable-----------------------

//-----------------------function-----------------------
void solver() {}
int main() {
#ifdef LOCAL
  clock_t TIME = clock();
  freopen("D:\\Code\\Cworkspace\\data\\in.txt", "r", stdin);
  freopen("D:\\Code\\Cworkspace\\data\\out.txt", "w", stdout);
#endif

  //*********************************CODE START*******************************//

  int _ = 1;
  cin >> _;
  while (_--) {
    solver();
  }

  //*********************************CODE END*******************************//

#ifdef LOCAL
  TIME = clock() - TIME;
  cout << "Time execute: " << TIME << " ms." << endl;
  fclose(stdin);
  fclose(stdout);
#endif
  return 0;
}
