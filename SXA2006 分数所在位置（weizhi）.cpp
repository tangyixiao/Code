#include <bits/stdc++.h>
using namespace std;
int n, m;
long long s;
signed main() {
    cin >> n >> m;
    s = (long long)m * (m - 1) / 2 + n;
    cout << s << "\n";
    return 0;
}
