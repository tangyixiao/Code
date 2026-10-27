#include <bits/stdc++.h>
using namespace std;
const int N = 1e5 + 5;
struct node {
    int ben, sto;
};
map<string, node> mp;
int n, k, i, q;
long long ans;
string nm;
signed main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cin >> n >> k;
    for (i = 1; i <= n; i++) {
        node t;
        cin >> nm >> t.ben >> t.sto;
        mp[nm] = t;
    }
    ans = 0;
    for (i = 1; i <= k; i++) {
        cin >> nm >> q;
        node &t = mp[nm];
        if (t.sto < q) {
            cout << "-" << i << "\n";
            return 0;
        }
        t.sto -= q;
        ans += 1LL * t.ben * q;
    }
    cout << ans << "\n";
    return 0;
}
