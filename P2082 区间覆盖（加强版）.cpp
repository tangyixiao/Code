#include <bits/stdc++.h>
using namespace std;
long long int n, l[100010], r[100010], ans = 0;
int main() {
    cin >> n;
    for (int i = 1; i <= n; i++) {
        cin >> l[i] >> r[i];
    }
    sort(l + 1, l + 1 + n);
    sort(r + 1, r + 1 + n);
    for (int i = 1; i <= n; i++) {
        if (l[i] <= r[i - 1]) {
            ans += r[i] - r[i - 1];
        } else {
            ans += r[i] - l[i] + 1;
        }
    }
    cout << ans;
    return 0;
}
