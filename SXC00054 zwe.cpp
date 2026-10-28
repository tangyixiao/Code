#include <bits/stdc++.h>
using namespace std;
const int N = 1e3 + 5;
string s[N];
int id[N], len[N], n, i, k, m, ml, t;
int cmp(int x, int y) {
    return s[x] < s[y];
}
signed main() {
    cin >> n;
    for (i = 1; i <= n; i++) {
        cin >> s[i];
        id[i] = i;
    }
    sort(id + 1, id + n + 1, cmp);
    for (i = 1; i <= n; i++) {
        ml = 0;
        for (k = i - 1; k <= i + 1; k += 2) {
            if (k < 1 || k > n) {
                continue;
            }
            m = 0;
            while (m < (int)s[id[i]].size() && m < (int)s[id[k]].size() && s[id[i]][m] == s[id[k]][m]) {
                m++;
            }
            if (m > ml) {
                ml = m;
            }
        }
        len[id[i]] = ml + 1;
    }
    for (i = 1; i <= n; i++) {
        cout << s[i].substr(0, len[i]) << "\n";
    }
    return 0;
}
