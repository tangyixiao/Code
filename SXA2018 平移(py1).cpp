#include <bits/stdc++.h>
using namespace std;

int a[11];

signed main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    for (int i = 1; i <= 10; i++) {
        cin >> a[i];
    }
    for (int k = 1; k <= 10; k++) {
        for (int i = 1; i <= 10; i++) {
            int id = (k + i - 1) % 10 + 1;
            cout << a[id];
            if (i < 10) {
                cout << " ";
            }
        }
        cout << "\n";
    }
    return 0;
}
