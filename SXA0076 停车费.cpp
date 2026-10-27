#include <bits/stdc++.h>
using namespace std;

int h1, m1, s1, h2, m2, s2;

signed main() {
    cin >> h1 >> m1 >> s1;
    cin >> h2 >> m2 >> s2;
    long long t = (long long)h2 * 3600 + m2 * 60 + s2 - ((long long)h1 * 3600 + m1 * 60 + s1);
    long long ans = (t + 3599) / 3600 * 5;
    cout << ans << "\n";
    return 0;
}
