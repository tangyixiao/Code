#include <bits/stdc++.h>
using namespace std;
int n, a[11], ans[11];
int main() {
    cin >> n;
    for (int i = 1; i <= 7; i++) {
        cin >> a[i];
    }
    for (int i = 1, d; i <= n; i++) {
        d = 0;
        for (int j = 1, x; j <= 7; j++) {
            cin >> x;
            for (int k = 1; k <= 7; k++) {
                if (x == a[k]) {
                    d++;
                    break;
                }
            }
        }
        ans[d]++;
    }
    for (int i = 7; i >= 1; i--) {
        cout << ans[i] << ' ';
    }
    return 0;
}
