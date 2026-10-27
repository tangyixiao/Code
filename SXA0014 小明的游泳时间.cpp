#include <bits/stdc++.h>
using namespace std;
signed main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    int a, b, c, d;
    cin >> a >> b >> c >> d;
    int t = (c * 60 + d) - (a * 60 + b);
    cout << t / 60 << " " << t % 60 << "\n";
    return 0;
}
