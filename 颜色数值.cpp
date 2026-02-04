#include <iostream>
using namespace std;

union Color {
    unsigned int rgba; // 32位整型颜色值

    struct {
        unsigned char b; // 蓝色
        unsigned char g; // 绿色
        unsigned char r; // 红色
        unsigned char a; // 透明度
    } components;
};

int main() {
    Color color;
    color.rgba = 0xFF336699; // ARGB格式

    cout << hex; // 十六进制输出
    cout << "整数值: 0x" << color.rgba << endl;
    cout << "红色分量: 0x" << (int)color.components.r << endl;
    cout << "绿色分量: 0x" << (int)color.components.g << endl;
    cout << "蓝色分量: 0x" << (int)color.components.b << endl;
    cout << "透明度: 0x" << (int)color.components.a << endl;

    return 0;
}