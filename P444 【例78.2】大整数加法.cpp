#include <bits/stdc++.h>
using namespace std;

const int N = 205;
char a[N], b[N];
int la, lb, c[N], n;

signed main() {
    cin >> a >> b;
    la = strlen(a), lb = strlen(b);
    n = max(la, lb);
    for (int i = 0; i < n; i++) {
        int x = i < la ? a[la - 1 - i] - '0' : 0, y = i < lb ? b[lb - 1 - i] - '0' : 0;
        c[i] = x + y;
    }
    for (int i = 0; i < n; i++) {
        if (i + 1 < n) {
            c[i + 1] += c[i] / 10;
        }
        c[i] %= 10;
    }
    int t = n - 1;
    for (; t > 0 && c[t] == 0; t--) {
    }
    for (; t >= 0; t--) {
        cout << c[t];
    }
    cout << "\n";
    return 0;
}
