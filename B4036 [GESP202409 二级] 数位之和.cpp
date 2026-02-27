#pragma G++ optimize("O3", "unroll-loops", "omit-frame-pointer", "inline")
#include <bits/stdc++.h>
using namespace std;
int n;
string s;
signed main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cin >> n;
    while (n--) {
        cin >> s;
        int ans = 0;
        for (int i = 0; i < s.size(); i++) {
            ans += s[i] - '0';
        }
        cout << (ans % 7 == 0 ? "Yes" : "No") << endl;
    }
    return 0;
}