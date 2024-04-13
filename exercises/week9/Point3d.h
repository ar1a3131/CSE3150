#ifndef POINT3D_H
#define POINT3D_H

struct Point3d {
private:
    double x, y, z;

public:
    Point3d() : x(0), y(0), z(0) {}
    Point3d(double x, double y, double z) : x(x), y(y), z(z) {}
    Point3d(const Point3d& p) : x(p.x), y(p.y), z(p.z) {}
    ~Point3d() {}

    double get_x() const { return x; }
    double get_y() const { return y; }
    double get_z() const { return z; }
};

#endif
