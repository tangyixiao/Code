#include <bits/stdc++.h>
using namespace std;

int n, sc[1005], ord[1005];
string id[1005];

bool cmp(int x, int y) {
    return sc[x] > sc[y];
}

signed main() {
    cin >> n;
    for (int i = 1; i <= n; i++) {
        cin >> id[i] >> sc[i];
        ord[i] = i;
    }
    stable_sort(ord + 1, ord + n + 1, cmp);
    for (int i = 1; i <= n; i++) {
        int p = ord[i], r = 1;
        for (int j = 1; j <= n; j++) {
            if (sc[j] > sc[p]) {
                r++;
            }
        }
        cout << r << " " << id[p] << " " << sc[p] << "\n";
    }
    return 0;
}
