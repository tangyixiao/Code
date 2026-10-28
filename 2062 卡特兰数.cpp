#include <bits/stdc++.h>
using namespace std;

int n;
long long c[25];

signed main() {
    ios::sync_with_stdio(false);
    cin.tie(0);
    cin >> n;
    c[0] = 1;
    for (int i = 1; i <= n; i++) {
        c[i] = 0;
        for (int j = 0; j < i; j++) {
            c[i] += c[j] * c[i - 1 - j];
        }
    }
    cout << c[n] << "\n";
    return 0;
}
