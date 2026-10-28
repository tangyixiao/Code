#include <bits/stdc++.h>
using namespace std;

int n;

signed main() {
    cin >> n;
    for (int i = 1; i <= n; i++) {
        if (n % i == 0) {
            cout << i;
            if (i != n) {
                cout << " ";
            }
        }
    }
    cout << "\n";
    return 0;
}
