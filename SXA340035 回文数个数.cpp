#include <bits/stdc++.h>
using namespace std;

int n, cnt;

bool pal(int x) {
    int r = 0, y = x;
    for (; y > 0;) {
        r = r * 10 + y % 10, y /= 10;
    }
    return r == x;
}

signed main() {
    cin >> n;
    for (int i = 1; i <= n; i++) {
        if (pal(i)) {
            cnt++;
        }
    }
    cout << cnt << "\n";
    return 0;
}
