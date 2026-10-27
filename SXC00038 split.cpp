#include <bits/stdc++.h>
using namespace std;

const int N = 1e6 + 5;
int n, a[N];
long long s[N];

signed main() {
    ios::sync_with_stdio(false);
    cin.tie(0);
    cin >> n;
    for (int i = 1; i <= n; i++) {
        cin >> a[i];
        s[i] = s[i - 1] + a[i];
    }
    int f = 0;
    for (int i = 1; i < n; i++) {
        if (s[i] == s[n] - s[i]) {
            if (f) {
                cout << " ";
            }
            cout << i;
            f = 1;
        }
    }
    if (f) {
        cout << "\n";
    }
    return 0;
}
