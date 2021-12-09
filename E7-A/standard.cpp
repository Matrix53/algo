// Author: Matrix53
#include <bits/stdc++.h>
using namespace std;

struct Point3 {
  double x, y, z;
  Point3() {}
  Point3(double a, double b, double c) : x(a), y(b), z(c) {}
};

typedef Point3 Vector3;
double dot(Vector3 a, Vector3 b) { return a.x * b.x + a.y * b.y + a.z * b.z; }
Vector3 det(Vector3 a, Vector3 b) {
  return Point3(a.y * b.z - a.z * b.y, a.z * b.x - a.x * b.z,
                a.x * b.y - a.y * b.x);
}

int main() {
  Point3 a, b, c;
  scanf("%lf%lf%lf%lf%lf%lf%lf%lf%lf", &a.x, &a.y, &a.z, &b.x, &b.y, &b.z, &c.x,
        &c.y, &c.z);
  printf("%f", fabs(dot(det(a, b), c)));
  return 0;
}