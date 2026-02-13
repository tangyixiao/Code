#include <bits/stdc++.h>
using namespace std;
int f[51114], w[35], v, n;
int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);
    cin >> v >> n;
    for (int i = 1; i <= n; i++) {
        cin >> w[i];
    }
    for (int i = 1; i <= n; i++) {
        for (int j = v; j >= w[i]; j--) {
            f[j] = max(f[j], f[j - w[i]] + w[i]);
        }
    }
    cout << v - f[v];
    return 0;
}