#include <algorithm>
#include <climits>
#include <iostream>
#include <queue>
#include <vector>

using namespace std;

typedef long long ll;

int main() {
    ll h;
    int x, y, z;
    cin >> h >> x >> y >> z;

    if (h == 1) {
        cout << 1 << endl;
        return 0;
    }

    int mod = x;                    // 以x为模数
    vector<ll> dis(mod, LLONG_MAX); // 最小可达高度（余数对应）
    dis[0] = 0;                     // 余数0的最小高度为0

    priority_queue<pair<ll, int>, vector<pair<ll, int>>, greater<pair<ll, int>>> pq;
    pq.push({0, 0});

    ll H = h - 1; // 最大可表示的数（比楼层小1）

    while (!pq.empty()) {
        auto [d, u] = pq.top();
        pq.pop();
        if (d != dis[u])
            continue; // 过时信息，跳过

        // 通过y松弛
        int v1 = (u + y) % mod;
        if (d + y <= H && d + y < dis[v1]) {
            dis[v1] = d + y;
            pq.push({dis[v1], v1});
        }

        // 通过z松弛
        int v2 = (u + z) % mod;
        if (d + z <= H && d + z < dis[v2]) {
            dis[v2] = d + z;
            pq.push({dis[v2], v2});
        }
    }

    ll ans = 0;
    for (int r = 0; r < mod; ++r) {
        if (dis[r] <= H) {
            // 统计所有同余于r且不超过H的可达数
            ans += (H - dis[r]) / x + 1;
        }
    }
    cout << ans << endl;

    return 0;
}