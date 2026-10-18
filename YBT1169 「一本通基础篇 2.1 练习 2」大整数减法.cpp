#include <bits/stdc++.h>
using namespace std;

const int N = 2e2 + 5;

char a[N], b[N], c[N];

signed main() {
    cin >> a >> b;
    int la = strlen(a), lb = strlen(b), t = 0;
    for (int i = 0; i < la; i++) {
        int x = a[la - 1 - i] - '0' - (i < lb ? b[lb - 1 - i] - '0' : 0) - t;
        c[la - 1 - i] = (x + 10) % 10 + '0';
        t = x < 0;
    }
    int p = 0;
    while (p < la - 1 && c[p] == '0') {
        p++;
    }
    cout << c + p << "\n";
    return 0;
}
