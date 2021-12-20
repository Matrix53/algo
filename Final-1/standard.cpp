#include <bits/stdc++.h>
using namespace std;

//高精度非负整数
#define MAXN 9999
#define MAXSIZE 1010
#define DLEN 4
struct BigNum {
  int a[500];
  int len;
  BigNum();
  BigNum(const char *, int);
  BigNum(const char *);
  BigNum(const BigNum &);
  BigNum operator+(const BigNum &) const;
  bool operator>(const BigNum &) const;
  void print();
};
BigNum::BigNum() {
  len = 1;
  memset(a, 0, sizeof(a));
}
BigNum::BigNum(const char *s, int L) {
  int t, k, index = 0, i;
  memset(a, 0, sizeof(a));
  len = L % DLEN ? L / DLEN + 1 : L / DLEN;
  for (i = L - 1; i >= 0; i -= DLEN) {
    k = max(0, i - DLEN + 1), t = 0;
    for (int j = k; j <= i; ++j) t = t * 10 + s[j] - '0';
    a[index++] = t;
  }
}
BigNum::BigNum(const char *s) { BigNum(s, strlen(s)); }
BigNum::BigNum(const BigNum &T) : len(T.len) {
  memset(a, 0, sizeof(a));
  for (int i = 0; i < len; ++i) a[i] = T.a[i];
}
BigNum BigNum::operator+(const BigNum &T) const {
  BigNum t(*this);
  int big = T.len > len ? T.len : len;
  for (int i = 0; i < big; ++i) {
    t.a[i] += T.a[i];
    if (t.a[i] > MAXN) {
      t.a[i + 1]++;
      t.a[i] -= MAXN + 1;
    }
  }
  t.len = t.a[big] ? big + 1 : big;
  return t;
}
bool BigNum::operator>(const BigNum &T) const {
  if (len != T.len) return len > T.len;
  int tmp = len - 1;
  while (a[tmp] == T.a[tmp] && tmp >= 0) --tmp;
  return tmp >= 0 && a[tmp] > T.a[tmp];
}
void BigNum::print() {
  printf("%d", a[len - 1]);
  for (int i = len - 2; i >= 0; --i) printf("%04d", a[i]);
}

char num[1000005];

int main() {
  int length;
  scanf("%d%s", &length, num);
  int l = length >> 1, r = l + 1;

  return 0;
}