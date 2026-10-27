#include <bits/stdc++.h>
using namespace std;

const int N = 105;

int n, i;
int a[N];

signed main() {
    cin >> n;
    for (i = 1; i <= n; i++) {
        cin >> a[i];
    }
    for (i = 1; i <= n; i += 2) {
        if (i > 1) {
            cout << " ";
        }
        cout << a[i];
    }
    cout << "\n";
    return 0;
}
