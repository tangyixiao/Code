#include <bits/stdc++.h>
#define int long long
using namespace std;
int a, b, k, c[61][61];

string ans;
signed main() {
    for (int i = 0; i <= 60; ++i) {
        c[i][0] = c[i][i] = 1;
        for (int j = 1; j < i; ++j) {
            c[i][j] = c[i - 1][j - 1] + c[i - 1][j];
        }
    }
    cin >> a >> b >> k;

    for (; a > 0 && b > 0;) {
        int cnt = c[a + b - 1][a - 1];
        if (k <= cnt) {
            ans += 'a';
            a--;
        } else {
            ans += 'b';
            k -= cnt;
            b--;
        }
    }
    for (int i = 0; i < a; i++) {
        ans += 'a';
    }

    for (int i = 0; i < b; i++) {
        ans += 'b';
    }

    cout << ans;
    return 0;
}