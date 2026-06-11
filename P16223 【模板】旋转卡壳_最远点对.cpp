#include <bits/stdc++.h>
using namespace std;
using ll = long long;
const int N = 5e5 + 5;
int n, m;
struct P {
    int x, y, z;
    bool operator<(const P &rhs) const {
        return x != rhs.x ? x < rhs.x : y < rhs.y;
    }
} a[N], b[N];
ll D(const P &u, const P &v) {
    ll dx = u.x - v.x, dy = u.y - v.y;
    return dx * dx + dy * dy;
}
ll C(const P &o, const P &u, const P &v) {
    return 1LL * (u.x - o.x) * (v.y - o.y) - 1LL * (v.x - o.x) * (u.y - o.y);
}
int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);
    int T;
    cin >> T;
    while (T--) {
        cin >> n;
        for (int i = 1; i <= n; ++i) {
            cin >> a[i].x >> a[i].y;
            a[i].z = i - 1;
        }
        sort(a + 1, a + n + 1);
        m = 0;
        for (int i = 1; i <= n; ++i) {
            for (; m > 1 && C(b[m - 1], b[m], a[i]) <= 0; --m)
                ;
            b[++m] = a[i];
        }
        int k = m;
        for (int i = n - 1; i >= 1; --i) {
            for (; m > k && C(b[m - 1], b[m], a[i]) <= 0; --m)
                ;
            b[++m] = a[i];
        }
        if (m > 1)
            --m;

        if (m == 2) {
            cout << b[1].z << ' ' << b[2].z << '\n';
        } else {
            b[m + 1] = b[1];
            int j = 2, u = b[1].z, v = b[2].z;
            ll mx = D(b[1], b[2]);
            for (int i = 1; i <= m; ++i) {
                for (; C(b[i], b[i + 1], b[j]) < C(b[i], b[i + 1], b[j + 1]);
                     j = (j == m ? 1 : j + 1))
                    ;
                ll d1 = D(b[i], b[j]);
                if (d1 > mx)
                    mx = d1, u = b[i].z, v = b[j].z;
                ll d2 = D(b[i + 1], b[j]);
                if (d2 > mx)
                    mx = d2, u = b[i + 1].z, v = b[j].z;
            }
            cout << u << ' ' << v << '\n';
        }
    }
    return 0;
}