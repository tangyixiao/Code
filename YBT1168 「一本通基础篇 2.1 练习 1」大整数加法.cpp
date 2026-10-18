#include <bits/stdc++.h>
using namespace std;

const int N = 2.5e2 + 5;

char a[N], b[N], c[N];

signed main() {
    cin >> a >> b;
    int la = strlen(a), lb = strlen(b), n = max(la, lb) + 1, t = 0;
    for (int i = 0; i < n; i++) {
        t = (i < la ? a[la - 1 - i] - '0' : 0) + (i < lb ? b[lb - 1 - i] - '0' : 0) + t;
        c[n - 1 - i] = t % 10 + '0';
        t /= 10;
    }
    int p = 0;
    while (p < n - 1 && c[p] == '0') {
        p++;
    }
    cout << c + p << "\n";
    return 0;
}
