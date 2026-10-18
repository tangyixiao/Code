#include <bits/stdc++.h>
using namespace std;
const int N = 50 + 5;
int n, na, nb;
double a[N], b[N], h[2][N];
string s;

inline void input() {
    cin >> n;
    for (int i = 1; i <= n; i++) {
        cin >> s >> h[0][i];
        if (s == "male") {
            a[++na] = h[0][i];
        } else {
            b[++nb] = h[0][i];
        }
    }
}

inline void solve() {
    sort(a + 1, a + na + 1);
    sort(b + 1, b + nb + 1, greater<double>());
    for (int i = 1; i <= na; i++) {
        h[1][i] = a[i];
    }
    for (int i = 1; i <= nb; i++) {
        h[1][na + i] = b[i];
    }
    for (int i = 1; i <= n; i++) {
        cout << fixed << setprecision(2) << h[1][i] << (i == n ? "\n" : " ");
    }
    return;
}

signed main() {
    input(), solve();
    return 0;
}