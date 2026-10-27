#include <bits/stdc++.h>
using namespace std;

signed main() {
    int t;
    cin >> t;
    for (int i = 1; i <= t; i++) {
        long long n, p = 3, k = 3;
        cin >> n;
        for (; p < n;) {
            p *= 2;
            k++;
        }
        cout << k << "\n";
    }
    return 0;
}
