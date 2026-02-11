#include <bits/stdc++.h>
using namespace std;
const int N = 3e5 + 5, inf = 0x3f3f3f3f;
int T, n, a[N], dist[N];
bool vis[N];
vector<int> nums;
namespace Graph {
inline void init();
inline void Dijkstra();
} // namespace Graph
using namespace Graph;
signed main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cin >> T;
    while (T--) {
        cin >> n;
        for (int i = 0; i <= n; i++) {
            vis[i] = false;
        }
        for (int i = 1; i <= n; i++) {
            cin >> a[i];
            if (a[i] <= n) {
                vis[a[i]] = true;
            }
            dist[i] = inf;
        }
        init();
        Dijkstra();
        for (int i = 1; i <= n; i++) {
            if (dist[i] == inf) {
                cout << -1;
            } else {
                cout << dist[i];
            }
            cout << " \n"[i == n];
        }
    }
    return 0;
}
namespace Graph {
inline void init() {
    nums.clear();
    for (int i = 1; i <= n; i++) {
        if (vis[i]) {
            nums.push_back(i);
        }
    }
    return;
}
inline void Dijkstra() {
    queue<int> q;
    for (int x : nums) {
        dist[x] = 1;
        q.push(x);
    }
    while (!q.empty()) {
        int u = q.front();
        q.pop();
        if (u <= n / nums[0]) {
            for (int x : nums) {
                if (u > n / x) {
                    break;
                }
                int v = u * x;
                if (v <= n && dist[u] + 1 < dist[v]) {
                    dist[v] = dist[u] + 1;
                    q.push(v);
                }
            }
        }
    }
    return;
}
} // namespace Graph

/*
#include <bits/stdc++.h>
// #define DEBUG
using namespace std;
const int N = 3e5 + 5, inf = 0x3f3f3f3f;
vector<int> fac[N];
int T, n, a[N], dp[N];
bool vis[N];
signed main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    for (int d = 2; d <= N - 5; d++) {
        for (int i = d << 1; i <= N - 5; i += d) {
            fac[i].push_back(d);
        }
    }
#ifdef DEBUG
    cerr << "\nHere\n";
#endif
    cin >> T;
    while (T--) {

#ifdef DEBUG
        cerr << "\nHere\n";
#endif
        cin >> n;
        for (int i = 0; i <= n; i++) {
            dp[i] = inf;
            vis[i] = false;
        }
#ifdef DEBUG
        cerr << "\nHere\n";
#endif
        for (int i = 1; i <= n; i++) {
            cin >> a[i];
            if (a[i] <= n) {
                dp[a[i]] = 1;
                vis[a[i]] = true;
            }
        }
#ifdef DEBUG
        cerr << "\nHere\n";
#endif
        for (int i = 1; i <= n; i++) {
            for (int d : fac[i]) {
                int j = i / d;
                if (vis[d] && dp[j] != inf) {
                    dp[i] = min(dp[i], dp[j] + 1);
                }
                if (vis[j] && dp[d] != inf) {
                    dp[i] = min(dp[i], dp[d] + 1);
                }
            }
        }
#ifdef DEBUG
        cerr << "\nHere\n";
#endif
        for (int i = 1; i <= n; i++) {
            cout << (dp[i] == inf ? -1 : dp[i]) << " \n"[i == n];
        }
#ifdef DEBUG
        cerr << "\nHere\n";
#endif
    }
    return 0;
}
*/