前面的 1zc\frac{1}{z_c} 是通过透视投影的几何关系推导出来的。在相机成像模型中，物体的三维坐标 (xc,yc,zc)(x_c, y_c, z_c) 在相机坐标系下被投影到二维的图像平面上。这个投影过程涉及到深度信息（zcz_c）的缩放和丢失，下面是如何得到 1zc\frac{1}{z_c} 的推导过程：
1. 相似三角形的几何关系
在相机坐标系下，一个三维物体点 (xc,yc,zc)(x_c, y_c, z_c) 会通过透视投影映射到图像平面上的点 (xu,yu)(x_u, y_u)。根据相似三角形的原理，可以得到以下关系：
xuf=xczc,yuf=yczc\frac{x_u}{f} = \frac{x_c}{z_c}, \quad \frac{y_u}{f} = \frac{y_c}{z_c} 这里：
ff 是相机的焦距， 
xu,yux_u, y_u 是图像平面上的坐标， 
xc,yc,zcx_c, y_c, z_c 是物体在相机坐标系中的坐标。 
2. 从几何关系到 1zc\frac{1}{z_c}
根据上述相似三角形的比例关系，我们可以得出：
xu=f⋅xczc,yu=f⋅yczcx_u = \frac{f \cdot x_c}{z_c}, \quad y_u = \frac{f \cdot y_c}{z_c} 这意味着 xux_u 和 yuy_u 不仅与物体的 xcx_c 和 ycy_c 成比例，而且还与物体的深度 zcz_c 成反比例。即深度越大（物体越远），图像中的投影越小，反之，深度越小（物体越近），图像中的投影越大。
3. 为什么是 1zc\frac{1}{z_c}？
在透视投影中，物体距离相机的深度 zcz_c 对于投影坐标有一个反比关系。也就是说，随着物体距离相机越来越远，图像中对应点的坐标（xu,yux_u, y_u）将按 1zc\frac{1}{z_c} 的比例缩小。因此，1zc\frac{1}{z_c} 就自然地出现在透视投影的变换中，作为深度与投影之间的缩放因子。
4. 综合成矩阵形式
为了将这一关系表示为矩阵形式，可以写成如下的矩阵表达式：
[xuyu1]=[f000f0001][xczcyczc1]\begin{bmatrix} x_u \\ y_u \\ 1 \end{bmatrix} = \begin{bmatrix} f & 0 & 0 \\ 0 & f & 0 \\ 0 & 0 & 1 \end{bmatrix} \begin{bmatrix} \frac{x_c}{z_c} \\ \frac{y_c}{z_c} \\ 1 \end{bmatrix} 即：
[xuyu1]=[f⋅xczcf⋅yczc1]\begin{bmatrix} x_u \\ y_u \\ 1 \end{bmatrix} = \begin{bmatrix} f \cdot \frac{x_c}{z_c} \\ f \cdot \frac{y_c}{z_c} \\ 1 \end{bmatrix} 从中可以看到，1zc\frac{1}{z_c} 出现在这里是因为物体的深度与图像中位置的关系是反比的，符合透视投影的基本几何规律。
你提到的“Z_c在外面除不会对第三维的1产生影响”是一个非常关键的问题，实际上在进行透视投影时，深度信息 zcz_c 的影响只会作用于 xx 和 yy 维度，而不会直接影响到齐次坐标中的第三维，也就是通常的“1”这一分量。
我们来仔细分析一下透视投影和齐次坐标的转换过程，看看为什么 zcz_c 只会影响 xux_u 和 yuy_u，而不会影响到最后的齐次坐标中的第三个分量（1）。
1. 透视投影的基本形式
首先，假设物体在相机坐标系下的三维坐标为 [xc,yc,zc][x_c, y_c, z_c]，我们希望将这个三维坐标投影到图像平面。透视投影的公式是：
xu=f⋅xczc,yu=f⋅yczcx_u = \frac{f \cdot x_c}{z_c}, \quad y_u = \frac{f \cdot y_c}{z_c} 其中：
ff 是相机的焦距， 
xu,yux_u, y_u 是图像坐标系中的二维坐标， 
xc,yc,zcx_c, y_c, z_c 是相机坐标系中的三维坐标。 
2. 齐次坐标的引入
为了将平移和旋转等变换统一表示，我们使用齐次坐标。在齐次坐标下，物体的三维坐标 [xc,yc,zc][x_c, y_c, z_c] 会扩展为 [xc,yc,zc,1][x_c, y_c, z_c, 1]，图像的二维坐标 [xu,yu][x_u, y_u] 会扩展为 [xu,yu,1][x_u, y_u, 1]。
对于透视投影，使用齐次坐标的矩阵形式可以写作：
[xuyu1]=[f0000f000001][xczcyczc11]\begin{bmatrix} x_u \\ y_u \\ 1 \end{bmatrix} = \begin{bmatrix} f & 0 & 0 & 0 \\ 0 & f & 0 & 0 \\ 0 & 0 & 0 & 1 \end{bmatrix} \begin{bmatrix} \frac{x_c}{z_c} \\ \frac{y_c}{z_c} \\ 1 \\ 1 \end{bmatrix} 可以看到，在透视投影的变换过程中，矩阵会对 xcx_c 和 ycy_c 应用 1zc\frac{1}{z_c} 的比例缩放。而齐次坐标的“1”并没有受影响。
3. 影响的原因：齐次坐标的性质
齐次坐标的引入并不是为了改变图像中坐标的比例，而是为了将平移和旋转等非线性变换纳入矩阵运算的统一框架。因此，在透视投影过程中，xux_u 和 yuy_u 会根据深度 zcz_c 进行缩放，但是齐次坐标中的“1”不参与这个缩放。
为什么会这样？因为齐次坐标的第三维（通常为1）表示的是一个“标定”值，用来维持坐标的比例关系和不变性，而不直接表示空间坐标的投影。换句话说，齐次坐标的“1”是为了保持矩阵的运算一致性，并不参与透视投影的缩放操作，它只起到保持比例和维度的作用。
4. 为什么 zcz_c 不影响齐次坐标中的第三维（1）
在透视投影中，所有的缩放（包括 1zc\frac{1}{z_c} 这样的比例缩放）仅仅作用于 xux_u 和 yuy_u，而不是作用于齐次坐标中的“1”。这和齐次坐标的定义有关：它的“1”表示一个统一的比例因子，通常在进行坐标变换时保持不变。在透视投影中，深度 zcz_c 只会影响物体的二维投影位置，而不会改变齐次坐标的第四维（即3D坐标中的“1”）。
5. 齐次坐标下的归一化
有时，我们在计算机视觉中，使用齐次坐标投影后，最终需要进行“归一化”，即将最后得到的坐标通过齐次坐标的“1”进行除法操作，以恢复真实的像素坐标。在这种情况下，归一化时，我们会将所有的坐标除以 zcz_c，但是这个过程是将透视变换后的坐标从齐次坐标恢复到实际图像坐标系中，而这并不影响最终的“1”，因为它的作用是确保坐标比例的一致性。
总结
简而言之，zcz_c 在透视投影中只影响 xux_u 和 yuy_u，即图像的二维坐标，而不会影响到齐次坐标中的“1”。齐次坐标中的“1”是为了确保矩阵运算的一致性和正确性，在透视投影过程中，它不会被深度 zcz_c 缩放。