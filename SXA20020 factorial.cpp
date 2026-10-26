#include <bits/stdc++.h>
using namespace std;

const int N = 1e5 + 5;
int n, len, a[N];

signed main() {
    cin >> n;
    a[0] = 1, len = 1;
    for (int i = 2; i <= n; i++) {
        int c = 0;
        for (int j = 0; j < len; j++) {
            int v = a[j] * i + c;
            a[j] = v % 10;
            c = v / 10;
        }
        for (; c;) {
            a[len++] = c % 10;
            c /= 10;
        }
    }
    for (int i = len - 1; i >= 0; i--) {
        cout << a[i];
    }
    cout << "\n";
    return 0;
}
