#include <bits/stdc++.h>
#define ll long long
using namespace std;
int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int n;
    cin >> n;
    vector<ll> a(n + 1);
    for (int i = 1; i <= n; ++i) {
        cin >> a[i];
    }

    vector<pair<ll, int>> cur;
    ll ans = 0;

    for (int i = 1; i <= n; ++i) {
        vector<pair<ll, int>> nxt;

        for (auto& [g, left] : cur) {
            ll new_g = gcd(g, a[i]);
            if (nxt.empty() || nxt.back().first != new_g) {
                nxt.emplace_back(new_g, left);
            }
        }
        if (nxt.empty() || nxt.back().first != a[i]) {
            nxt.emplace_back(a[i], i);
        }

        cur = move(nxt);
        for (auto& [g, left] : cur) {
            ans = max(ans, g * (i - left + 1));
        }
    }

    cout << ans << endl;
    return 0;
}