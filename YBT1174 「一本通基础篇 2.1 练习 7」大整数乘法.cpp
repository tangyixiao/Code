#include <bits/stdc++.h>
using namespace std;

const int N = 2e2 + 5, M = 4e2 + 5;

char a[N], b[N];
int c[M], la, lb, lc;

signed main() {
    cin >> a >> b;
    la = strlen(a);
    lb = strlen(b);
    for (int i = 0; i < la; i++) {
        for (int j = 0; j < lb; j++) {
            c[i + j] += (a[la - 1 - i] - '0') * (b[lb - 1 - j] - '0');
        }
    }
    lc = la + lb;
    for (int i = 0; i < lc; i++) {
        c[i + 1] += c[i] / 10;
        c[i] %= 10;
    }
    int p = lc - 1;
    for (; p > 0 && c[p] == 0; p--) {
    }
    for (int i = p; i >= 0; i--) {
        cout << c[i];
    }
    cout << "\n";
    return 0;
}
