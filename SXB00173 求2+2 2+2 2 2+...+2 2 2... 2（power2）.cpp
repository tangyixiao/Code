#include <bits/stdc++.h>
using namespace std;

const int N = 2e2 + 5;
int n, len, a[N];

signed main() {
    cin >> n;
    a[1] = 1;
    len = 1;
    for (int i = 1; i <= n + 1; i++) {
        int c = 0;
        for (int j = 1; j <= len; j++) {
            int t = a[j] * 2 + c;
            a[j] = t % 10;
            c = t / 10;
        }
        while (c) {
            a[++len] = c % 10;
            c /= 10;
        }
    }
    a[1] -= 2;
    for (int i = len; i >= 1; i--) {
        cout << a[i];
    }
    cout << "\n";
    return 0;
}
