#include <bits/stdc++.h>
using namespace std;

char s[100005];

signed main() {
    cin >> s;
    int mx = 0;
    for (int i = 0; s[i]; i++) {
        int v;
        if (s[i] >= '0' && s[i] <= '9') {
            v = s[i] - '0';
        } else {
            v = s[i] - 'A' + 10;
        }
        if (v > mx) {
            mx = v;
        }
    }
    int ans = mx + 1;
    if (ans < 2) {
        ans = 2;
    }
    cout << ans << "\n";
    return 0;
}
