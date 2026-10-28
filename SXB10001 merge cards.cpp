#include <bits/stdc++.h>
using namespace std;

int t, n;

signed main() {
    cin >> t;
    for (int i = 1; i <= t; i++) {
        cin >> n;
        if (n % 2 == 0) {
            cout << "Alice\n";
        } else {
            cout << "Bob\n";
        }
    }
    return 0;
}
