#include <bits/stdc++.h>
using namespace std;

long long n, k, p;

signed main() {
    while (cin >> n) {
        if (n == 0) {
            break;
        }
        k = 0;
        p = 1;
        while (p < n) {
            p *= 3;
            k++;
        }
        cout << k << "\n";
    }
    return 0;
}
