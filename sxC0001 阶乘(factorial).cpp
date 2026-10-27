#include <bits/stdc++.h>
using namespace std;

const int N = 3e3 + 5;
int n, len = 1, a[N];

signed main() {
    cin >> n;
    a[1] = 1;
    for (int i = 2; i <= n; i++) {
        int c = 0;
        for (int j = 1; j <= len; j++) {
            int t = a[j] * i + c;
            a[j] = t % 10;
            c = t / 10;
        }
        while (c) {
            a[++len] = c % 10;
            c /= 10;
        }
    }
    for (int i = len; i >= 1; i--) {
        cout << a[i];
    }
    cout << "\n";
    return 0;
}
