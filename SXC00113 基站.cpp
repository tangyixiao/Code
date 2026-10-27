#include <bits/stdc++.h>
using namespace std;
const int N = 1e5 + 5;
int n;
double px[N], py[N];

struct seg {
    double l, r;
} a[N];

bool operator<(const seg &x, const seg &y) {
    return x.r < y.r;
}

signed main() {
    double L, D;
    int i, cnt;
    string s;
    while (cin >> L) {
        cin >> D;
        cin >> n;
        cnt = 0;
        for (i = 1; i <= n; i++) {
            cin >> px[i] >> py[i];
            double t = D * D - py[i] * py[i];
            if (t < 0) {
                continue;
            }
            double w = sqrt(t);
            cnt++;
            a[cnt].l = px[i] - w;
            a[cnt].r = px[i] + w;
        }
        sort(a + 1, a + cnt + 1);
        int ans = 0;
        double cur = -1e18;
        for (i = 1; i <= cnt; i++) {
            if (a[i].l > cur) {
                ans++;
                cur = a[i].r;
            }
        }
        cout << ans << "\n";
    }
    return 0;
}
