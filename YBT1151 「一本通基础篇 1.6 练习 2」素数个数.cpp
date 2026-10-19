#include <bits/stdc++.h>
using namespace std;

const int N = 1e5 + 5;

bool pd(int p) {
    for (int i = 2; i * i <= p; i++) {
        if (p % i == 0) {
            return false;
        }
    }
    return true;
}

signed main() {
    int n;
    cin >> n;
    int c = 0;
    for (int i = 2; i <= n; i++) {
        c += pd(i);
    }
    cout << c << "\n";
    return 0;
}
