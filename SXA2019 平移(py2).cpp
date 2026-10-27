#include <bits/stdc++.h>
using namespace std;

int a[15];

signed main() {
    for (int i = 0; i < 10; i++) {
        cin >> a[i];
    }
    for (int k = 1; k <= 10; k++) {
        for (int i = 0; i < 10; i++) {
            int p = (i - k + 100) % 10;
            if (i > 0) {
                cout << " ";
            }
            cout << a[p];
        }
        cout << "\n";
    }
    return 0;
}
