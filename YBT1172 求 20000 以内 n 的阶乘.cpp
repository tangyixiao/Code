#include <bits/stdc++.h>
using namespace std;

const int N = 8e4 + 5;

int a[N], n, l = 1;

signed main() {
    cin >> n;
    a[0] = 1;
    for (int i = 2; i <= n; i++) {
        long long t = 0;
        for (int j = 0; j < l; j++) {
            t += (long long)a[j] * i;
            a[j] = t % 10;
            t /= 10;
        }
        while (t) {
            a[l++] = t % 10;
            t /= 10;
        }
    }
    for (int i = l - 1; i >= 0; i--) {
        cout << a[i];
    }
    cout << "\n";
    return 0;
}
