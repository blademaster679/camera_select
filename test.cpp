#include <SFML/Graphics.hpp>

int main()
{
    // 创建一个窗口，尺寸为 800x600
    sf::RenderWindow window(sf::VideoMode(800, 600), "SFML Rectangle");

    // 创建一个矩形，宽 300，高 160
    sf::RectangleShape rectangle(sf::Vector2f(300, 160));
    
    // 设置矩形的位置（左上角坐标）
    rectangle.setPosition(250, 220);  // 使其居中显示

    // 设置矩形的边框颜色和填充颜色
    rectangle.setFillColor(sf::Color::White);  // 填充为绿色
    rectangle.setOutlineColor(sf::Color::Blue); // 边框颜色为蓝色
    rectangle.setOutlineThickness(5);           // 边框厚度为 5

    // 程序主循环，保持窗口持续显示，直到用户关闭窗口
    while (window.isOpen())
    {
        sf::Event event;
        // 事件处理
        while (window.pollEvent(event))
        {
            if (event.type == sf::Event::Closed)
                window.close();
        }

        // 清空窗口
        window.clear();

        // 绘制矩形
        window.draw(rectangle);

        // 显示窗口内容
        window.display();
    }

    return 0;
}
