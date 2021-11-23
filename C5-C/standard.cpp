// Author: Matrix53
#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

const ll inf = LLONG_MAX / 2;
const int maxv = 1e5 + 5;

struct edge {
  int to;
  ll w;
  edge(int a, ll b) : to(a), w(b) {}
};
struct qnode {
  int id;
  ll ndis;
  qnode(int a, ll b) : id(a), ndis(b) {}
  bool operator<(const qnode& a) const { return ndis > a.ndis; }
};

vector<edge> g[maxv];
int n, m;
ll dis[maxv];
bool done[maxv];

void dijkstra(int s) {
  for (int i = 1; i <= n; ++i) {
    dis[i] = inf;
    done[i] = false;
  }
  dis[s] = 0;
  priority_queue<qnode> q;
  q.push(qnode(s, 0));
  while (!q.empty()) {
    qnode u = q.top();
    q.pop();
    if (done[u.id]) continue;
    done[u.id] = true;
    for (auto v : g[u.id]) {
      if (done[v.to]) continue;
      if (dis[v.to] > u.ndis + v.w) {
        dis[v.to] = u.ndis + v.w;
        q.push(qnode(v.to, dis[v.to]));
      }
    }
  }
}

int main() {
  // freopen("D:/Workspace/algo/E5-D/data/5.in", "r", stdin);
  int p, x, y;
  scanf("%d%d", &n, &m);
  scanf("%d%d%d", &p, &x, &y);
  for (int i = 0; i < m; ++i) {
    int u, v, t;
    scanf("%d%d%d", &u, &v, &t);
    g[u].push_back(edge(v, t));
    g[v].push_back(edge(u, t));
  }
  dijkstra(p);
  ll px = dis[x], py = dis[y];
  dijkstra(x);
  ll xy = dis[y];
  if (px == inf || py == inf || xy == inf) {
    printf("-1");
  } else {
    printf("%lld", xy + min(px, py));
  }
  return 1;
}