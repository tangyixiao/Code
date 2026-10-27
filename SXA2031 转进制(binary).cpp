#include <bits/stdc++.h>
using namespace std;
char buf[64];
void out(unsigned long long v, int b, int up) {
    int t = 0, i;
    if (v == 0) {
        cout << "0\n";
        return;
    }
    while (v > 0) {
        int d = (int)(v % b);
        buf[t++] = d < 10 ? (char)('0' + d) : (char)((up ? 'A' : 'a') + d - 10);
        v /= b;
    }
    for (i = t - 1; i >= 0; i--) {
        cout << buf[i];
    }
    cout << "\n";
}
signed main() {
    long long n;
    unsigned long long v;
    cin >> n;
    if (n < 0) {
        v = 0ULL - (unsigned long long)n;
    } else {
        v = (unsigned long long)n;
    }
    if (n < 0) {
        cout << "-";
    }
    out(v, 2, 0);
    if (n < 0) {
        cout << "-";
    }
    out(v, 8, 0);
    if (n < 0) {
        cout << "-";
    }
    out(v, 16, 1);
    return 0;
}
