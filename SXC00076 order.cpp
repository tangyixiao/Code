#include <bits/stdc++.h>
using namespace std;

const int MOD = 1e9 + 7;

int m, n;
vector<string> s;
int f[52];

signed main() {
    ios::sync_with_stdio(false);
    cin.tie(0);
    cin >> m >> n;
    s.resize(m);
    for (int i = 0; i < m; i++) {
        cin >> s[i];
    }
    long long ans = m % MOD, p = 1;
    for (int i = n - 1; i >= 0; i--) {
        for (int c = 0; c < 52; c++) {
            f[c] = 0;
        }
        for (int j = 0; j < m; j++) {
            char ch = s[j][i];
            int id;
            if (ch >= 'a' && ch <= 'z') {
                id = ch - 'a';
            } else {
                id = 26 + ch - 'A';
            }
            if (id < 0 || id > 51) {
                id = 51;
            }
            f[id]++;
        }
        sort(f, f + 52, greater<int>());
        long long cur = 0;
        for (int r = 0; r < 52; r++) {
            cur += (long long)r * f[r];
        }
        ans = (ans + p * (cur % MOD)) % MOD;
        p = p * 50 % MOD;
    }
    cout << ans << "\n";
    return 0;
}
