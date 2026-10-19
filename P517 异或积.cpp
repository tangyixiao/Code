#include <bits/stdc++.h>
using namespace std;

const int N = 1e5 + 5;

int n, i;
long long k, s;
int a[N];

signed main() {
    int t;
    cin >> t;
    while (t--) {
        cin >> n >> k;
        s = 0;
        for (i = 0; i < n; i++) {
            cin >> a[i];
            s ^= a[i];
        }
        if (k % 2 == 0) {
            for (i = 0; i < n; i++) {
                cout << a[i] << (i + 1 == n ? "\n" : " ");
            }
            continue;
        }
        for (i = 0; i < n; i++) {
            cout << (s ^ a[i]) << (i + 1 == n ? "\n" : " ");
        }
    }
    return 0;
}