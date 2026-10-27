#include <bits/stdc++.h>
using namespace std;

int n, k;
int id[105], p[105], res[105];
double v[105];

bool cmp(int x, int y) {
    if (v[x] != v[y]) {
        return v[x] > v[y];
    }
    return id[x] < id[y];
}

signed main() {
    cin >> n >> k;
    for (int i = 1; i <= n; i++) {
        cin >> id[i] >> v[i];
        p[i] = i;
    }
    sort(p + 1, p + n + 1, cmp);
    int t = 0;
    for (int i = 1; i <= n; i++) {
        if (v[i] == v[p[k]]) {
            t++;
            res[t] = id[i];
        }
    }
    sort(res + 1, res + t + 1);
    for (int i = 1; i <= t; i++) {
        if (i > 1) {
            cout << " ";
        }
        cout << res[i];
    }
    cout << "\n";
    return 0;
}
