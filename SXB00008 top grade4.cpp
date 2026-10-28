#include <bits/stdc++.h>
using namespace std;

int n, m, k, a[105], s[105], id[105];

signed main() {
    cin >> n >> m >> k;
    for (int i = 1; i <= n; i++) {
        id[i] = i;
        for (int j = 0; j < m; j++) {
            int v;
            cin >> v;
            s[i] += v;
        }
    }
    for (int i = 1; i <= n; i++) {
        for (int j = i + 1; j <= n; j++) {
            if (s[i] < s[j] || (s[i] == s[j] && id[i] > id[j])) {
                swap(s[i], s[j]);
                swap(id[i], id[j]);
            }
        }
    }
    a[0] = k;
    for (int i = k + 1; i <= n; i++) {
        if (s[i] == s[k]) {
            a[0]++;
        }
    }
    cout << a[0] << "\n";
    for (int i = 1; i <= a[0]; i++) {
        cout << id[i] << "\n";
    }
    return 0;
}
