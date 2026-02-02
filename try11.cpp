#include <iostream>
#include <set>
using namespace std;
int T;
int n, m;
multiset<__int128> s;
__int128 t[100010];
__int128 a[100010], b[100010], p[100010];
__int128 mx;
__int128 exgcd(__int128 a, __int128 b, __int128& x, __int128& y) {
    if (!b) {
        x = 1;
        y = 0;
        return a;
    }
    __int128 c = exgcd(b, a % b, y, x);
    y -= a / b * x;
    return c;
}
__int128 exCRT(int n) {
    __int128 A = 0, P = 1, c, y1, y2, x = 0;
    for (int i = 1; i <= n; i++) {
        c = exgcd(P * b[i], p[i], y1, y2);
        if ((a[i] - A * b[i] % p[i] + p[i]) % p[i] % c)
            return -1;
        y1 = y1 * (a[i] - A * b[i] % p[i] + p[i]) % p[i] / c;
        x = A + P * y1;
        P = P / c * p[i];
        A = x = (x % P + P) % P;
    }
    if (x < mx)
        x += ((mx - x - 1) / P + 1) * P;
    return x;
}
int main() {
    freopen("P4774_5.in", "r", stdin);
    ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    cin >> T;
    while (T--) {
        cin >> n >> m;
        for (int i = 1; i <= n; i++) {
            long long A;
            cin >> A;
            a[i] = A;
        }
        for (int i = 1; i <= n; i++) {
            long long P;
            cin >> P;
            p[i] = P;
        }
        for (int i = 1; i <= n; i++) {
            long long T;
            cin >> T;
            t[i] = T;
        }
        s.clear();
        for (int i = 1, t; i <= m; i++) {
            cin >> t;
            s.insert(t);
        }
        mx = 0;
        for (int i = 1; i <= n; i++) {
            multiset<__int128>::iterator it = s.upper_bound(a[i]);
            if (it != s.begin())
                it--;
            b[i] = *it;
            mx = max((a[i] - 1) / b[i] + 1, mx);
            s.erase(it);
            s.insert(t[i]);
        }
        cout << (long long)exCRT(n) << '\n';
    }
    return 0;
}