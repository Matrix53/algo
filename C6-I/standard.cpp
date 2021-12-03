#include <math.h>
#include <stdio.h>
#include <string.h>

#include <algorithm>
#include <iostream>
#include <string>

using namespace std;
const long long N = 500005;
const double PI = acos(-1.0);

struct Virt {
  double r, i;
  Virt(double r = 0.0, double i = 0.0) {
    this->r = r;
    this->i = i;
  }
  Virt operator+(const Virt &x) { return Virt(r + x.r, i + x.i); }
  Virt operator-(const Virt &x) { return Virt(r - x.r, i - x.i); }
  Virt operator*(const Virt &x) {
    return Virt(r * x.r - i * x.i, i * x.r + r * x.i);
  }
};
//雷德算法--倒位序
void Rader(Virt F[], long long len) {
  long long j = len >> 1;
  for (long long i = 1; i < len - 1; i++) {
    if (i < j) swap(F[i], F[j]);
    long long k = len >> 1;
    while (j >= k) {
      j -= k;
      k >>= 1;
    }
    if (j < k) j += k;
  }
}
// FFT实现
void FFT(Virt F[], long long len, long long on) {
  Rader(F, len);
  for (long long h = 2; h <= len; h <<= 1)  //分治后计算长度为h的DFT
  {
    Virt wn(cos(-on * 2 * PI / h),
            sin(-on * 2 * PI / h));  //单位复根e^(2*PI/m)用欧拉公式展开
    for (long long j = 0; j < len; j += h) {
      Virt w(1, 0);  //旋转因子
      for (long long k = j; k < j + h / 2; k++) {
        Virt u = F[k];
        Virt t = w * F[k + h / 2];
        F[k] = u + t;  //蝴蝶合并操作
        F[k + h / 2] = u - t;
        w = w * wn;  //更新旋转因子
      }
    }
  }
  if (on == -1)
    for (long long i = 0; i < len; i++) F[i].r /= len;
}
//求卷积
void Conv(Virt a[], long long len) {
  FFT(a, len, 1);
  //    FFT(b,len,1);
  for (long long i = 0; i < len; i++) a[i] = a[i] * a[i];
  FFT(a, len, -1);
}
long long a[N], num[N], sum[N], ans[N];
Virt va[N];
int main() {
  memset(num, 0, sizeof(num));
  long long n;
  scanf("%I64d", &n);
  for (long long i = 0; i < n; i++) {
    scanf("%I64d", &a[i]);
    num[a[i]]++;
  }
  sort(a, a + n);
  long long len1 = a[n - 1] + 1;
  long long len = 1;
  while (len < len1 * 2) len <<= 1;
  for (long long i = 0; i < len; i++) {
    va[i].r = num[i];
    va[i].i = 0;
  }
  Conv(va, len);
  for (long long i = 0; i < len; i++) {
    sum[i] = (long long)(va[i].r + 0.5);
    //            cout<<sum[i]<<endl;
  }
  len = a[n - 1] * 2;
  for (long long i = 0; i < n; i++) sum[a[i] + a[i]]--;
  for (long long i = 0; i <= len; i++) sum[i] >>= 1;
  ans[0] = 0;
  for (long long i = 1; i <= len; i++) {
    ans[i] = ans[i - 1] + sum[i];
  }
  long long cnt = 0;
  for (long long i = 0; i < n; i++) {
    cnt += ans[len] - ans[a[i]];
    cnt -= (long long)(n - i - 1) * i;                //减去一大一小
    cnt -= n - 1;                                     //减去选择这个数的
    cnt -= (long long)(n - i - 1) * (n - i - 2) / 2;  //减去两个大的
  }
  // long long tmp=(long long)n*(n-1)*(n-2)/6;
  printf("%lld\n", cnt);
  return 0;
}