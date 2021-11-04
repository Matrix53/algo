#include <bits/stdc++.h>

using namespace std;

const int N = 3505;

int a[N], b[N], c[N];
int pa, pb, pc;

int main() {
  long long ans = 0;
  scanf("%d", &pa);
  for (int i = 0; i < pa; ++i) scanf("%d", &a[i]);
  for (int j = 1; j < pa - 1; ++j) {
    pc = pb = 0;
    for (int i = 0; i < j; ++i) {
      if (a[i] <= a[j]) b[pb++] = a[i];
    }
    for (int k = j + 1; k < pa; ++k) {
      if (a[j] <= a[k]) c[pc++] = a[k];
    }
    if (pb == 0 || pc == 0) continue;
    sort(b, b + pb);
    sort(c, c + pc);
    int i = 0, k = 0;
    while (i < pb && b[i] + a[j] <= c[k]) i++;
    while (i < pb) {
      while (k < pc - 1 && b[i] + a[j] > c[k + 1]) k++;
      ans += k + 1;
      i++;
    }
  }
  printf("%lld", ans);
  return 0;
}