// Author: Matrix53
#include <bits/stdc++.h>
using namespace std;

const int INF = 10001;

vector<int> g[1000005];
int score[1000005];

int minNode(int, int);

int maxNode(int now, int limit) {
  if (score[now] != -1) return score[now];
  int ans = -INF;
  for (auto son : g[now]) {
    ans = max(ans, minNode(son, ans));
    if (ans >= limit) break;
  }
  score[now] = ans;
  return ans;
}

int minNode(int now, int limit) {
  if (score[now] != -1) return score[now];
  int ans = INF;
  for (auto son : g[now]) {
    ans = min(ans, maxNode(son, ans));
    if (ans <= limit) break;
  }
  score[now] = ans;
  return ans;
}

int main() {
  int n;
  scanf("%d", &n);
  for (int i = 1; i < n; ++i) {
    int a, b;
    scanf("%d%d", &a, &b);
    g[a].emplace_back(b);
  }
  memset(score, 0xff, sizeof(score));
  for (int i = 1; i <= n; ++i) {
    if (g[i].empty()) scanf("%d", &score[i]);
  }
  printf("%d", maxNode(1, INF));
  return 0;
}