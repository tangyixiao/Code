#include <bits/stdc++.h>
using namespace std;

int n;

signed main() {
    cin >> n;
    for (int i = 2; i <= n; i += 2) {
        for (int j = i; j <= n - i; j += 2) {
            int k = n - i - j;
            if (k % 2 == 0 && j <= k) {
                cout << i << " " << j << " " << k << "\n";
            }
        }
    }
    return 0;
}
