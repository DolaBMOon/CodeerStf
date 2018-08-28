#include<bits/stdc++.h>

using namespace std;
const int MAXN = 505;
const int P = 65521;
template <typename T> void chkmax(T &x, T y) {x = max(x, y); }
template <typename T> void chkmin(T &x, T y) {x = min(x, y); } 
template <typename T> void read(T &x) {
  x = 0; int f = 1;
  char c = getchar();
  for (; !isdigit(c); c = getchar()) if (c == '-') f = -f;
  for (; isdigit(c); c = getchar()) x = x * 10 + c - '0';
  x *= f;
}
template <typename T> void write(T x) {
  if (x < 0) x = -x, putchar('-');
  if (x > 9) write(x / 10);
  putchar(x % 10 + '0');
}
template <typename T> void writeln(T x) {
  write(x);
  puts("");
}
namespace CayleyHamilton {
  const int MAXN = 3005;
  int n, k;
  int a[MAXN], now[MAXN];
  int res[MAXN], h[MAXN];
  void times(int *x, int *y) {
      static int tmp[MAXN];
      memset(tmp, 0, sizeof(tmp));
      for (int i = 0; i <= k - 1; i++)
      for (int j = 0; j <= k - 1; j++)
          tmp[i + j] = (tmp[i + j] + 1ll * x[i] * y[j]) % P;
      for (int i = 2 * k - 2; i >= k; i--) {
          for (int j = 1; j <= k; j++)
              tmp[i - j] = (tmp[i - j] + 1ll * tmp[i] * a[j]) % P;
          tmp[i] = 0;
      }
      for (int i = 0; i <= k - 1; i++)
          x[i] = tmp[i];
  }
  void init(vector <int> &res, int *val) {
      k = res.size();
      for (int i = 1; i <= k; i++)
          a[i] = res[i - 1];
      for (int i = 1; i <= k * 2; i++)
          h[i] = val[i];
  }
  int query(long long n) {
      if (n <= 2 * k) return h[n];
      res[0] = now[1] = 1; n -= k;
      for (int i = 0; i <= 62; i++) {
          long long tmp = 1ll << i;
          if (n & tmp) times(res, now);
          times(now, now);
      }
      int ans = 0;
      for (int j = 0; j <= k - 1; j++)
          ans = (ans + 1ll * h[k + j] * res[j]) % P;
      return ans;
  }
}
namespace BerlekampMassey {
  const int MAXN = 3005;
  int n, val[MAXN], cnt, fail[MAXN], delta[MAXN];
  vector <int> ans[MAXN];
  int power(int x, int y) {
      if (y == 0) return 1;
      int tmp = power(x, y / 2);
      if (y % 2 == 0) return 1ll * tmp * tmp % P;
      else return 1ll * tmp * tmp % P * x % P;
  }
  void work() {
      ans[cnt = 0].clear();
      for (int i = 1; i <= n; i++) {
          int now = val[i];
          for (unsigned j = 0; j < ans[cnt].size(); j++)
              now = (now - 1ll * val[i - j - 1] * ans[cnt][j] % P + P) % P;
          delta[i] = now; if (now == 0) continue;
          fail[cnt] = i;
          if (cnt == 0) {
              ans[++cnt].clear();
              ans[cnt].resize(i);
              continue;
          }
          ans[++cnt].clear();
          ans[cnt].resize(i - fail[cnt - 2] - 1);
          int mul = 1ll * now * power(delta[fail[cnt - 2]], P - 2) % P;
          ans[cnt].push_back(mul);
          for (unsigned j = 0; j < ans[cnt - 2].size(); j++)
              ans[cnt].push_back(1ll * ans[cnt - 2][j] * (P - mul) % P);
          if (ans[cnt].size() < ans[cnt - 1].size()) ans[cnt].resize(ans[cnt - 1].size());
          for (unsigned j = 0; j < ans[cnt - 1].size(); j++)
              ans[cnt][j] = (ans[cnt][j] + ans[cnt - 1][j]) % P;
      }
  }
}
int k, a[MAXN][MAXN]; long long n;
int power(int x, int y) {
  if (y == 0) return 1;
  int tmp = power(x, y / 2);
  if (y % 2 == 0) return 1ll * tmp * tmp % P;
  else return 1ll * tmp * tmp % P * x % P;
}
int gauss(int n) {
  int f = 1;
  for (int i = 1; i <= n; i++) {
      for (int j = i; j <= n; j++)
          if (a[j][i] != 0) {
              if (i != j) f = -f;
              swap(a[i], a[j]);
              break;
          }
      if (a[i][i] == 0) return 0;
      int inv = power(a[i][i], P - 2);
      for (int j = i + 1; j <= n; j++) {
          int tmp = P - a[j][i];
          if (tmp == P) continue;
          tmp = 1ll * tmp * inv % P;
          for (int k = i; k <= n; k++)
              a[j][k] = (a[j][k] + 1ll * a[i][k] * tmp) % P;
      }
  }
  int ans = (P + f) % P;
  for (int i = 1; i <= n; i++)
      ans = 1ll * ans * a[i][i] % P;
  return ans;
}
int solve(int n, int k) {
  memset(a, 0, sizeof(a));
  for (int i = 1; i <= n; i++)
  for (int j = i + 1; j <= n; j++)
      if (abs(i - j) <= k) {
          a[i][i]++, a[j][j]++;
          a[j][i] = a[i][j] = P - 1;
      }
  return gauss(n - 1);
}
int main() {
  read(k), read(n);
  BerlekampMassey :: n = 100;
  for (int i = 1; i <= BerlekampMassey :: n; i++)
      BerlekampMassey :: val[i] = solve(i, k);
  BerlekampMassey :: work();
  CayleyHamilton :: init(BerlekampMassey :: ans[BerlekampMassey :: cnt], BerlekampMassey :: val);
  writeln(CayleyHamilton :: query(n));
  return 0;
}
