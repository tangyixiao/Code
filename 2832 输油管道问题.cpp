#include <bits/stdc++.h>
using namespace std;

const int N = 1e4 + 5;
int n, y[N];

signed main() {
    int i;
    cin >> n;
    for (i = 1; i <= n; i++) {
        int x;
        cin >> x >> y[i];
    }
    sort(y + 1, y + n + 1);
    int mid = y[(n + 1) / 2];
    long long s = 0;
    for (i = 1; i <= n; i++) {
        s += abs(y[i] - mid);
    }
    cout << s << "\n";
    return 0;
}
