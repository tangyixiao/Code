#include <bits/stdc++.h>
using namespace std;

const int MOD = 1e9 + 7;

int m, n;
vector<string> s;
int cnt[60], v[60];

int idx(char ch) {
    if (ch >= 'a' && ch <= 'z') {
        return ch - 'a';
    }
    return ch - 'A' + 26;
}

signed main() {
    cin >> m >> n;
    s.resize(m);
    for (int i = 0; i < m; i++) {
        cin >> s[i];
    }
    long long ans = m % MOD, base = 1;
    for (int p = n - 1; p >= 0; p--) {
        for (int c = 0; c < 60; c++) {
            cnt[c] = 0;
        }
        for (int i = 0; i < m; i++) {
            cnt[idx(s[i][p])]++;
        }
        int k = 0;
        for (int c = 0; c < 60; c++) {
            if (cnt[c] > 0) {
                v[k] = cnt[c];
                k++;
            }
        }
        sort(v, v + k, greater<int>());
        long long sum = 0;
        for (int i = 0; i < k; i++) {
            sum += (long long)i * v[i];
        }
        ans = (ans + base * (sum % MOD)) % MOD;
        base = base * 50 % MOD;
    }
    cout << ans << "\n";
    return 0;
}
