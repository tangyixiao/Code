#include <bits/stdc++.h>
using namespace std;

const int N = 2e5 + 5;
int n, k, i, c, o, r, ans;
int cnt[N];
char s[N];

signed main() {
    ios::sync_with_stdio(false);
    cin.tie(0);
    cin >> n >> k;
    cin >> (s + 1);
    for (i = 1; i <= n; i++) {
        cnt[s[i] - 'a']++;
    }
    for (i = 0; i < 26; i++) {
        c += cnt[i] / 2;
    }
    for (i = 0; i < 26; i++) {
        if (cnt[i] % 2 == 1) {
            o++;
        }
    }
    r = c % k;
    ans = 2 * (c / k);
    if (2 * r + o >= k) {
        ans++;
    }
    cout << ans << "\n";
    return 0;
}
