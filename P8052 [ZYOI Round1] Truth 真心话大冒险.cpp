#include <bits/stdc++.h>
using namespace std;
constexpr int N = 2e4 + 5;
int n, a[N], mx = 1, my = 2, ans[N];
inline int ask(int a, int b, int c) {
    int res;
    cout << "1 " << a << ' ' << b << ' ' << c << endl;
    cin >> res;
    return res;
}
inline int test(int a, int b) {
    int res;
    cout << "2 " << a << ' ' << b << endl;
    cin >> res;
    return res;
}
bool cmp(int a, int b) {
    return ask(ans[1], a, b) == a;
}
signed main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cin >> n;
    if (n == 1) {
        cout << "3 1" << endl;
        exit(0);
    }
    if (n == 2) {
        int res = test(1, 2);
        cout << "3 " << res << ' ' << ((res - 1) ^ 1) + 1 << endl;
        exit(0);
    }
    for (int i = 3, res; i <= n; i++) {
        res = ask(mx, my, i);
        if (res == mx) {
            mx = i;
        } else {
            if (res == my) {
                my = i;
            }
        }
    }
    ans[1] = test(mx, my), ans[n] = (mx != ans[1] ? mx : my);
    for (int i = 1, pos = 1; i <= n; i++) {
        if (i != mx && i != my) {
            ans[++pos] = i;
        }
    }
    sort(ans + 2, ans + n, cmp);
    cout << "3 ";
    for (int i = 1; i <= n; i++) {
        cout << ans[i] << " ";
    }
    cout << flush;
    return 0;
}
