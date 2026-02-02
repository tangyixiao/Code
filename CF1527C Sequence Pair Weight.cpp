
/*
#include <bits/stdc++.h>
#define int long long
using namespace std;
const int N = 1e5 + 5;
int T, n, ans, a[N];
signed main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);
    for (cin >> T; T--;) {
        ans = 0;
        unordered_map<int, vector<int>> Pos;
        cin >> n;
        for (int i = 1; i <= n; i++) {
            cin >> a[i];
            Pos[a[i]].push_back(i);
        }
        for (auto& [v, pos] : Pos) {
            int m = pos.size();
            if (m >= 2) {
                vector<int> suf(m, 0);
                suf[m - 1] = n - pos[m - 1] + 1;
                for (int i = m - 2; i >= 0; i--) {
                    suf[i] = suf[i + 1] + (n - pos[i] + 1);
                }
                for (int i = 0; i < m - 1; i++) {
                    ans += pos[i] * suf[i + 1];
                }
            }
        }
        cout << ans << '\n';
    }
    return 0;
}

    */

#include <bits/stdc++.h>
#define int long long
using namespace std;
int n, ans, T;
signed main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);
    for (cin >> T; T--;) {
        cin >> n;
        unordered_map<int, int> suf;
        ans = 0;
        for (int i = 1, x; i <= n; i++) {
            cin >> x;
            ans += suf[x] * (n - i + 1);
            suf[x] += i;
        }
        cout << ans << '\n';
    }
    return 0;
}