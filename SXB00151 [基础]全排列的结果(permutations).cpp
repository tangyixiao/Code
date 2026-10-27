#include <bits/stdc++.h>
using namespace std;

int n, a[10];

signed main() {
    cin >> n;
    for (int i = 1; i <= n; i++) {
        a[i] = i;
    }
    for (; next_permutation(a + 1, a + n + 1);) {
    }
    reverse(a + 1, a + n + 1);
    for (; prev_permutation(a + 1, a + n + 1);) {
        for (int i = 1; i <= n; i++) {
            if (i > 1) {
                cout << " ";
            }
            cout << a[i];
        }
        cout << "\n";
    }
    for (int i = 1; i <= n; i++) {
        if (i > 1) {
            cout << " ";
        }
        cout << a[i];
    }
    cout << "\n";
    return 0;
}
