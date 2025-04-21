#include "math_.h"
#include "base.h"

namespace SoftRaster
{
    Eigen::Matrix4f Mat4Translate(float tx, float ty, float tz)
    {
        Eigen::Matrix4f result = Eigen::Matrix4f::Identity();
        result(0, 3) = tx;
        result(1, 3) = ty;
        result(2, 3) = tz;
        return result;
    }

    Eigen::Matrix4f Mat4Scale(float sx, float sy, float sz)
    {
        Eigen::Matrix4f result = Eigen::Matrix4f::Identity();
        result(0, 0) = sx;
        result(1, 1) = sy;
        result(2, 2) = sz;
        return result;
    }

    float radians(float angle)
    {
        return angle * PI / 360.0f;
    }

    Eigen::Matrix4f Mat4RotateX(float angle)
    {
        float radian_ = radians(angle);
        float cos_angle = std::cos(radian_);
        float sin_angle = std::sin(radian_);
        Eigen::Matrix4f result = Eigen::Matrix4f::Identity();
        result(1, 1) = cos_angle;
        result(1, 2) = -sin_angle;
        result(2, 1) = sin_angle;
        result(2, 2) = cos_angle;
        return result;
    }

    Eigen::Matrix4f Mat4RotateY(float angle)
    {
        float radian_ = radians(angle);
        float cos_angle = std::cos(radian_);
        float sin_angle = std::sin(radian_);
        Eigen::Matrix4f result = Eigen::Matrix4f::Identity();
        result(0, 0) = cos_angle;
        result(0, 2) = sin_angle;
        result(2, 0) = -sin_angle;
        result(2, 2) = cos_angle;
        return result;
    }

    Eigen::Matrix4f Mat4RotateZ(float angle)
    {
        float radian_ = radians(angle);
        float cos_angle = std::cos(radian_);
        float sin_angle = std::sin(radian_);
        Eigen::Matrix4f result = Eigen::Matrix4f::Identity();
        result(0, 0) = cos_angle;
        result(0, 1) = -sin_angle;
        result(1, 0) = sin_angle;
        result(1, 1) = cos_angle;
        return result;
    }

    Eigen::Matrix4f Mat4LookAt(const Eigen::Vector3f &x_axis, const Eigen::Vector3f &y_axis, const Eigen::Vector3f &z_axis, const Eigen::Vector3f &eye)
    {
        Eigen::Matrix4f result = Eigen::Matrix4f::Identity();

        result(0, 0) = x_axis.x();
        result(0, 1) = x_axis.y();
        result(0, 2) = x_axis.z();

        result(1, 0) = y_axis.x();
        result(1, 1) = y_axis.y();
        result(1, 2) = y_axis.z();

        result(2, 0) = z_axis.x();
        result(2, 1) = z_axis.y();
        result(2, 2) = z_axis.z();

        result(0, 3) = -x_axis.dot(eye);
        result(1, 3) = -y_axis.dot(eye);
        result(2, 3) = -z_axis.dot(eye);

        return result;
    }

    Eigen::Matrix4f Mat4LookAt(const Eigen::Vector3f &eye, const Eigen::Vector3f &target, const Eigen::Vector3f &up)
    {
        Eigen::Vector3f z_axis = (target - eye).normalized();
        Eigen::Vector3f x_axis = up.cross(z_axis).normalized();
        Eigen::Vector3f y_axis = z_axis.cross(x_axis);
        return Mat4LookAt(x_axis, y_axis, z_axis, eye);
    }

    /*
     * fovy: the field of view angle in the y direction, in radians
     * aspect: the aspect ratio, defined as width divided by height
     * near, far: the distances to the near and far depth clipping planes
     *
     * 1/(aspect*tan(fovy/2))              0             0           0
     *                      0  1/tan(fovy/2)             0           0
     *                      0              0  -(f+n)/(f-n)  -2fn/(f-n)
     *                      0              0            -1           0
     *
     * this is the same as
     *     float half_h = near * (float)tan(fovy / 2);
     *     float half_w = half_h * aspect;
     *     mat4_frustum(-half_w, half_w, -half_h, half_h, near, far);
     *
     * see http://www.songho.ca/opengl/gl_projectionmatrix.html
     */
    Eigen::Matrix4f Mat4Perspective(float fovy, float aspect, float near, float far)
    {
        Eigen::Matrix4f result = Eigen::Matrix4f::Identity();
        float z_range = far - near;
        ASSERT(fovy > 0 && aspect > 0);
        ASSERT(near > 0 && far > 0 && z_range > 0);
        result(1, 1) = 1 / (float)std::tan(fovy / 2);
        result(0, 0) = result(1, 1) / aspect;
        result(2, 2) = -(near + far) / z_range;
        result(2, 3) = -2 * near * far / z_range;
        result(3, 2) = -1;
        result(3, 3) = 0;
        return result;
    }
} // namespace SoftRaster
