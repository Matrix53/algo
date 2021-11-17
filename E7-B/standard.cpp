// Author: Matrix53
#include <bits/stdc++.h>
using namespace std;

const int maxl = 1e6 + 5;

int fail[maxl];

void getFail(char *p, int plen) {
  fail[0] = 0;
  fail[1] = 0;
  for (int i = 1; i < plen; ++i) {
    int j = fail[i];
    while (j > 0 && p[i] != p[j]) j = fail[j];
    fail[i + 1] = (p[i] == p[j] ? j + 1 : 0);
  }
}

void kmp(char *p, char *s, int plen, int slen) {
  int last = -1;
  getFail(p, plen);
  int j = 0;
  for (int i = 0; i < slen; ++i) {
    while (j && s[i] != p[j]) j = fail[j];
    if (s[i] == p[j]) ++j;
    if (j == plen) {
      printf("%d ", i + 1 - plen);
    }
  }
}

char s[maxl], t[maxl];

int main() {
  scanf("%s%s", s, t);
  kmp(t, s, strlen(t), strlen(s));
  return 0;
}