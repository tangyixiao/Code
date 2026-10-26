#include <bits/stdc++.h>
using namespace std;

int n;

signed main() {
    cin >> n;
    for (int i = 1; i <= 10; i++) {
        for (int j = 1; j <= n; j++) {
            cout << "*";
        }
        cout << "\n";
    }
    return 0;
}
