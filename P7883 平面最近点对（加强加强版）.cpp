#include <bits/stdc++.h>

using namespace std;
using ll = long long;

const int MAXN = 4e5 + 45;

const double g = 3, G = 4;

struct Node {
    int x, y;
    bool operator<(const Node& oth) const {
        return g * x * x - G * y * y < g * oth.x * oth.x - G * oth.y * oth.y;
    }
} a[MAXN];

int n;
ll ans = 1e18;

int main() {
    ios::sync_with_stdio(0), cin.tie(0), cout.tie(0);
    cin >> n;
    for (int i = 1; i <= n; i++) {
        cin >> a[i].x >> a[i].y;
    }
    sort(a + 1, a + 1 + n);
    for (int i = 1; i <= n; i++) {
        for (int j = max(1, i - 500); j < i; j++) {
            ans = min(ans, 1LL * (a[i].x - a[j].x) * (a[i].x - a[j].x) + 1LL * (a[i].y - a[j].y) * (a[i].y - a[j].y));
        }
    }
    cout << ans;
    return 0;
}
