#include <bits/stdc++.h>
using namespace std;
const int N = 1e6 + 15;
struct node {
    int l, st, en;
} s[N];
int a[N], n, ln, t, mx, cnt, ans;
int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);
    cin >> n, t = 1;
    for (int i = 1; i <= n; i++) {
        cin >> a[i];
        if (mx < a[i]) {
            ln++;
            mx = a[i];
        } else {
            s[++cnt].st = t;
            s[cnt].en = i - 1;
            s[cnt].l = ln;
            ln = 1;
            mx = a[i];
            t = i;
        }
    }
    if (s[cnt].en != n) {
        s[++cnt].st = t;
        s[cnt].en = n;
        s[cnt].l = ln;
    }
    if (cnt == 1) {
        cout << n;
        exit(0);
    }
    for (int i = 1; i <= cnt; i++) {
        ans = max(ans, s[i].l + 1);
    }
    for (int i = 2; i <= cnt; i++) {
        if (a[s[i].st + 1] - a[s[i - 1].en] > 1 || a[s[i].st] - a[s[i - 1].en - 1] > 1) {
            ans = max(ans, s[i].l + s[i - 1].l);
        }
    }
    cout << ans;
    return 0;
}