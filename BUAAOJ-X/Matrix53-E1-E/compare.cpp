#include <bits/stdc++.h>

using namespace std;

int a[10005];

bool isTriangle(int a, int b, int c) {
  return (a + b > c) && (a + c > b) && (b + c > a);
}

int main() {
  ios::sync_with_stdio(false);
  long long ans = 0;
  int n;
  cin >> n;
  for (int i = 0; i < n; ++i) cin >> a[i];
  for (int i = 0; i < n - 2; ++i) {
    for (int j = i + 1; j < n - 1; ++j) {
      for (int k = j + 1; k < n; ++k) {
        if (isTriangle(a[i], a[j], a[k])) ans++;
      }
    }
  }
  cout << ans;
  return 0;
}