#include <algorithm>
#include <cstdint>
#include <iostream>

using namespace std;

// 计算最大公因数，使用 int64_t 避免溢出
int64_t gcd(int64_t a, int64_t b) {
    while (b) {
        a %= b;
        swap(a, b);
    }
    return a;
}

int main() {
    int64_t x, y;
    // 读取用户提交程序输出的两个整数
    if (!(cin >> x >> y)) {
        return 1; // 输入格式错误
    }
    // 检查 x, y 是否在 [1, 10^9] 范围内
    if (x < 1 || x > 1000000000 || y < 1 || y > 1000000000) {
        return 1; // 数据范围错误
    }
    int64_t g = gcd(x, y);
    // 计算真实的最小公倍数，先除后乘避免溢出
    int64_t lcm_real = (x / g) * y;
    // 检查最小公倍数是否不超过 10^9
    if (lcm_real > 1000000000) {
        return 1; // 最小公倍数超出限制
    }
    // 模拟给定程序的计算过程
    // 给定程序使用 int 类型，假设为 32 位有符号整数
    int64_t exact_product = x * y; // 精确乘积，可能超过 32 位范围
    // 获取低 32 位（模拟 int 乘法溢出后的位模式）
    uint32_t low32 = static_cast<uint32_t>(exact_product & 0xFFFFFFFFULL);
    // 将低 32 位解释为有符号 int（补码规则）
    int32_t product_int = static_cast<int32_t>(low32);
    // 最大公因数在 int 范围内
    int32_t g_int = static_cast<int32_t>(g);
    // 模拟给定程序中的除法：ans = x * y / g
    int32_t ans_program = product_int / g_int; // 整数除法，向零取整
    // 如果给定程序的计算结果与真实最小公倍数不一致，则数据有效
    if (ans_program != lcm_real) {
        return 0; // 接受这组数据
    } else {
        return 1; // 拒绝这组数据
    }
}