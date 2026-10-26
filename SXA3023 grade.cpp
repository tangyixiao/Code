#include <bits/stdc++.h>
using namespace std;

const int N = 1e2 + 5;
int n, p[N];
string id[N], sc[N];
double v[N];

bool cmp(int x, int y) {
    if (v[x] != v[y]) {
        return v[x] > v[y];
    }
    return stoll(id[x]) > stoll(id[y]);
}

signed main() {
    ios::sync_with_stdio(false);
    cin.tie(0);
    cin >> n;
    for (int i = 1; i <= n; i++) {
        cin >> id[i] >> sc[i];
        v[i] = stod(sc[i]);
        p[i] = i;
    }
    sort(p + 1, p + n + 1, cmp);
    for (int i = 1; i <= n; i++) {
        cout << id[p[i]] << " " << sc[p[i]] << "\n";
    }
    return 0;
}
