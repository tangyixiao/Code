#include <bits/stdc++.h>
using namespace std;

const double inf = 1e18;
const int N = 1e3 + 5;

struct point {
    int x, y;
    bool operator<(const point &other) const {
        if (x != other.x) {
            return x < other.x;
        }
        return y < other.y;
    }
} a[N];

inline double dist(const point &a, const point &b) {
    double dx = a.x - b.x;
    double dy = a.y - b.y;
    return sqrt(dx * dx + dy * dy);
}

int n;
double dp[N][N], ans = inf;

signed main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cin >> n;
    for (int i = 1; i <= n; i++) {
        cin >> a[i].x >> a[i].y;
    }
    sort(a + 1, a + 1 + n);

    for (int i = 0; i <= n; i++)
        for (int j = 0; j <= n; j++)
            dp[i][j] = inf;

    dp[2][1] = dist(a[1], a[2]);
    for (int i = 2; i < n; i++) {
        for (int j = 1; j < i; j++) {
            dp[i + 1][j] = min(dp[i + 1][j], dp[i][j] + dist(a[i], a[i + 1]));
            dp[i + 1][i] = min(dp[i + 1][i], dp[i][j] + dist(a[j], a[i + 1]));
        }
    }

    for (int j = 1; j < n; j++) {
        ans = min(ans, dp[n][j] + dist(a[j], a[n]));
    }

    cout << fixed << setprecision(2) << ans << '\n';
    return 0;
}