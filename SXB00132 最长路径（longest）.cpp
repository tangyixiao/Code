#include <bits/stdc++.h>
using namespace std;

const int N = 105;

int n1, n2, i, j;
long long a[N], b[N], s1, s2, ans;

signed main() {
    cin >> n1;
    for (i = 1; i <= n1; i++) {
        cin >> a[i];
    }
    cin >> n2;
    for (i = 1; i <= n2; i++) {
        cin >> b[i];
    }
    i = 1, j = 1, s1 = 0, s2 = 0, ans = 0;
    for (; i <= n1 && j <= n2;) {
        if (a[i] < b[j]) {
            s1 += a[i], i++;
        } else if (a[i] > b[j]) {
            s2 += b[j], j++;
        } else {
            ans += max(s1, s2) + a[i], s1 = 0, s2 = 0, i++, j++;
        }
    }
    for (; i <= n1; i++) {
        s1 += a[i];
    }
    for (; j <= n2; j++) {
        s2 += b[j];
    }
    ans += max(s1, s2);
    cout << ans << "\n";
    return 0;
}
