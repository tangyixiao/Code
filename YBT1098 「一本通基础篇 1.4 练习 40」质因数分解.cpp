#include <bits/stdc++.h>
using namespace std;

signed main() {
    int n;
    cin >> n;
    for (int i = 2; i <= n / i + 1; i++) {
        if (n % i == 0) {
            cout << n / i << "\n";
            return 0;
        }
    }
    return 0;
}
