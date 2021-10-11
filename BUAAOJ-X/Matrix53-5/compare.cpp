#include <bits/stdc++.h>

using namespace std;

typedef long long ll;
typedef pair<ll, ll> pll;

const ll mod = 998244353;
const int maxn = 1e5 + 5;

pll data[maxn];
int permutation[maxn];

int main() {
  int n;
  scanf("%d", &n);
  for (int i = 0; i < n; ++i) scanf("%lld", &data[i].first);
  for (int i = 0; i < n; ++i) scanf("%lld", &data[i].second);
  for (int i = 0; i < n; ++i) permutation[i] = i;
  ll ans = 0;
  do {
    ll tmp_ans = 0, tmp_item;
    for (int i = 0; i < n; ++i) {
      tmp_item = data[permutation[i]].second;
      for (int j = 0; j < i; ++j) tmp_item *= data[permutation[j]].first;
      tmp_ans += tmp_item;
    }
    tmp_item = 1;
    for (int i = 0; i < n; ++i) tmp_item *= data[permutation[i]].first;
    tmp_ans += tmp_item;
    ans = max(tmp_ans, ans);
  } while (next_permutation(permutation, permutation + n));
  printf("%lld", ans);
  return 0;
}