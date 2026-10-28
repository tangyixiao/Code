#include <bits/stdc++.h>
using namespace std;

int n, cnt[25];

signed main() {
    char tp;
    cin >> tp >> n;
    int cap = 2;
    if (tp == 'B') {
        cap = 4;
    }
    if (tp == 'C') {
        cap = 8;
    }
    for (int i = 0; i < n; i++) {
        int s, e;
        cin >> s >> e;
        for (int t = s; t < e; t++) {
            if (t >= 6 && t <= 22) {
                cnt[t]++;
            }
        }
    }
    int ok = 0;
    for (int t = 6; t < 22;) {
        if (cnt[t] < cap) {
            int s = t;
            for (; t < 22 && cnt[t] < cap;) {
                t++;
            }
            cout << s << " " << t << "\n";
            ok = 1;
        } else {
            t++;
        }
    }
    if (ok == 0) {
        cout << "NO\n";
    }
    return 0;
}
