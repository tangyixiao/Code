#include <bits/stdc++.h>
using namespace std;

int t, cy[26], cx[26];
string x, y;

signed main() {
    ios::sync_with_stdio(false);
    cin.tie(0);
    freopen("sub.in", "r", stdin);
    freopen("sub.out", "w", stdout);
    cin >> t;
    for (; t--;) {
        cin >> x >> y;
        for (int i = 0; i < 26; i++) {
            cx[i] = cy[i] = 0;
        }
        for (int i = 0; i < (int)x.size(); i++) {
            cx[x[i] - 'a']++;
        }
        for (int i = 0; i < (int)y.size(); i++) {
            cy[y[i] - 'a']++;
        }
        int ans = y.size() + 1;
        for (int i = 0; i < 26; i++) {
            if (cx[i] > 0 && cy[i] / cx[i] < ans) {
                ans = cy[i] / cx[i];
            }
        }
        cout << ans << "\n";
    }
    return 0;
}
