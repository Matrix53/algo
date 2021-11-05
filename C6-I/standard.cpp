#include <bits/stdc++.h>
using namespace std;

int a[100005];

int main() {
  int n, x;
  scanf("%d", &n);
  for (int i = 0; i < n; ++i) {
    scanf("%d", &x);
    a[x]++;
  }
  return 0;
}