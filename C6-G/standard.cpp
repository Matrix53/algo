#include <bits/stdc++.h>
using namespace std;

const double pi = acos(-1.0);
const double eps = 1e-8;

int sgn(double x) {
  if (fabs(x) < eps) return 0;
  return x > 0 ? 1 : -1;
}
int dcmp(double x, double y) {
  if (fabs(x - y) < eps) return 0;
  return x < y ? -1 : 1;
}

struct Point {
  double x, y;
  Point() : x(0), y(0) {}
  Point(double a, double b) : x(a), y(b) {}
  Point operator+(Point a) { return Point(x + a.x, y + a.y); }
  Point operator-(Point a) { return Point(x - a.x, y - a.y); }
  Point operator*(double k) { return Point(k * x, k * y); }
  Point operator/(double k) { return Point(x / k, y / k); }
  bool operator==(const Point& a) const {
    return sgn(x - a.x) == 0 && sgn(y - a.y) == 0;
  }
  bool operator<(const Point& a) const {
    return sgn(x - a.x) < 0 || (sgn(x - a.x) == 0 && sgn(y - a.y) < 0);
  }
};

double dis(Point a, Point b) { return hypot(a.x - b.x, a.y - b.y); }
typedef Point Vector;
double dot(Vector a, Vector b) { return a.x * b.x + a.y * b.y; }
double det(Vector a, Vector b) { return a.x * b.y - a.y * b.x; }
double len(Vector a) { return hypot(a.x, a.y); }
double len2(Vector a) { return dot(a, a); }
//向量A逆时针旋转rad弧度
Vector rotate(Vector a, double rad) {
  return Vector(a.x * cos(rad) - a.y * sin(rad),
                a.x * sin(rad) + a.y * cos(rad));
}

struct Line {
  Point p1, p2;
  Line() {}
  Line(Point a, Point b) : p1(a), p2(b) {}
  Line(Point p, double angle) {
    p1 = p;
    if (sgn(angle - pi / 2) == 0)
      p2 = p1 + Point(0, 1);
    else
      p2 = p1 + Point(1, tan(angle));
  }
  // ax+by+c=0
  Line(double a, double b, double c) {
    if (sgn(a) == 0) {
      p1 = Point(0, -c / b);
      p2 = Point(1, -c / b);
    } else if (sgn(b) == 0) {
      p1 = Point(-c / a, 0);
      p2 = Point(-c / a, 1);
    } else {
      p1 = Point(0, -c / b);
      p2 = Point(1, (-c - a) / b);
    }
  }
};

typedef Line Segment;
//点到直线的距离
double dis(Point p, Line l) {
  return fabs(det(p - l.p1, l.p2 - l.p1)) / dis(l.p1, l.p2);
}
//点在直线上的投影
Point projection(Point p, Line l) {
  double k = dot(l.p2 - l.p1, p - l.p1) / len2(l.p2 - l.p1);
  return l.p1 + (l.p2 - l.p1) * k;
}
//点和线段的关系：0为在线段延长线上，1为线段端点，2为在线段上，3为左侧，4为右侧
int relation(Point p, Segment s) {
  int sign = sgn(det(s.p2 - s.p1, p - s.p1));
  if (sign) return sign > 0 ? 3 : 4;
  sign = sgn(dot(s.p2 - p, s.p1 - p));
  if (sign) return sign > 0 ? 0 : 2;
  return 1;
}

struct Circle {
  Point c;
  double r;
  Circle() {}
  Circle(Point p, double d) : c(p), r(d) {}
  Circle(double x, double y, double d) {
    c = Point(x, y);
    r = d;
  }
};

//直线和圆的交点，pa和pb为交点，返回值为交点个数
int cross(Line v, Circle C, Point& pa, Point& pb) {
  double d = dis(C.c, v);
  if (d > C.r) return 0;
  Point q = projection(C.c, v);
  double k = sqrt(C.r * C.r - d * d);
  if (sgn(k) == 0) {
    pa = q;
    pb = q;
    return 1;
  }
  Point n = (v.p2 - v.p1) / len(v.p2 - v.p1);
  pa = q + n * k;
  pb = q - n * k;
  return 2;
}

int main() {
  Circle O;
  Point A, K;
  int alpha;
  Point T1, T2, V;
  scanf("%lf%lf%lf", &O.c.x, &O.c.y, &O.r);
  scanf("%lf%lf%d", &A.x, &A.y, &alpha);
  scanf("%lf%lf", &K.x, &K.y);
  cross(Line(A, A + rotate(O.c - A, -(90 - alpha) * pi / 180)), O, T1, T2);
  V = T2 - A + T1 - A;
  for (int count = 0; count < 365; ++count) {
    int res = relation(K, Segment(A, A + V));
    if (res == 1 || res == 2) {
      printf("%d", count);
      return 0;
    }
    A = A + V;
    V = rotate(V, 2 * alpha * pi / 180);
  }
  printf("-1");
  return 0;
}