#include <bits/stdc++.h>
using namespace std;

const int N = 1e3 + 5;
int n, k;
string id[N], sc[N];
double v[N];
int p[N];

bool cmp(int x, int y) {
    if (v[x] != v[y]) {
        return v[x] > v[y];
    }
    return id[x] > id[y];
}

signed main() {
    ios::sync_with_stdio(false);
    cin.tie(0);
    cin >> n;
    for (int i = 1; i <= n; i++) {
        cin >> id[i] >> sc[i];
        v[i] = atof(sc[i].c_str());
        p[i] = i;
    }
    sort(p + 1, p + n + 1, cmp);
    for (int i = 1; i <= n; i++) {
        cout << id[p[i]] << " " << sc[p[i]] << "\n";
    }
    return 0;
}
