#include <algorithm>
#include <iostream>
#include <vector>

using namespace std;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int n;
    cin >> n;
    vector<int> h(n + 1);
    for (int i = 1; i <= n; ++i)
        cin >> h[i];

    if (n == 0) {
        cout << 0 << '\n';
        return 0;
    }

    const int INF = 1e9;
    vector<int> dp0(n + 1, INF), dp1(n + 1, INF);

    dp0[0] = 0;
    dp1[0] = INF;

    dp1[1] = 0;
    dp0[1] = dp0[0] + h[1];

    for (int i = 2; i <= n; ++i) {

        dp0[i] = min(dp0[i - 1], dp1[i - 1]) + h[i];

        dp1[i] = min(dp0[i - 1], dp0[i - 2]);
    }

    int ans = min(dp0[n], dp1[n]);
    cout << ans << '\n';

    return 0;
}