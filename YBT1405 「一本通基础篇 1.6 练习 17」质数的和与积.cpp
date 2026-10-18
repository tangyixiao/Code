#include <bits/stdc++.h>
using namespace std;

const int N = 1e4 + 5;

bool pd(int p) {
    if (p < 2) {
        return false;
    }
    for (int i = 2; i * i <= p; i++) {
        if (p % i == 0) {
            return false;
        }
    }
    return true;
}

signed main() {
    int s;
    cin >> s;
    for (int i = s / 2; i >= 2; i--) {
        if (pd(i) && pd(s - i)) {
            cout << i * (s - i) << "\n";
            return 0;
        }
    }
    return 0;
}
