#include <iostream>
#include <Eigen/Dense>

int main() {
    // 定义世界坐标系中的点 P_w
    Eigen::Vector4d Pw_leftbelow;
    double X_w_leftbelow = 983.0;
    double Y_w_leftbelow = 991.0;
    double Z_w_leftbelow = 17008.0;
    Pw_leftbelow << X_w_leftbelow, Y_w_leftbelow, Z_w_leftbelow, 1.0; // 示例点 (X_w, Y_w, Z_w, 1)

    Eigen::Vector4d Pw_leftup;
    double X_w_leftup = 983.0;
    double Y_w_leftup = 1671.0;
    double Z_w_leftup = 17008.0;
    Pw_leftup << X_w_leftup, Y_w_leftup, Z_w_leftup, 1.0;

    Eigen::Vector4d Pw_rightbelow;
    double X_w_rightbelow = 181.0;
    double Y_w_rightbelow = 991.0;
    double Z_w_rightbelow = 17008.0;
    Pw_rightbelow << X_w_rightbelow, Y_w_rightbelow, Z_w_rightbelow, 1.0;

    Eigen::Vector4d Pw_rightup;
    double X_w_rightup = 181.0;
    double Y_w_rightup = 1671.0;
    double Z_w_rightup = 17008.0;
    Pw_rightup << X_w_rightup, Y_w_rightup, Z_w_rightup, 1.0;
//     // 定义旋转矩阵 R (3x3)
//     Eigen::Matrix3d R;
//     R << 1, 0, 0,
//          0, 1, 0,
//          0, 0, 1; // 示例为单位矩阵（无旋转）

//     // 定义平移向量 t (3x1)
//     Eigen::Vector3d t;
//     t << 0, 0, 0; // 示例平移向量

    // 定义相机内参矩阵 K (3x3)
    Eigen::Matrix3d K;
    K << 1/0.00345, 0, 720, // 主点 (u0, v0) = (720, 540)
         0, 1/0.00345, 540,
         0,   0,   1;
     
    //构造伸缩变换矩阵 F (3x3)
    int f = 75;
    Eigen::Matrix3d F;
    F << f, 0, 0,
         0, f, 0,
         0, 0, 1;

//     // 构造齐次变换矩阵 [R|t]
//     Eigen::Matrix4d RT;
//     RT << R, t,
//           0, 0, 0, 1;

    // 计算相机坐标系下的点 P_c
    Eigen::Vector4d Pc_leftbelow =Pw_leftbelow;
    Eigen::Vector4d Pc_leftup = Pw_leftup;
    Eigen::Vector4d Pc_rightbelow =Pw_rightbelow;
    Eigen::Vector4d Pc_rightup =Pw_rightup;

    // 打印相机坐标系中的齐次坐标
    // std::cout << "Camera coordinate (homogeneous):" << std::endl;
    // std::cout << Pc << std::endl;

    // 如果需要图像坐标 (u, v)，进行透视投影
    Eigen::Vector3d Pc_normalized_leftbelow = Pc_leftbelow.head<3>() / Pc_leftbelow(2); // 归一化
    Eigen::Vector3d Pc_normalized_leftup = Pc_leftup.head<3>() / Pc_leftup(2);
    Eigen::Vector3d Pc_normalized_rightbelow = Pc_rightbelow.head<3>() / Pc_rightbelow(2);
    Eigen::Vector3d Pc_normalized_rightup = Pc_rightup.head<3>() / Pc_rightup(2);

    Eigen::Vector3d uv_homogeneous_leftbelow = K * F * Pc_normalized_leftbelow;
    Eigen::Vector3d uv_homogeneous_leftup = K * F * Pc_normalized_leftup;
    Eigen::Vector3d uv_homogeneous_rightbelow = K * F * Pc_normalized_rightbelow;
    Eigen::Vector3d uv_homogeneous_rightup = K * F * Pc_normalized_rightup;

    std::cout << "Image coordinate (u, v, 1) leftbelow:" << std::endl;
    std::cout << uv_homogeneous_leftbelow << std::endl;
    std::cout << "Image coordinate (u, v, 1) leftup:" << std::endl;
    std::cout << uv_homogeneous_leftup << std::endl;
    std::cout << "Image coordinate (u, v, 1) rightbelow:" << std::endl;
    std::cout << uv_homogeneous_rightbelow << std::endl;
    std::cout << "Image coordinate (u, v, 1) rightup:" << std::endl;
    std::cout << uv_homogeneous_rightup << std::endl;

    return 0;
}
