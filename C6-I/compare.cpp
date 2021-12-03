#include <bits/stdc++.h>

using namespace std;

int a[100005];

int main() {
  ios::sync_with_stdio(false);
  long long ans = 0;
  int n;
  cin >> n;
  for (int i = 0; i < n; ++i) cin >> a[i];
  sort(a, a + n);
  for (int i = 2; i < n; ++i) {
    int index = lower_bound(a, a + i, a[i] / 2 + 1) - a;
    if (index == i) {
      continue;
    } else if (index == 0) {
      ans += i * (i - 1) / 2;
    } else {
      for (int l = index - 1, r = index; l >= 0; --l) {
        while (r < i && a[l] + a[r] <= a[i]) r++;
        if (r == i) break;
        ans += i - r;
      }
      ans += (i - index) * (i - index - 1) / 2;
    }
  }
  cout << ans;
  return 0;
}