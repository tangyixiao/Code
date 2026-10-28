#include <bits/stdc++.h>
using namespace std;

const int N = 1e3 + 5;
int n, a[N];

signed main() {
    cin >> n;
    int p = 0;
    for (int i = 1; i <= n; i++) {
        cin >> a[i];
        if (a[i] > a[p]) {
            p = i;
        }
    }
    if (a[p] % 2 == 0) {
        a[p] *= 2;
    } else {
        a[p]++;
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
