#include <iostream>
#include <vector>
#include <cstring>
using namespace std;

const int MAXN = 510;
const int MAXM = 50010;

vector<int> graph[MAXN];  // 邻接表
int match[MAXN];          // 右部点匹配的左部点
bool vis[MAXN];           // 访问标记

// DFS寻找增广路径
bool dfs(int u) {
    for (int v : graph[u]) {
        if (!vis[v]) {
            vis[v] = true;
            // 如果v没有匹配，或者可以为v的当前匹配找到新匹配
            if (match[v] == 0 || dfs(match[v])) {
                match[v] = u;
                return true;
            }
        }
    }
    return false;
}

int main() {
    int n, m, e;
    cin >> n >> m >> e;
    
    // 读取边
    for (int i = 0; i < e; i++) {
        int u, v;
        cin >> u >> v;
        graph[u].push_back(v);  // 只从左部点连接到右部点
    }
    
    int ans = 0;  // 最大匹配数
    
    // 尝试为每个左部点寻找匹配
    for (int i = 1; i <= n; i++) {
        memset(vis, false, sizeof(vis));
        if (dfs(i)) {
            ans++;
        }
    }
    
    cout << ans << endl;
    
    return 0;
}