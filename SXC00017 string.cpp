#include <bits/stdc++.h>
using namespace std;

const int N = 55;
char s[N], t[N];
int p[N], tp[2];

signed main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    int T;
    cin >> T;
    for (; T; T--) {
        cin >> s >> t;
        int n = strlen(s);
        if (strcmp(s, t) == 0) {
            cout << 0 << "\n";
            continue;
        }
        int ans = -1;
        for (int k = 1; k <= n; k++) {
            if (strcmp(s + k, "") != 0 && strncmp(s + k, t, n - k) != 0) {
                continue;
            }
            vector<int> pos[2];
            for (int i = 0; i < k; i++) {
                pos[s[i] == 'o' ? 0 : 1].push_back(i);
            }
            bool ok = true;
            int p0 = 0, p1 = 0;
            for (int i = n - k; i < n; i++) {
                int c = t[i] == 'o' ? 0 : 1;
                if (c == 0) {
                    if (p0 == (int)pos[0].size()) {
                        ok = false;
                        break;
                    }
                    p[i - (n - k)] = pos[0][p0++];
                } else {
                    if (p1 == (int)pos[1].size()) {
                        ok = false;
                        break;
                    }
                    p[i - (n - k)] = pos[1][p1++];
                }
            }
            if (!ok) {
                continue;
            }
            int cnt = 0;
            for (int i = 0; i < k; i++) {
                int j = cnt - 1;
                for (; j >= 0; j--) {
                    if (tp[j] < p[i]) {
                        break;
                    }
                }
                if (j >= 0) {
                    tp[j] = p[i];
                } else if (cnt < 2) {
                    tp[cnt++] = p[i];
                    sort(tp, tp + cnt);
                } else {
                    ok = false;
                    break;
                }
            }
            if (!ok) {
                continue;
            }
            ans = 2 * k;
            break;
        }
        cout << ans << "\n";
    }
    return 0;
}
