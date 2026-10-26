#include <bits/stdc++.h>
using namespace std;
string a, b;
int c[305], i, la, lb, len;
signed main() {
    cin >> a >> b;
    la = a.size();
    lb = b.size();
    len = max(la, lb);
    for (i = 0; i < len; i++) {
        if (i < la) {
            c[i] += a[la - 1 - i] - '0';
        }
        if (i < lb) {
            c[i] += b[lb - 1 - i] - '0';
        }
        c[i + 1] += c[i] / 10;
        c[i] %= 10;
    }
    i = len + 1;
    while (i > 0 && c[i] == 0) {
        i--;
    }
    for (; i >= 0; i--) {
        cout << c[i];
    }
    cout << "\n";
    return 0;
}
