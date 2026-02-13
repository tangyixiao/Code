#include <algorithm>
#include <cmath>
#include <iostream>
#include <vector>

using namespace std;

struct Mole {
    int t, x, y;
};

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    int n, m;
    cin >> n >> m;
    vector<Mole> moles(m);
    for (int i = 0; i < m; ++i)
        cin >> moles[i].t >> moles[i].x >> moles[i].y;

    vector<int> dp(m, 1);
    int ans = 0;

    for (int i = 0; i < m; ++i) {
        for (int j = 0; j < i; ++j) {
            int dt = moles[i].t - moles[j].t;
            int dist = abs(moles[i].x - moles[j].x) + abs(moles[i].y - moles[j].y);
            if (dist <= dt) {
                dp[i] = max(dp[i], dp[j] + 1);
            }
        }
        ans = max(ans, dp[i]);
    }
    cout << ans << '\n';
    return 0;
}