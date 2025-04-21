/**
 * @file math_.h
 * @author 刘亚奇 (1904310303@qq.com)
 * @brief 实现矩阵计算
 * @date 2025-04-20
 *
 * @copyright Copyright (c) 2025
 *
 */

#pragma once

#include "Eigen/Eigen"

constexpr double PI = 3.1415926535;

namespace SoftRaster
{
    /**
     * @brief 计算平移矩阵
     *
     * @param tx
     * @param ty
     * @param tz
     * @return Eigen::Matrix4f
     */
    Eigen::Matrix4f Mat4Translate(float tx, float ty, float tz);

    /**
     * @brief 计算缩放矩阵
     *
     * @param sx
     * @param sy
     * @param sz
     * @return Eigen::Matrix4f
     */
    Eigen::Matrix4f Mat4Scale(float sx, float sy, float sz);

    /**
     * @brief 角度转弧度
     *
     * @param angle
     * @return float
     */
    float radians(float angle);

    /**
     * @brief 旋转矩阵 绕X轴
     *
     * @param angle
     * @return Eigen::Matrix4f
     */
    Eigen::Matrix4f Mat4RotateX(float angle);

    /**
     * @brief 旋转矩阵 绕Y轴
     *
     * @param angle
     * @return Eigen::Matrix4f
     */
    Eigen::Matrix4f Mat4RotateY(float angle);

    /**
     * @brief 旋转矩阵 绕Z轴
     *
     * @param angle
     * @return Eigen::Matrix4f
     */
    Eigen::Matrix4f Mat4RotateZ(float angle);

    /**
     * @brief 计算视图矩阵
     *
     * @param x_axis x轴
     * @param y_axis y轴
     * @param z_axis z轴
     * @param eye  摄像机位置
     * @return Eigen::Matrix4f
     */
    Eigen::Matrix4f Mat4LookAt(const Eigen::Vector3f &x_axis, const Eigen::Vector3f &y_axis, const Eigen::Vector3f &z_axis, const Eigen::Vector3f &eye);

    /**
     * @brief 计算视图矩阵
     *
     * @param eye 摄像机位置
     * @param target  目标位置
     * @param up  上方向
     * @return Eigen::Matrix4f
     */
    Eigen::Matrix4f Mat4LookAt(const Eigen::Vector3f &eye, const Eigen::Vector3f &target, const Eigen::Vector3f &up);

    /**
     * @brief 透视投影矩阵
     *
     * @param fovy
     * @param aspect
     * @param near
     * @param far
     * @return Eigen::Matrix4f
     */
    Eigen::Matrix4f Mat4Perspective(float fovy, float aspect, float near, float far);
} // namespace SoftRaster
