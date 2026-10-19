#include <bits/stdc++.h>
using namespace std;

const int N = 1e3 + 5;

char l[N], t[3][N], ex[N], op;
int n;
long long x, y, r;

inline void input() {
    cin >> n;
    cin.getline(l, sizeof(l));
    return;
}

inline void solve() {
    char s;
    for (int i = 1; i <= n; i++) {
        cin.getline(l, sizeof(l));
        int m = strlen(l);
        while (m && (l[m - 1] == '\r' || l[m - 1] == ' ')) {
            l[--m] = '\0';
        }
        int p = 0, c = 0;
        while (p < m && c < 3) {
            while (p < m && l[p] == ' ') {
                p++;
            }
            int q = 0;
            while (p < m && l[p] != ' ') {
                t[c][q++] = l[p];
                p++;
            }
            t[c][q] = '\0';
            c++;
        }
        if (c == 3) {
            op = t[0][0];
        }
        x = atoll(t[c - 2]), y = atoll(t[c - 1]);
        if (op == 'a') {
            r = x + y;
        } else if (op == 'b') {
            r = x - y;
        } else {
            r = x * y;
        }
        s = op == 'a' ? '+' : (op == 'b' ? '-' : '*');
        sprintf(ex, "%lld%c%lld=%lld", x, s, y, r);
        cout << ex << "\r\n"
             << strlen(ex);
        if (i < n) {
            cout << "\r\n";
        }
    }
    return;
}

signed main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    input();
    solve();
    return 0;
}
