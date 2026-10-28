#include <bits/stdc++.h>
using namespace std;
const int N = 1e4 + 5;
int n, i, j, p;
long long a[N];
long long v[N];
int c[N];
signed main() {
    cin >> n;
    for (i = 1; i <= n; i++) {
        cin >> a[i];
    }
    p = 0;
    for (i = 1; i <= n; i = j) {
        for (j = i; j <= n && a[j] == a[i]; j++) {
        }
        p++;
        v[p] = a[i], c[p] = j - i;
    }
    for (i = 1; i <= p; i++) {
        if (i > 1) {
            cout << " ";
        }
        cout << v[i];
    }
    cout << "\n";
    for (i = 1; i <= p; i++) {
        if (i > 1) {
            cout << " ";
        }
        cout << c[i];
    }
    cout << "\n";
    return 0;
}
