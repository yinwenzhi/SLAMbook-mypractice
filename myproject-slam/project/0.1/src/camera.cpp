#include "myslam/camera.h"
namespce myslam
{
    Camera::camera()
    {
    }
    //这些坐标系变化的内容在第五章
    Vector3d Camera::world2camera (cons Vector3d& p_w, const SE3& T_c_w )//p_w世界坐标系、T_c_w P_w 表示把一个世界坐标系下的齐次坐标,变换到相机坐标系下
    {
        return T_c_w*p_w;
    
    }

    Vector3d Camera::camera2world (cons Vector3d& p_c, const SE3& T_c_w )//p_c 相机坐标系
    {
        return T_c_w.inverse()*p_c;
    }

    Vector3d Camera::camera2pixel (cons Vector3d& p_c )//其中fx_、fy_、cx_、cy_是相机的内参
    {
        return Vector2d(
            fx_ * p_c (0,0 )/p_c( 2,0 ) +cx_,
            fy_ * p_c (1,0 )/p_c( 2,0 ) +cy_
        );
    }

    Vector3d Camera::pixel2camera (cons Vector2d& p_p, double depth )
    {
        return Vector3d(
            (p_p (0,0 ) - cx_) *depth/fx_,
            (p_p (1,0 ) - cy_) *depth/fy_,
            depth 
        );
    }

    Vector3d Camera::world2pixel (cons Vector3d& p_w, const SE3& T_c_w )
    {
        return camera2pixel (world2camera (p_w, T_c_w)
    }

    Wector3d Camera::pixel2world (const Vector2d& p_p ,const SE3& T_c_w, double depth)
    {
        return camera2world (pixel2camera(p_p,depth ), T_c_w);
    }

}
