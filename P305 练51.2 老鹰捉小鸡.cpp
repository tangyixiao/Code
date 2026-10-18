#include <bits/stdc++.h>
using namespace std;

const int N = 6 + 5;

int a[N];

inline void input() {
    for (int i = 0; i < 5; i++) {
        a[i] = i + 1;
    }
}

inline void solve() {
    for (int t = 1; t <= 10; t++) {
        printf("%d:", t);
        for (int i = 0; i < 5; i++) {
            printf(" %d", a[i]);
        }
        printf("\n");
        int x = a[0];
        for (int i = 0; i < 4; i++) {
            a[i] = a[i + 1];
        }
        a[4] = x;
    }
    return;
}

signed main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    input();
    solve();
    return 0;
}