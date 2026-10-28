#include <bits/stdc++.h>
using namespace std;

int n, a;
long long s;

signed main() {
    cin >> n;
    for (int i = 1; i <= n; i++) {
        cin >> a;
        s += a;
    }
    if (s >= 100) {
        cout << "yes" << "\n";
    } else {
        cout << "no" << "\n";
    }
    return 0;
}
