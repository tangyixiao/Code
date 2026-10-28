#include <bits/stdc++.h>
using namespace std;

const int N = 1e5 + 5;

int base, la, lb, i, j, d, c;
char sa[N], sb[N];
int ra[N], rb[N], rr[N];

signed main() {
    cin >> base;
    cin >> sa;
    cin >> sb;
    la = strlen(sa);
    lb = strlen(sb);
    for (i = 0; i < la; i++) {
        d = sa[la - 1 - i];
        if (d >= '0' && d <= '9') {
            ra[i] = d - '0';
        } else {
            ra[i] = d - 'A' + 10;
        }
    }
    for (i = 0; i < lb; i++) {
        d = sb[lb - 1 - i];
        if (d >= '0' && d <= '9') {
            rb[i] = d - '0';
        } else {
            rb[i] = d - 'A' + 10;
        }
    }
    int len = max(la, lb);
    c = 0;
    for (i = 0; i < len; i++) {
        int x = 0, y = 0;
        if (i < la) {
            x = ra[i];
        }
        if (i < lb) {
            y = rb[i];
        }
        int s = x + y + c;
        rr[i] = s % base;
        c = s / base;
    }
    while (c > 0) {
        rr[len] = c % base;
        c /= base;
        len++;
    }
    while (len > 1 && rr[len - 1] == 0) {
        len--;
    }
    for (i = len - 1; i >= 0; i--) {
        if (rr[i] < 10) {
            cout << (char)('0' + rr[i]);
        } else {
            cout << (char)('A' + rr[i] - 10);
        }
    }
    cout << "\n";
    return 0;
}
