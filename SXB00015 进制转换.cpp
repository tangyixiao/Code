#include <bits/stdc++.h>
using namespace std;

int a, b, i;
long long v;
char s[64], out[64];

signed main() {
    cin >> a >> b;
    cin >> s;
    v = 0;
    for (i = 0; s[i]; i++) {
        int d;
        if (s[i] >= '0' && s[i] <= '9') {
            d = s[i] - '0';
        } else {
            d = s[i] - 'A' + 10;
        }
        v = v * a + d;
    }
    if (v == 0) {
        cout << "0\n";
        return 0;
    }
    int k = 0;
    while (v > 0) {
        out[k] = "0123456789ABCDEF"[v % b];
        v /= b;
        k++;
    }
    for (i = k - 1; i >= 0; i--) {
        cout << out[i];
    }
    cout << "\n";
    return 0;
}
