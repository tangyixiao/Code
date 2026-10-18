#include <bits/stdc++.h>
using namespace std;

const int N = 1e2 + 5;
char s[N][15];
int a[N], n;

inline bool gt(int x, int y) {
    if ((x >= 60) != (y >= 60)) {
        return x >= 60;
    }
    return x >= 60 && x > y;
}

inline void input() {
    cin >> n;
    return;
}

inline void solve() {
    for (int i = 0; i < n; i++) {
        cin >> s[i] >> a[i];
    }
    for (int i = 1; i < n; i++) {
        for (int j = i; j > 0 && gt(a[j], a[j - 1]); j--) {
            swap(a[j], a[j - 1]), swap(s[j], s[j - 1]);
        }
    }
    for (int i = 0; i < n; i++) {
        cout << s[i] << "\n";
    }
    return;
}

signed main() {
    input();
    solve();
    return 0;
}