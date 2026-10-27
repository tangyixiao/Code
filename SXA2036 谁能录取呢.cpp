#include <bits/stdc++.h>
using namespace std;

const int N = 1e5 + 5;
int n, m, k[N], s[N];

signed main() {
    cin >> n >> m;
    for (int i = 1; i <= n; i++) {
        cin >> k[i] >> s[i];
    }
    for (int i = 1; i < n; i++) {
        for (int j = 1; j <= n - i; j++) {
            if (s[j] < s[j + 1] || (s[j] == s[j + 1] && k[j] > k[j + 1])) {
                swap(s[j], s[j + 1]);
                swap(k[j], k[j + 1]);
            }
        }
    }
    int c = s[m], t = 0;
    for (int i = 1; i <= n; i++) {
        if (s[i] >= c) {
            t++;
        }
    }
    cout << c << " " << t << "\n";
    for (int i = 1; i <= n; i++) {
        if (s[i] >= c) {
            cout << k[i] << " " << s[i] << "\n";
        }
    }
    return 0;
}
