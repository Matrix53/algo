// Author: Matrix53
#include <bits/stdc++.h>
using namespace std;

vector<int> g[100005];
priority_queue<int> pq;
int inDegree[100005];

int main() {
  int n, m;
  scanf("%d%d", &n, &m);
  for (int i = 0; i < m; ++i) {
    int u, v;
    scanf("%d%d", &u, &v);
    g[u].emplace_back(v);
    inDegree[v]++;
  }
  for (int i = 1; i <= n; ++i) {
    if (inDegree[i] == 0) {
      pq.push(i);
    }
  }
  while (!pq.empty()) {
    int now = pq.top();
    pq.pop();
    printf("%d ", now);
    for (auto v : g[now]) {
      inDegree[v]--;
      if (inDegree[v] == 0) {
        pq.push(v);
      }
    }
  }
  return 0;
}