#include <bits/stdc++.h>
using namespace std;
string s, s1, s2;
int i, j, n, ans;
signed main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cin >> s;
    n = s.size();
    for (i = 0, j = 1; i < n; i += j, j++) {
        if (j > n - i) {
            break;
        }
        s1 = s.substr(i, j);
        bool flag = true;
        for (int k = 0; k < s1.size() / 2; k++) {
            if (s1[k] != s1[s1.size() - 1 - k]) {
                flag = false;
                break;
            }
        }
        ans += flag;
    }
    if (i < n) {
        s2 = s.substr(i, n - i);
        bool flag = true;
        for (int k = 0; k < s2.size() / 2; k++) {
            if (s2[k] != s2[s2.size() - 1 - k]) {
                flag = false;
                break;
            }
        }
        ans += flag;
    }
    cout << ans;
    return 0;
}