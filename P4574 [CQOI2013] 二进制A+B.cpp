#include <bits/stdc++.h>
using namespace std;
inline int popcount(int x) {
    int cnt = 0;
    while (x) {
        cnt += x & 1;
        x >>= 1;
    }
    return cnt;
}

int a, b, c, ans, cnt;
signed main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cin >> a >> b >> c;
    return 0;
}