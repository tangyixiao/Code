#include <bits/stdc++.h>
using namespace std;
signed main() {
    string s;
    cin >> s;

    int ans = 0;
    for (int i = 0; i <= 9999; ++i) {
        int cnt[10] = {0};
        cnt[(i / 1000)]++;
        cnt[((i / 100) % 10)]++;
        cnt[((i / 10) % 10)]++;
        cnt[(i % 10)]++;

        bool ok = true;
        for (int j = 0; j < 10; ++j) {
            if (s[j] == 'o' && cnt[j] == 0) {
                ok = false;
            }
            if (s[j] == 'x' && cnt[j] > 0) {
                ok = false;
            }
        }
        if (ok) {
            ans++;
        }
    }

    cout << ans;
    return 0;
}