#include <bits/stdc++.h>
using namespace std;

const int N = 5e5+5;  
const int INF = 0x3f3f3f3f;

int n, m;
vector<pair<int, int>> g[N];
int dist[N];

inline int id(int x, int y) {
    return x * (m + 1) + y;
}

void dijkstra() {
    memset(dist, 0x3f, sizeof(dist));
    dist[0] = 0;
    
    deque<int> dq;
    dq.push_front(0);
    
    while (!dq.empty()) {
        int u = dq.front();
        dq.pop_front();
        
        for (auto [v, w] : g[u]) {
            if (dist[v] > dist[u] + w) {
                dist[v] = dist[u] + w;
                if (w == 0) {
                    dq.push_front(v);
                } else {
                    dq.push_back(v);
                }
            }
        }
    }
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    
    cin >> n >> m;
    
    
    int total = (n + 2) * (m + 2) + 5;
    g->clear();
    
    
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < m; j++) {
            char ch;
            cin >> ch;
            
            int u1 = id(i, j);        
            int u2 = id(i, j + 1);    
            int v1 = id(i + 1, j);    
            int v2 = id(i + 1, j + 1);
            
            if (ch == '\\') {
                
                g[u1].push_back({v2, 0});
                g[v2].push_back({u1, 0});
                
                g[u2].push_back({v1, 1});
                g[v1].push_back({u2, 1});
            } else { 
                
                g[u1].push_back({v2, 1});
                g[v2].push_back({u1, 1});
                
                g[u2].push_back({v1, 0});
                g[v1].push_back({u2, 0});
            }
        }
    }
    
    dijkstra();
    
    int target = id(n, m);
    if (dist[target] == INF) {
        cout << "NO SOLUTION\n";
    } else {
        cout << dist[target] << "\n";
    }
    
    return 0;
}