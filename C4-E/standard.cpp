// Author: Matrix53
#include <bits/stdc++.h>
using namespace std;
const int maxn = 1e5 + 5;
pair<int, int> b[maxn];
int ans[maxn];
int main() {
  int n;
  scanf("%d", &n);
  for (int i = 0; i < n; ++i) {
    scanf("%d", &b[i].first);
    b[i].second = i;
  }
  sort(b, b + n);
  for (int i = 0; i < n; ++i) ans[b[i].second] = b[n - i - 1].first;
  for (int i = 0; i < n; ++i) printf("%d ", ans[i]);
  return 0;
}