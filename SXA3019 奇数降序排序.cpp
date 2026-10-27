#include <bits/stdc++.h>
using namespace std;

int a[15], b[15], c, x;

signed main() {
    for (int i = 1; i <= 10; i++) {
        cin >> x;
        if (x % 2 == 1) {
            b[++c] = x;
        }
    }
    sort(b + 1, b + c + 1, greater<int>());
    for (int i = 1; i <= c; i++) {
        cout << b[i];
        if (i < c) {
            cout << " ";
        }
    }
    cout << "\n";
    return 0;
}
