#include <bits/stdc++.h>
#define int long long
using namespace std;

bool dfs(int x, const vector<int> &a, int start, int end) {
    if (x == 0)
        return true;
    if (x < 0)
        return false;

    for (int i = start; i < end; i++) {
        if (a[i] > x)
            break;
        if (dfs(x - a[i], a, i, end))
            return true;
    }
    return false;
}

void solve() {
    int n;
    cin >> n;
    vector<int> a(n);
    for (auto &x : a)
        cin >> x;
    sort(a.begin(), a.end());

    int ans = n;
    for (int i = 0; i < n; i++) {
        if (dfs(a[i], a, 0, i))
            ans--;
    }
    cout << ans << '\n';
}

signed main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int T;
    cin >> T;
    while (T--)
        solve();
    return 0;
}
