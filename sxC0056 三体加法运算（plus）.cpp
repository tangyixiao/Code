#include <bits/stdc++.h>
using namespace std;

signed main() {
    int base;
    string a, b;
    cin >> base >> a >> b;
    int la = a.size(), lb = b.size(), L = max(la, lb) + 1;
    string r(L, '0');
    for (int i = 1; i <= L; i++) {
        int x = 0, y = 0;
        if (i <= la) {
            char c = a[la - i];
            x = c <= '9' ? c - '0' : c - 'A' + 10;
        }
        if (i <= lb) {
            char c = b[lb - i];
            y = c <= '9' ? c - '0' : c - 'A' + 10;
        }
        int s = x + y + (r[L - i] - '0');
        int d = s % base;
        r[L - i] = d < 10 ? (char)('0' + d) : (char)('A' + d - 10);
        if (s >= base) {
            r[L - i - 1] = '1';
        }
    }
    int p = 0;
    for (; p < L - 1; p++) {
        if (r[p] != '0') {
            break;
        }
    }
    cout << r.substr(p) << "\n";
    return 0;
}
