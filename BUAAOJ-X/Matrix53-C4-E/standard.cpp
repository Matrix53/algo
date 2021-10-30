#include <bits/stdc++.h>
using namespace std;

priority_queue<int> pq;

int main() {
  int n, x, y;
  scanf("%d", &n);
  for (int i = 0; i < n; ++i) {
    scanf("%d", &x);
    pq.emplace(x);
  }
  while (pq.size() != 1) {
    x = pq.top();
    pq.pop();
    y = pq.top();
    pq.pop();
    pq.emplace(x - y);
  }
  printf("%d", pq.top());
  return 0;
}