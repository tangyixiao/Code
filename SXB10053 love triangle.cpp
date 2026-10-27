#include <bits/stdc++.h>
using namespace std;

const int N = 1e5 + 5;

int n, i, j, k;
int a[N];

signed main() {
    ios::sync_with_stdio(false);
    cin.tie(0);
    cin >> n;
    for (i = 1; i <= n; i++) {
        cin >> a[i];
    }
    for (i = 1; i <= n; i++) {
        j = a[i];
        if (j == i) {
            continue;
        }
        k = a[j];
        if (k != i && k != j && a[k] == i) {
            cout << "YES\n";
            return 0;
        }
    }
    cout << "NO\n";
    return 0;
}
