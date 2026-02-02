#include <bits/stdc++.h>
#define int long long
using namespace std;
const int N = 1e6 + 5;
double f, sf;
int n, p[N], sump[N];
string s;
signed main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cin >> s;
    n = s.size();
    for (int i = 1; i <= n; ++i) {
        p[i] = p[i - 1] + (s[i - 1] == 'W');
    }
    for (int i = n; i >= 1; i--) {
        sump[i] = sump[i + 1] + p[i];
    }
    for (int i = n, m; i >= 1; i--) {
        m = n - i + 1;
        f = (s[i - 1] == 'C') ? (sump[i] - 1.0 * m * p[i - 1]) : (((1.0 * m * (m + 1) / 2.0 + 1.0 * m * p[i - 1] - sump[i])) + sf) / m;
        sf += f;
    }
    cout << fixed << setprecision(12) << f;
    return 0;
}