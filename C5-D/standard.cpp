#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

const int N = 1e4 + 5, M = 2e5 + 5;
const ll inf = LLONG_MAX;

int tot = 1, lnk[N], ter[M], nxt[M], dep[N], cur[N];
ll val[M];

void add(int u, int v, ll w) {
  ter[++tot] = v;
  nxt[tot] = lnk[u];
  lnk[u] = tot;
  val[tot] = w;
}

void addedge(int u, int v, ll w) {
  add(u, v, w);
  add(v, u, 0);
}

int bfs(int s, int t) {
  memset(dep, 0, sizeof(dep));
  memcpy(cur, lnk, sizeof(lnk));
  queue<int> q;
  q.push(s);
  dep[s] = 1;
  while (!q.empty()) {
    int u = q.front();
    q.pop();
    for (int i = lnk[u]; i; i = nxt[i]) {
      int v = ter[i];
      if (val[i] && !dep[v]) {
        q.push(v);
        dep[v] = dep[u] + 1;
      }
    }
  }
  return dep[t];
}

ll dfs(int u, int t, ll flow) {
  if (u == t) return flow;
  ll ans = 0;
  for (int &i = cur[u]; i && ans < flow; i = nxt[i]) {
    int v = ter[i];
    if (val[i] && dep[v] == dep[u] + 1) {
      ll x = dfs(v, t, min(val[i], flow - ans));
      if (x) {
        val[i] -= x;
        val[i ^ 1] += x;
        ans += x;
      }
    }
  }
  if (ans < flow) dep[u] = -1;
  return ans;
}

ll dinic(int s, int t) {
  ll ans = 0;
  while (bfs(s, t)) {
    ll x;
    while ((x = dfs(s, t, inf))) ans += x;
  }
  return ans;
}

int main() {
  freopen("D:\\Workspace\\algo\\C5-D\\data\\4.in", "r", stdin);
  int n, m, p, t;
  scanf("%d%d%d%d", &n, &m, &p, &t);
  for (int i = 0; i < m; ++i) {
    int u, v, c;
    scanf("%d%d%d", &u, &v, &c);
    addedge(u, v, c);
  }
  for (int i = 0; i < p; ++i) {
    int q;
    scanf("%d", &q);
    addedge(n + 1, q, inf);
  }
  printf("%lld", dinic(n + 1, t));
  return 0;
}