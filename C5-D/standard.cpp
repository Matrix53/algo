#include <bits/stdc++.h>

using namespace std;

const int N = 1005;
const int M = 1000005;

struct Road {
  int u, v;
  double val;
  inline bool operator<(const Road &a) const { return val < a.val; }
} A[M];

int n, m, fa[N];
int find(int x) { return fa[x] == x ? x : fa[x] = find(fa[x]); }

double Kruskal() {
  sort(A + 1, A + 1 + m);
  for (int i = 1; i <= n; ++i) fa[i] = i;
  double res = 0;
  for (int i = 1; i <= m; ++i) {
    int u = find(A[i].u);
    int v = find(A[i].v);
    if (u == v) continue;
    fa[u] = v;
    res += A[i].val;
  }
  return res;
}

pair<double, double> p[1005];

int main() {
  // freopen("D:\\Workspace\\algo\\C5-D\\data\\in2.txt", "r", stdin);
  scanf("%d", &n);
  m = n * (n - 1) / 2;
  for (int i = 1; i <= n; ++i) scanf("%lf%lf", &p[i].first, &p[i].second);
  int cnt = 1;
  for (int i = 1; i <= n - 1; ++i) {
    for (int j = i + 1; j <= n; ++j) {
      A[cnt].u = i;
      A[cnt].v = j;
      A[cnt].val =
          hypot(fabs(p[i].first - p[j].first), fabs(p[i].second - p[j].second));
      cnt++;
    }
  }
  printf("%.3f", Kruskal());
  return 0;
}