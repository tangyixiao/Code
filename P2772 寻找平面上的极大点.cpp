#include <bits/stdc++.h>
using namespace std;
const int N = 5e5 + 5, inf = 0x3f3f3f3f;
struct Node {
    int x, y;
    bool operator<(const Node &b) const {
        if (y == b.y) {
            return x > b.x;
        }
        return y > b.y;
    }
} a[N];
bool f;
int la = -inf, n;
signed main() {
    ios::sync_with_stdio(false);
    cin.tie(0);
    cin >> n;
    for (int i = 0; i < n; i++) {
        cin >> a[i].x >> a[i].y;
    }
    sort(a, a + n);
    for (int i = 0; i < n; i++) {
        if (a[i].x > la) {
            la = a[i].x;
            if (!f) {
                f = !f;
            } else {
                cout << ",";
            }
            cout << "(" << a[i].x << "," << a[i].y << ")";
        }
    }
    return 0;
}
