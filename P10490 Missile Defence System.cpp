#include <iostream>
#include <algorithm>
using namespace std;

const int N = 55;
int n;
int h[N];
int up[N], down[N];  // 分别记录上升系统和下降系统的最后一个高度
int ans;             // 当前最优答案

// u: 当前处理导弹下标, nu: 上升系统数量, nd: 下降系统数量
void dfs(int u, int nu, int nd) {
    if (nu + nd >= ans) return;   // 剪枝：当前系统数已经不小于最优解
    if (u == n) {                 // 所有导弹处理完毕
        ans = nu + nd;
        return;
    }

    // ---------- 尝试将当前导弹加入某个上升系统 ----------
    int k = -1;
    for (int i = 0; i < nu; ++i) {
        if (h[u] > up[i]) {       // 满足上升条件
            if (k == -1 || up[i] < up[k]) // 贪心：选择最后一个高度最小的上升系统
                k = i;
        }
    }
    if (k != -1) {                // 找到可以加入的上升系统
        int tmp = up[k];
        up[k] = h[u];
        dfs(u + 1, nu, nd);
        up[k] = tmp;              // 恢复现场
    } else {                      // 没有可加入的上升系统，新开一个上升系统
        up[nu] = h[u];
        dfs(u + 1, nu + 1, nd);
        // 无需恢复，因为回溯后 nu 不变，下次使用 up[nu] 会覆盖
    }

    // ---------- 尝试将当前导弹加入某个下降系统 ----------
    k = -1;
    for (int i = 0; i < nd; ++i) {
        if (h[u] < down[i]) {     // 满足下降条件
            if (k == -1 || down[i] > down[k]) // 贪心：选择最后一个高度最大的下降系统
                k = i;
        }
    }
    if (k != -1) {                // 找到可以加入的下降系统
        int tmp = down[k];
        down[k] = h[u];
        dfs(u + 1, nu, nd);
        down[k] = tmp;
    } else {                      // 没有可加入的下降系统，新开一个下降系统
        down[nd] = h[u];
        dfs(u + 1, nu, nd + 1);
    }
}

int main() {
    while (cin >> n, n) {
        for (int i = 0; i < n; ++i)
            cin >> h[i];
        ans = n;                  // 最坏情况：每个导弹单独一个系统
        dfs(0, 0, 0);
        cout << ans << endl;
    }
    return 0;
}