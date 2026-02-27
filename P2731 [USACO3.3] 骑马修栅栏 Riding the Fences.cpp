#include <algorithm>
#include <iostream>
#include <vector>
using namespace std;

const int MAXN = 501;
int edge[MAXN][MAXN]; // 存储边的数量（处理重边）
int degree[MAXN];     // 每个顶点的度数
int m;
vector<int> path; // 存储欧拉路径

void dfs(int u, int maxV) {
    // 优先访问编号小的顶点，保证字典序最小
    for (int v = 1; v <= maxV; ++v) {
        if (edge[u][v] > 0) { // 存在未访问的边
            edge[u][v]--;     // 标记边为已访问
            edge[v][u]--;
            dfs(v, maxV); // 递归访问下一个顶点
        }
    }
    path.push_back(u); // 递归返回时加入路径
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);

    cin >> m;
    int u, v;
    int maxV = 0; // 记录最大顶点编号，减少遍历范围

    // 读入图，统计度数和边
    for (int i = 0; i < m; ++i) {
        cin >> u >> v;
        edge[u][v]++;
        edge[v][u]++;
        degree[u]++;
        degree[v]++;
        maxV = max(maxV, max(u, v));
    }

    // 确定起点：优先选奇数度顶点中编号最小的
    int start = 1;
    for (int i = 1; i <= maxV; ++i) {
        if (degree[i] % 2 == 1) {
            start = i;
            break;
        }
    }
    // 如果没有奇数度顶点，选第一个有边的顶点
    if (start == 1) {
        for (int i = 1; i <= maxV; ++i) {
            if (degree[i] > 0) {
                start = i;
                break;
            }
        }
    }

    dfs(start, maxV); // 寻找欧拉路径

    // 路径是递归返回的顺序，需要反转
    reverse(path.begin(), path.end());

    // 输出路径（每行一个顶点）
    for (int x : path) {
        cout << x << "\n";
    }

    return 0;
}