#include <bits/stdc++.h>
using namespace std;

const int N = 1e4 + 5;
int n, a[N];
long long ans;

signed main() {
    cin >> n;
    for (int i = 1; i <= n; i++) {
        cin >> a[i];
    }
    for (int i = 1; i <= n; i++) {
        for (int j = i + 1; j <= n; j++) {
            if (a[i] > a[j]) {
                ans++;
            }
        }
    }
    cout << ans << "\n";
    return 0;
}
