#include <bits/stdc++.h>
using namespace std;

int p[26];

signed main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    string s;
    getline(cin, s);
    int a[8] = {3, 6, 9, 12, 15, 19, 22, 26};
    int st = 0, val = 1;
    for (int i = 0; i < 26; i++) {
        while (st < 8 && i >= a[st]) {
            st++;
            val = 1;
        }
        p[i] = val;
        val++;
    }
    int ans = 0;
    for (size_t i = 0; i < s.size(); i++) {
        if (s[i] == ' ') {
            ans += 1;
        } else if (s[i] >= 'a' && s[i] <= 'z') {
            ans += p[s[i] - 'a'];
        }
    }
    cout << ans << "\n";
    return 0;
}
