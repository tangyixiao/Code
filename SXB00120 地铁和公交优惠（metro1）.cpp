#include <bits/stdc++.h>
using namespace std;

const int N = 1e5 + 5;

int n, ans, hd = 1, tl = 0;
int ty[N], pr[N], ti[N], p[N];
int ct[N], cv[N];

bool cmp(int x, int y) {
    return ti[x] < ti[y];
}

signed main() {
    cin >> n;
    for (int i = 1; i <= n; i++) {
        cin >> ty[i] >> pr[i] >> ti[i];
        p[i] = i;
    }
    sort(p + 1, p + n + 1, cmp);
    for (int i = 1; i <= n; i++) {
        int x = p[i];
        if (ty[x] == 0) {
            ans += pr[x];
            tl++;
            ct[tl] = ti[x];
            cv[tl] = pr[x];
            continue;
        }
        for (; hd <= tl; hd++) {
            if (ti[x] - ct[hd] <= 45) {
                break;
            }
        }
        int pick = 0;
        for (int j = hd; j <= tl; j++) {
            if (ct[j] < 0 || ti[x] - ct[j] > 45 || cv[j] < pr[x]) {
                continue;
            }
            pick = j;
            break;
        }
        if (pick) {
            ct[pick] = -1;
        } else {
            ans += pr[x];
        }
    }
    cout << ans << "\n";
    return 0;
}
