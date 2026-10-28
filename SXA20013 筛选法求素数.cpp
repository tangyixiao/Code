#include <bits/stdc++.h>
using namespace std;

int n;
bool f[50005];

signed main() {
    cin >> n;
    for (int i = 2; i <= n; i++) {
        f[i] = true;
    }
    for (int i = 2; i * i <= n; i++) {
        if (f[i]) {
            for (int j = i * i; j <= n; j += i) {
                f[j] = false;
            }
        }
    }
    for (int i = 2; i <= n; i++) {
        if (f[i]) {
            cout << i << "\n";
        }
    }
    return 0;
}
