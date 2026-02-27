#include <bits/stdc++.h>
using namespace std;
const int N = 1e7 + 5;
string s;
int T, sum[N], q;
inline int score(char c) {
    if (c == 'P') {
        return 3;
    }
    if (c == 'p') {
        return 2;
    }
    if (c == 'G') {
        return 1;
    }
    return 0;
}
signed main() {
    ios::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
    for (cin >> T; T--;) {
        cin >> s;
        int n = s.size();
        for (int i = 0; i < n; i++) {
            sum[i + 1] = sum[i] + score(s[i]);
        }
        cin >> q;
        for (int l, r; q--;) {
            cin >> l >> r;
            cout << sum[r] - sum[l - 1] << "\n";
        }
    }
    return 0;
}