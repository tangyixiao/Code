#include <bits/stdc++.h>
using namespace std;

const int N = 1000 + 5;
int n, t[N], id[N], o[N];

signed main() {
    cin >> n;
    for (int i = 1; i <= n; i++) {
        cin >> t[i], id[i] = i;
    }
    sort(id + 1, id + n + 1, [](int x, int y) { return t[x] < t[y]; });
    double s = 0;
    for (int i = 1; i <= n; i++) {
        if (i > 1) {
            cout << " ";
        }
        cout << id[i], s += t[id[i]] * (n - i);
    }
    cout << "\n"
         << fixed << setprecision(2) << s / n << "\n";
    return 0;
}