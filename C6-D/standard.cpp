#include <bits/stdc++.h>
using namespace std;

const double pi = acos(-1.0);
const double eps = 1e-8;
const int maxp = 1010;

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
  bool operator==(const Point &a) const {
    return sgn(x - a.x) == 0 && sgn(y - a.y) == 0;
  }
  bool operator<(const Point &a) const {
    return sgn(x - a.x) < 0 || (sgn(x - a.x) == 0 && sgn(y - a.y) < 0);
  }
};

double dis(Point a, Point b) { return hypot(a.x - b.x, a.y - b.y); }
typedef Point Vector;
double dot(Vector a, Vector b) { return a.x * b.x + a.y * b.y; }
double det(Vector a, Vector b) { return a.x * b.y - a.y * b.x; }

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

struct Polygon {
  int n;
  Point p[maxp];
  Line v[maxp];
};

int convexHull(Point *p, int n, Point *ch) {
  sort(p, p + n);
  n = unique(p, p + n) - p;
  int v = 0;
  for (int i = 0; i < n; ++i) {
    while (v > 1 && det(ch[v - 1] - ch[v - 2], p[i] - ch[v - 2]) <= 0) v--;
    ch[v++] = p[i];
  }
  int j = v;
  for (int i = n - 2; i >= 0; i--) {
    while (v > j && det(ch[v - 1] - ch[v - 2], p[i] - ch[v - 2]) <= 0) v--;
    ch[v++] = p[i];
  }
  if (n > 1) v--;
  return v;
}

double longDis(Point *ch, int n) {
  if (n == 2) return dis(ch[0], ch[1]);
  int i = 0, j = 0;
  for (int k = 0; k < n; ++k) {
    if (ch[k].x < ch[i].x) i = k;
    if (ch[j].x < ch[k].x) j = k;
  }
  double res = 0;
  int si = i, sj = j;
  while (i != sj || j != si) {
    res = max(res, dis(ch[i], ch[j]));
    if (det(ch[(i + 1) % n] - ch[i], ch[(j + 1) % n] - ch[j]) < 0)
      i = (i + 1) % n;
    else
      j = (j + 1) % n;
  }
  return res;
}

Point p[100005], ch[100005];

int main() {
  int n;
  scanf("%d", &n);
  for (int i = 0; i < n; ++i) scanf("%lf%lf", p[i].x, p[i].y);
  int count = convexHull(p, n, ch);
  printf("%lf", longDis(ch, count));
  return 0;
}