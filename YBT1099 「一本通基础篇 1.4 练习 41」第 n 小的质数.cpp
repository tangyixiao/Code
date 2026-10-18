#include <bits/stdc++.h>
using namespace std;

inline bool pd(int p) {
    for (int i = 2; i * i <= p; i++) {
        if (p % i == 0) {
            return false;
        }
    }
    return true;
}

signed main() {
    int n, c = 0;
    cin >> n;
    for (int i = 2;; i++) {
        if (pd(i) && ++c == n) {
            cout << i << "\n";
            return 0;
        }
    }
    return 0;
}
