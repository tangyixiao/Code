#include <bits/stdc++.h>
using namespace std;

const int N = 1e3 + 5;
int n, m, a[N];
pair<int, int> p[N];

signed main() {
    cin >> n >> m;
    for (int i = 1; i <= n; i++) {
        cin >> a[i];
        p[i] = make_pair(-a[i], i);
    }
    sort(p + 1, p + n + 1);
    long long s = 0, t = 0;
    for (int i = 1; i <= m; i++) {
        s += -p[i].first;
        t += p[i].second;
    }
    cout << s << " " << t << "\n";
    return 0;
}
