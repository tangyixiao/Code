#include <bits/stdc++.h>
using namespace std;

const int N = 8005;
int n, x[N], y[N];

signed main() {
    cin >> n;
    for (int i = 1; i <= n; i++) {
        cin >> x[i] >> y[i];
    }
    sort(x + 1, x + n + 1);
    sort(y + 1, y + n + 1);
    long long s = 0;
    for (int i = 1; i <= n; i++) {
        s += abs(x[i] - i);
        s += abs(y[i] - i);
    }
    cout << s << "\n";
    return 0;
}
