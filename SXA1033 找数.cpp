#include <bits/stdc++.h>
using namespace std;

int n, first = 1;

signed main() {
    cin >> n;
    for (int i = 100; i <= n; i++) {
        bool a = i % 5 == 0, b = i % 6 == 0;
        if (a != b) {
            if (!first) {
                cout << " ";
            }
            first = 0;
            cout << i;
        }
    }
    cout << "\n";
    return 0;
}
