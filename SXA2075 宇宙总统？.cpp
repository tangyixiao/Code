#include <bits/stdc++.h>
using namespace std;
int n, i, x, best, id;
int cnt[105];
signed main() {
    cin >> n;
    for (i = 1; i <= n; i++) {
        cin >> x;
        cnt[x]++;
    }
    best = -1;
    for (i = 1; i <= 100; i++) {
        if (cnt[i] >= best && cnt[i] > 0) {
            best = cnt[i];
            id = i;
        }
    }
    cout << id << "\n";
    return 0;
}
