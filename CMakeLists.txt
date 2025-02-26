# CMake 最低版本要求
cmake_minimum_required(VERSION 3.10)

# 项目信息
#test
project(camera_matrix_base)

# 设置 C++ 标准为 17
set(CMAKE_CXX_STANDARD 17)
set(CMAKE_CXX_STANDARD_REQUIRED True)

# 添加可执行文件
add_executable(${PROJECT_NAME} camera_matrix_base.cpp)

# 找到 Eigen 库（假设已安装 Eigen）
find_package(Eigen3 REQUIRED)

# 链接 Eigen 库
target_include_directories(${PROJECT_NAME} PRIVATE ${EIGEN3_INCLUDE_DIR})
