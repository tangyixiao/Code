#include <bits/stdc++.h>
using namespace std;

int n;

signed main() {
    cin >> n;
    bool f = n > 1;
    for (int i = 2; i * i <= n; i++) {
        if (n % i == 0) {
            f = false;
        }
    }
    cout << (f ? "Y" : "N") << "\n";
    return 0;
}