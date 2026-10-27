#include <bits/stdc++.h>
using namespace std;

double s;

signed main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cin >> s;
    if (s >= 500) {
        s = s * 0.8;
    } else if (s >= 300) {
        s = s * 0.9;
    }
    cout << fixed << setprecision(2) << s << "\n";
    return 0;
}
