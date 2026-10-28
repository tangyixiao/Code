#include <bits/stdc++.h>
using namespace std;

int a[15], i;

signed main() {
    for (i = 1; i <= 10; i++) {
        cin >> a[i];
    }
    for (i = 10; i >= 1; i--) {
        cout << a[i];
        if (i > 1) {
            cout << " ";
        }
    }
    cout << "\n";
    return 0;
}
