#include <bits/stdc++.h>
using namespace std;

const string city = "ABCDEFGRST";
int n, ans;

inline void input() {
    cin >> n;
    return;
}

inline void solve() {
    for (int i = 0; i < n; i++) {
        string s;
        cin >> s;
        if (city.find(s[0]) == string::npos) {
            ans++;
        }
    }
    cout << ans << "\n";
    return;
}

signed main() {
    input();
    solve();
    return 0;
}
