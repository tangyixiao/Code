#include <bits/stdc++.h>
using namespace std;

int n;

signed main() {
    cin >> n;
    cout << fixed << setprecision(1);
    if (n >= 10) {
        cout << n * 1.2 << "\n";
    } else {
        cout << n * 1.5 << "\n";
    }
    return 0;
}
