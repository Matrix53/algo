#include <bits/stdc++.h>
using namespace std;

typedef pair<int, int> pii;

int trapRainWater(vector<vector<int>>& heightMap) {
  if (heightMap.size() <= 2 || heightMap[0].size() <= 2) {
    return 0;
  }
  int m = heightMap.size();
  int n = heightMap[0].size();
  priority_queue<pii, vector<pii>, greater<pii>> pq;
  vector<vector<bool>> visit(m, vector<bool>(n, false));
  for (int i = 0; i < m; ++i) {
    for (int j = 0; j < n; ++j) {
      if (i == 0 || i == m - 1 || j == 0 || j == n - 1) {
        pq.push({heightMap[i][j], i * n + j});
        visit[i][j] = true;
      }
    }
  }

  int res = 0;
  int dirs[] = {-1, 0, 1, 0, -1};
  while (!pq.empty()) {
    pii curr = pq.top();
    pq.pop();
    for (int k = 0; k < 4; ++k) {
      int nx = curr.second / n + dirs[k];
      int ny = curr.second % n + dirs[k + 1];
      if (nx >= 0 && nx < m && ny >= 0 && ny < n && !visit[nx][ny]) {
        if (heightMap[nx][ny] < curr.first) {
          res += curr.first - heightMap[nx][ny];
        }
        visit[nx][ny] = true;
        pq.push({max(heightMap[nx][ny], curr.first), nx * n + ny});
      }
    }
  }

  return res;
}

vector<vector<int>> h;

int main() {
  int n, m, x;
  scanf("%d%d", &n, &m);
  for (int i = 0; i < n; ++i) {
    vector<int> tmp;
    for (int j = 0; j < m; ++j) {
      scanf("%d", &x);
      tmp.emplace_back(x);
    }
    h.emplace_back(tmp);
  }
  printf("%d", trapRainWater(h));
  return 0;
}