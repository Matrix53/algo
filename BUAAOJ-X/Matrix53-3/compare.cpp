#include <bits/stdc++.h>

using namespace std;

int a[2505];

int main() {
  long long ans = 0;
  int n;
  scanf("%d", &n);
  for (int i = 0; i < n; ++i) scanf("%d", &a[i]);
  for (int i = 0; i < n - 2; ++i) {
    for (int j = i + 1; j < n - 1; ++j) {
      for (int k = j + 1; k < n; ++k) {
        if (a[i] <= a[j] && a[j] <= a[k] && a[i] + a[j] > a[k]) ans++;
      }
    }
  }
  printf("%lld", ans);
  return 0;
}