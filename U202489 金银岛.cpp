#include <algorithm>
#include <iomanip>
#include <iostream>
#include <vector>


using namespace std;

struct Metal {
    int weight;        // 总重量
    int value;         // 总价值
    double unit_value; // 单位价值
};

bool compare(const Metal &a, const Metal &b) {
    return a.unit_value > b.unit_value; // 按单位价值降序排序
}

int main() {
    int k;
    cin >> k;

    cout << fixed << setprecision(2); // 设置输出精度为两位小数

    for (int t = 0; t < k; ++t) {
        int w, s;
        cin >> w >> s;

        vector<Metal> metals(s);

        // 读取金属信息
        for (int i = 0; i < s; ++i) {
            cin >> metals[i].weight >> metals[i].value;
            metals[i].unit_value = static_cast<double>(metals[i].value) / metals[i].weight;
        }

        // 按单位价值降序排序
        sort(metals.begin(), metals.end(), compare);

        double total_value = 0.0;
        int remaining_weight = w;

        // 贪心选择
        for (int i = 0; i < s && remaining_weight > 0; ++i) {
            if (metals[i].weight <= remaining_weight) {
                // 全部取走这种金属
                total_value += metals[i].value;
                remaining_weight -= metals[i].weight;
            } else {
                // 部分取走这种金属
                total_value += metals[i].unit_value * remaining_weight;
                remaining_weight = 0;
            }
        }

        cout << total_value << endl;
    }

    return 0;
}