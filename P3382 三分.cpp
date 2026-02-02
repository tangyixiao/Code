#include <iostream>
#include <iomanip>
#include <cmath>

using namespace std;

const double EPS = 1e-7; // 精度控制

int n;
double l, r;
double coeff[15]; // 存储系数，coeff[0]为最高次项系数

// 使用秦九韶算法计算多项式在x处的值
double f(double x) {
    double result = coeff[0];
    for (int i = 1; i <= n; i++) {
        result = result * x + coeff[i];
    }
    return result;
}

int main() {
    cin >> n >> l >> r;
    for (int i = 0; i <= n; i++) {
        cin >> coeff[i];
    }
    
    double left = l, right = r;
    while (right - left > EPS) {
        double mid1 = left + (right - left) / 3.0;
        double mid2 = right - (right - left) / 3.0;
        if (f(mid1) < f(mid2)) {
            left = mid1; // 极大值在[mid1, right]区间
        } else {
            right = mid2; // 极大值在[left, mid2]区间
        }
    }
    
    // 输出左端点或右端点均可，这里输出左端点
    cout << fixed << setprecision(5) << left << endl;
    
    return 0;
}