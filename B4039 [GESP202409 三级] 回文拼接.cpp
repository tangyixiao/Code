#include <bits/stdc++.h>
using namespace std;
int T;
string s;
inline void solve() {
    for (int i = 2; i + 1 < s.size(); i++) {
        string a = s.substr(0, i);
        string b = s.substr(i);
        bool flag1 = true, flag2 = true;
        for (int j = 0; j < a.size(); j++) {
            if (a[j] != a[a.size() - 1 - j]) {
                flag1 = false;
                break;
            }
        }
        for (int j = 0; j < b.size(); j++) {
            if (b[j] != b[b.size() - 1 - j]) {
                flag2 = false;
                break;
            }
        }
        if (flag1 && flag2) {
            cout << "Yes\n";
            return;
        }
    }
    cout << "No\n";
    return;
}
signed main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cin >> T;
    while (T--) {
        cin >> s;
        solve();
    }
    return 0;
}