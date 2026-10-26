#include <bits/stdc++.h>
using namespace std;
const int N = 1e5 + 5;
long long a[N], ans = 0;
int st[N], top = 0, n, i;
signed main() {
    cin >> n;
    for (i = 1; i <= n; i++) {
        cin >> a[i];
    }
    a[n + 1] = 0;
    for (i = 1; i <= n + 1; i++) {
        while (top > 0 && a[st[top]] >= a[i]) {
            int j = st[top--];
            long long w = i - st[top] - 1, s = a[j] * w;
            if (s > ans) {
                ans = s;
            }
        }
        st[++top] = i;
    }
    cout << ans << "\n";
    return 0;
}
