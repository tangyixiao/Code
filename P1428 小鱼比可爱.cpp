#include <bits/stdc++.h>
using namespace std;
const int N = 101;
int n, a[N], f[N];
signed main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cin >> n;
    for (int i = 1; i <= n; i++) {
        cin >> a[i];
        for (int j = 1; j < i; j++) {
            f[i] += (a[i] < a[j]);
        }
    }
    for (int i = 1; i <= n; i++) {
        cout << f[i] << " ";
    }
    return 0;
}