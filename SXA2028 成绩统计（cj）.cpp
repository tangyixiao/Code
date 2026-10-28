#include <bits/stdc++.h>
using namespace std;

const int N = 105;
int n, s1[N], s2[N], s3[N], sm[N], ord[N];
string nm[N];

bool cmp(int x, int y) {
    return sm[x] < sm[y];
}

signed main() {
    ios::sync_with_stdio(false);
    cin.tie(0);
    cin >> n;
    for (int i = 1; i <= n; i++) {
        cin >> nm[i] >> s1[i] >> s2[i] >> s3[i];
        sm[i] = s1[i] + s2[i] + s3[i];
        ord[i] = i;
    }
    stable_sort(ord + 1, ord + n + 1, cmp);
    for (int i = 1; i <= n; i++) {
        int p = ord[i];
        cout << nm[p] << " " << s1[p] << " " << s2[p] << " " << s3[p] << " " << sm[p] << "\n";
    }
    return 0;
}
