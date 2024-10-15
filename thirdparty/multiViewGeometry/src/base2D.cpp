#include "base2D.h"

#include <gflags/gflags.h>

#include <utility>

DEFINE_string(user_flag, "default", "User_defined flag for demonstration");

Myclass::Myclass(const std::string &name) : name_(name) {
    std::cout << "Construct ---  Name is : " << name_;
}

void Myclass::PrintMessage() {
    std::cout << "Print ---- Name is : " << name_;
}

void Myclass::SetFlag(const std::string &flag) {
    FLAGS_user_flag = flag;
    std::cout << "Flag ---- Name is : " << FLAGS_user_flag;
}




bool PG2D::PointInLine(const V3d &p, const V3d &l) {
    // is line
    if (ValueIsZero(l.x()) && ValueIsZero(l.y())) return false;
    return ValueIsZero(p.transpose().dot(l)) && ValueIsZero(l.transpose().dot(p));
}

void PG2D::Intersection2Lines(const V3d &l0, const V3d &l1, V3d &point) {
    if (ValueIsZero(l0.x()) && ValueIsZero(l0.y())) return;
    if (ValueIsZero(l1.x()) && ValueIsZero(l1.y())) return;
    point(l0.cross(l1));
}

void PG2D::Intersection2points(const V3d &p1, const V3d &p2, V3d &line) {
    line(p1.cross(p2));
}

bool PG2D::IsIdeaPoint(const V3d &l0, const V3d &l1) {
    if (ValueIsZero(l0.x()) && ValueIsZero(l0.y())) return false;
    if (ValueIsZero(l1.x()) && ValueIsZero(l1.y())) return false;
    return l0.x() * l1.y() == l1.x() * l0.y();
}

void PG2D::IdeaPoint(const V3d &l0, const V3d &l1, V3d &point) {
    if (ValueIsZero(l0.x()) && ValueIsZero(l0.y())) return;
    if (ValueIsZero(l1.x()) && ValueIsZero(l1.y())) return;
    if (l0.x() * l1.y() == l1.x() * l0.y()) {
        point(l0.cross(l1));
    }
}


