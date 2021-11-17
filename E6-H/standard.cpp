// Author: Matrix53
#include <bits/stdc++.h>
using namespace std;

const double pi = acos(-1.0);
const double eps = 1e-6;

int sgn(double x) {
  if (fabs(x) < eps) return 0;
  return x > 0 ? 1 : -1;
}

struct Point {
  double x, y;
  Point() : x(0), y(0) {}
  Point(double a, double b) : x(a), y(b) {}
  Point operator-(Point a) { return Point(x - a.x, y - a.y); }
};

typedef Point Vector;
double dot(Vector a, Vector b) { return a.x * b.x + a.y * b.y; }
double det(Vector a, Vector b) { return a.x * b.y - a.y * b.x; }
//向量A逆时针旋转rad弧度
Vector rotate(Vector a, double rad) {
  return Vector(a.x * cos(rad) - a.y * sin(rad),
                a.x * sin(rad) + a.y * cos(rad));
}

struct Line {
  Point p1, p2;
  Line() {}
  Line(Point a, Point b) : p1(a), p2(b) {}
};

typedef Line Segment;
//点和线段的关系：0为在线段延长线上，1为线段端点，2为在线段上，3为左侧，4为右侧
int relation(Point p, Segment s) {
  int sign = sgn(det(s.p2 - s.p1, p - s.p1));
  if (sign) return sign > 0 ? 3 : 4;
  sign = sgn(dot(s.p2 - p, s.p1 - p));
  if (sign) return sign > 0 ? 0 : 2;
  return 1;
}

int main() {
  // freopen("D:/Workspace/algo/E6-H/data/4.in", "r", stdin);
  Point O, A, K, T1, T2;
  int alpha;
  scanf("%lf%lf", &O.x, &O.y);
  scanf("%lf%lf%d", &A.x, &A.y, &alpha);
  scanf("%lf%lf", &K.x, &K.y);
  K = K - O;
  A = A - O;
  for (int count = 0; count < 365; ++count) {
    T1 = rotate(A, ((alpha * 2 * count) % 360) * pi / 180);
    T2 = rotate(A, ((alpha * 2 * (count + 1)) % 360) * pi / 180);
    int res = relation(K, Segment(T1, T2));
    if (res == 1 || res == 2) {
      printf("%d", count);
      return 0;
    }
  }
  printf("-1");
  return 0;
}