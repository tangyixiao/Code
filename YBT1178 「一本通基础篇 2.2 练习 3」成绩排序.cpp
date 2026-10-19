#include <bits/stdc++.h>
using namespace std;

const int N = 1e2 + 5;
int n, a[N];
char s[N][25];

inline void input() {
    cin >> n;
    return;
}

inline void solve() {
    for (int i = 0; i < n; i++) {
        cin >> s[i] >> a[i];
    }
    for (int i = 0; i < n; i++) {
        int m = i;
        for (int j = i + 1; j < n; j++) {
            if (a[j] > a[m] || (a[j] == a[m] && strcmp(s[j], s[m]) < 0)) {
                m = j;
            }
        }
        swap(a[i], a[m]), swap(s[i], s[m]);
    }
    for (int i = 0; i < n; i++) {
        cout << s[i] << " " << a[i] << "\n";
    }
    return;
}

signed main() {
    input();
    solve();
    return 0;
}