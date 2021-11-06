#include <bits/stdc++.h>
using namespace std;

const double pi = acos(-1.0);

struct Point {
  double x, y;
  Point() : x(0), y(0) {}
  Point(double a, double b) : x(a), y(b) {}
  Point operator+(Point a) { return Point(x + a.x, y + a.y); }
  Point operator-(Point a) { return Point(x - a.x, y - a.y); }
  Point operator*(double k) { return Point(k * x, k * y); }
};

typedef Point Vector;
Vector rotate(Vector a, double rad) {
  return Vector(a.x * cos(rad) - a.y * sin(rad),
                a.x * sin(rad) + a.y * cos(rad));
}

int main() {
  Point O, A, T1, T2;
  int alpha;
  O.x = 100;
  O.y = 100;
  A.x = 2100;
  A.y = 100;
  alpha = 10;
  A = A - O;
  for (int count = 0; count < 365; ++count) {
    if (count == 197) {
      T1 = rotate(A, ((alpha * 2 * count) % 360) * pi / 180);
      T2 = rotate(A, ((alpha * 2 * (count + 1)) % 360) * pi / 180);
      T1 = (T2 - T1) * 0.7 + T1 + O + Point(0, 1e-4);
      printf("%.10f %.10f", T1.x, T1.y);
    }
  }
  return 0;
}