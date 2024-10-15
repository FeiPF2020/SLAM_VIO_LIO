//
// Created by pf on 2024/10/10.
//

#ifndef MULTIVIEWGEOMETRY_COMMONCONSTANT_H
#define MULTIVIEWGEOMETRY_COMMONCONSTANT_H
//MVG: multiViewGeometry

#include <cmath>
#include <eigen3/Eigen/Eigen>
//#include <pcl/point_types.h>
//#include <pcl/point_cloud.h>

namespace MVG {

//#define  M_1_180 (0.005555555555555556);
    constexpr float G_m_s2 = 9.81;
    constexpr double epsilon = 1e-8;


    using V3d = Eigen::Vector3d;
    using M3d = Eigen::Matrix3d;
    using V3f = Eigen::Vector3f;
    using M3f = Eigen::Matrix3f;
    using V6d = Eigen::Vector<double,6>;
    using V6f = Eigen::Vector<float,6>;

    M3d Eye3d(M3d::Identity());
    M3f Eye3f(M3f::Identity());
    V3d Zero3d(0.0, 0.0, 0.0);
    V3f Zero3f(0.0f, 0.0f, 0.0f);


    template<typename T>
    T rad2deg(T radians) {
        return radians * M_1_PI * 180.0;
    }

    template<typename T>
    T deg2rad(T degrees) {
        return degrees * M_PI / 180.0;
    }
    template<typename T>
    T calc_dist(V3d &p1,V3d &p2){
        return (p1-p2).norm();
    }

    template<typename T>
    T calc_dist_T(Eigen::Vector<T,3>p1,Eigen::Vector<T,3>p2){
        return (p1-p2).norm();
    }

    template<typename T>
    bool ValueIsZero(const T &value){
        return value < T(epsilon);
    }




}

#endif //MULTIVIEWGEOMETRY_COMMONCONSTANT_H
