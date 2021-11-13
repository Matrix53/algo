#include <bits/stdc++.h>

using namespace std;
typedef long long ll;
inline int read() {
  int q = 0, w = 1;
  char c = getchar();
  while (!isdigit(c)) {
    if (c == '-') w = -1;
    c = getchar();
  }
  while (isdigit(c)) q = q * 10 + c - '0', c = getchar();
  return w * q;
}
const int N = 5050;
const int M = N * 2;

int head[N], to[M], Next[M];
ll cap[M];
int n, m, s, t;
int q[N], l, r;
int d[N], cur[N];
int num = 1;
inline void insert(int x, int y, ll l) {
  Next[++num] = head[x];
  head[x] = num;
  to[num] = y;
  cap[num] = l;
  Next[++num] = head[y];
  head[y] = num;
  to[num] = x;
  cap[num] = 0;
}

inline bool BFS() {
  for (int i = 1; i <= n; ++i) d[i] = 0x3f3f3f3f;
  l = r = 1;
  q[1] = t;
  d[t] = 0;
  while (l <= r) {
    int x = q[l++];
    for (int i = head[x]; i; i = Next[i]) {
      int u = to[i];
      if (cap[i ^ 1] && d[u] > d[x] + 1) {
        d[u] = d[x] + 1;
        q[++r] = u;
      }
    }
  }
  return d[s] != 0x3f3f3f3f;
}
inline ll DFS(int x, ll a) {
  if (x == t || !a) return a;
  ll flow = 0, f = 0;
  for (int &i = cur[x]; i; i = Next[i]) {
    int u = to[i];
    if (d[u] == d[x] - 1 && cap[i] && (f = DFS(u, min(a, cap[i]))) > 0) {
      cap[i] -= f;
      cap[i ^ 1] += f;
      flow += f;
      a -= f;
      if (!a) return flow;
    }
  }
  return flow;
}

inline ll Dinic() {
  ll res = 0;
  while (BFS()) {
    //		for(int i = 1;i <= n;++i) cur[i] = head[i];
    memcpy(cur, head, sizeof head);
    res += DFS(s, 0x3f3f3f3f3f3f3f3f);
  }
  return res;
}
int main() {
  // freopen("D:\\Workspace\\algo\\C5-D\\data\\1.in", "r", stdin);
  n = read() + 1;
  m = read();
  s = n;
  int p = read();
  t = read();
  for (int i = 1; i <= m; ++i) {
    int x = read(), y = read(), l = read();
    insert(x, y, l);
  }
  for (int i = 0; i < p; ++i) {
    int x = read();
    insert(n, x, 0x3f3f3f3f3f3f3f3f);
  }
  printf("%lld\n", Dinic());
  return 0;
}