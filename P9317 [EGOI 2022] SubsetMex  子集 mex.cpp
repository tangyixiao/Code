#include <bits/stdc++.h>
#define int long long
using namespace std;
const int N = 51;
int T, n, a[N];
int f(int i, int j) {
    return (!i ? 0 : (a[i] >= j ? f(i - 1, j) : f(i - 1, j + j - a[i]) + j - a[i]));
}
signed main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cin >> T;
    for (; T--;) {
        cin >> n;
        for (int i = 1; i <= n; i++) {
            cin >> a[i];
        }
        cout << f(n, 1) + 1 << "\n";
    }
    return 0;
}
