#include <bits/stdc++.h>

using namespace std;

pair<int, int> a[2505], b[2505], c[2505];

long long clac() { return 0; }

int main() {
  long long ans = 0;
  int n;
  scanf("%d", &n);
  for (int i = 0; i < n; ++i) {
    scanf("%d", &a[i].first);
    a[i].second = i;
  }
  sort(a, a + n);
  for (int i = 2; i < n; ++i) {
    int cnt = 0;
    for (int j = 0; j < i; ++j) {
      if (a[j].second < a[i].second) {
        cnt++;
        b[cnt].first = a[j].second;
        b[cnt].second = a[j].first;
      }
    }
    if (cnt <= 1) continue;
    sort(b, b + cnt);
    // TODO: 计算三角形个数
    ans += clac();
  }
  printf("%lld", ans);
  return 0;
}