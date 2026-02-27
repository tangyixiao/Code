#include <algorithm>
#include <iostream>
#include <vector>

using namespace std;

struct Product {
    int id; // 产品编号（从1开始）
    int a;  // A车间加工时间
    int b;  // B车间加工时间
};

// 第一组比较函数：A时间升序，相同时按编号升序
bool cmp1(const Product &p1, const Product &p2) {
    if (p1.a != p2.a)
        return p1.a < p2.a;
    return p1.id < p2.id;
}

// 第二组比较函数：B时间降序，相同时按编号降序
bool cmp2(const Product &p1, const Product &p2) {
    if (p1.b != p2.b)
        return p1.b > p2.b;
    return p1.id > p2.id;
}

int main() {
    int n;
    cin >> n;

    vector<int> A(n), B(n);
    for (int i = 0; i < n; i++)
        cin >> A[i];
    for (int i = 0; i < n; i++)
        cin >> B[i];

    vector<Product> group1, group2;

    // 分组：A时间 < B时间 的为第一组，其余为第二组
    for (int i = 0; i < n; i++) {
        Product p;
        p.id = i + 1;
        p.a = A[i];
        p.b = B[i];
        if (p.a < p.b) {
            group1.push_back(p);
        } else {
            group2.push_back(p);
        }
    }

    // 分别排序
    sort(group1.begin(), group1.end(), cmp1);
    sort(group2.begin(), group2.end(), cmp2);

    // 合并得到最终顺序
    vector<Product> order;
    order.reserve(n);
    for (auto &p : group1)
        order.push_back(p);
    for (auto &p : group2)
        order.push_back(p);

    // 计算总加工时间
    int timeA = 0, timeB = 0;
    for (auto &p : order) {
        timeA += p.a;
        timeB = max(timeA, timeB) + p.b;
    }

    // 输出结果
    cout << timeB << endl;
    for (size_t i = 0; i < order.size(); i++) {
        if (i > 0)
            cout << " ";
        cout << order[i].id;
    }
    cout << endl;

    return 0;
}