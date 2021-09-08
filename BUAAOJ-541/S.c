#include <stdio.h>
typedef long long ll;

ll A[100005], B[100005];

inline int isEqual(ll a[], ll b[], int n) {
  for (int i = 0; i < n; ++i) {
    if (a[i] != b[i]) return 0;
  }
  return 1;
}

inline int isReverseEqual(ll a[], ll b[], int n) {
  for (int i = 0; i < n; ++i) {
    if (a[i] != b[n - 1 - i]) return 0;
  }
  return 1;
}

int main() {
  int t;
  scanf("%d", &t);
  while (t--) {
    int n;
    scanf("%d", &n);
    for (int i = 0; i < n; ++i) scanf("%lld", &A[i]);
    for (int i = 0; i < n; ++i) scanf("%lld", &B[i]);

    int ans = 0;
    while (1) {
      if (isEqual(A, B, n)) {
        printf("%d\n", ans);
        break;
      }
      if (isReverseEqual(A, B, n)) {
        printf("%d\n", ans + 1);
        break;
      }

      int shouldBreak = 0;
      if (B[0] < B[n - 1]) {
        for (int i = n - 1; i > 0; i--) {
          B[i] = B[i] - B[i - 1];
          if (B[i] <= 0) {
            shouldBreak = 1;
            break;
          }
        }
        ans++;
      } else if (B[0] > B[n - 1]) {
        ll tmp;
        for (int i = 0; i < n / 2; ++i) {
          tmp = B[i];
          B[i] = B[n - 1 - i];
          B[n - 1 - i] = tmp;
        }
        ans++;
      } else {
        shouldBreak = 1;
      }

      if (shouldBreak) {
        printf("-1\n");
        break;
      }
    }
  }
  return 0;
}