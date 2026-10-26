#include <bits/stdc++.h>
using namespace std;

int n, i, d;
char s[64], t[64];
int a[64], b[64];

signed main() {
    cin >> n;
    cin >> s;
    d = strlen(s);
    for (i = 0; i < d; i++) {
        if (s[i] >= '0' && s[i] <= '9') {
            a[i] = s[i] - '0';
        } else {
            a[i] = s[i] - 'A' + 10;
        }
    }
    for (int step = 1; step <= 30; step++) {
        bool ok = true;
        for (i = 0; i < d; i++) {
            if (a[i] != a[d - 1 - i]) {
                ok = false;
            }
        }
        if (ok) {
            cout << step - 1 << "\n";
            return 0;
        }
        for (i = 0; i < d; i++) {
            t[i] = a[i];
        }
        int c = 0;
        for (i = 0; i < d; i++) {
            int v = a[i] + a[d - 1 - i] + c;
            b[i] = v % n;
            c = v / n;
        }
        for (i = 0; i < d; i++) {
            cout << "0123456789ABCDEF"[a[i]];
        }
        cout << "+";
        for (i = d - 1; i >= 0; i--) {
            cout << "0123456789ABCDEF"[t[i]];
        }
        cout << "=";
        int nd = d;
        if (c > 0) {
            b[d] = c;
            nd = d + 1;
        }
        for (i = nd - 1; i >= 0; i--) {
            cout << "0123456789ABCDEF"[b[i]];
        }
        cout << "\n";
        for (i = 0; i < nd; i++) {
            a[i] = b[i];
        }
        d = nd;
    }
    cout << "Impossible\n";
    return 0;
}
