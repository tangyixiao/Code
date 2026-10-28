#include <bits/stdc++.h>
using namespace std;

char s[1005];
int a[1005], r[3005];

signed main() {
    int b, n, i, j, t, c;
    cin >> s >> b;
    n = strlen(s);
    for (i = 0; i < n; i++) {
        a[i] = s[n - 1 - i] - '0';
    }
    c = 0;
    for (i = 0; i < n; i++) {
        t = a[i] * b + c;
        r[i] = t % 10;
        c = t / 10;
    }
    j = n;
    for (; c > 0;) {
        r[j++] = c % 10;
        c /= 10;
    }
    for (i = j - 1; i > 0 && r[i] == 0; i--) {
    }
    for (; i >= 0; i--) {
        cout << r[i];
    }
    cout << "\n";
    return 0;
}
