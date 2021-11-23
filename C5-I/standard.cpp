// Author: Marvolo
#include <algorithm>
#include <cmath>
#include <cstdio>
#include <cstring>
#include <iostream>
#include <map>
#include <queue>
#include <vector>
#define l(x) (x << 1)
#define r(x) ((x << 1) | 1)
#define IL inline
#define reg register
#define LL long long
#define N 100010
#define EPS 1e-5
#define INF 0x3f3f3f3f
using namespace std;

int n, m, i, tot, x, y;
double p, q, low, high, mid, ans;
int f[N];

struct Data {
  int x, y, a, b;
  double l;
} a[N];

inline bool cmp(const Data &a, const Data &b) { return a.l > b.l; }

IL int Find(int x) { return (x == f[x]) ? x : f[x] = Find(f[x]); }

IL double Abs(double x) { return (x < 0) ? -x : x; }

IL int read() {
  int p = 0, f = 1;
  char c = getchar();
  while (c < 48 || c > 57) {
    if (c == '-') f = -1;
    c = getchar();
  }
  while (c >= 48 && c <= 57) p = (p << 1) + (p << 3) + c - 48, c = getchar();
  return p * f;
}

IL bool KrusKal(double p) {
  reg int i = 0, tot = 0, x = 0, y = 0;
  double sum = 0;
  for (i = 1; i <= m; i++) a[i].l = a[i].b - p * a[i].a;
  sort(a + 1, a + 1 + m, cmp);
  for (i = 1; i <= n; i++) f[i] = i;
  for (i = 1; i <= m; i++) {
    x = Find(a[i].x);
    y = Find(a[i].y);
    if (x == y) continue;
    f[x] = y;
    sum += a[i].l;
    if (++tot >= n - 1) break;
  }
  return (sum >= 0);
}

int main() {
#ifdef __Marvolo
  freopen("zht.in", "r", stdin);
  freopen("zht.out", "w", stdout);
#endif
  n = read();
  m = read();
  for (i = 1; i <= m; i++) {
    a[i].x = read();
    a[i].y = read();
    a[i].a = read();
    a[i].b = read();
  }

  low = 0;
  high = 9999999999.0;
  while (Abs(low - high) > EPS) {
    mid = (low + high) / 2;
    if (KrusKal(mid))
      low = ans = mid;
    else
      high = mid;
  }
  printf("%.3lf\n", ans);
  return 0;
}