#ifndef BASE2D_H
#define BASE2D_H

#include <string>
#include <iostream>

#include <eigen3/Eigen/Dense>

#include "commonConstant.h"
///  PG2D:PhotographyGeometry2D
using namespace MVG;
class PG2D{
    PG2D() = default;

    bool PointInLine(const V3d& p,const V3d& l);
    void Intersection2Lines(const V3d& l0,const V3d& l1,V3d& point);
    void Intersection2points(const V3d& p1,const V3d& p2,V3d& line);
    bool IsIdeaPoint(const V3d& l0,const V3d& l1);
    void IdeaPoint(const V3d& l0,const V3d& l1, V3d& point);



private:
//    MVG::V3d p1_,p2_,p3_;
//    MVG::V3d l1_,l2_,l3_;
    V6d conic_section_;

};






















class Myclass{
public:
     Myclass(const std::string &name);
    void PrintMessage();
    static void SetFlag(const std::string &flag);
private:
    std::string name_;
};

#endif //BASE2D_H