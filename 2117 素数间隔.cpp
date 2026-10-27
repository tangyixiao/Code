#include <bits/stdc++.h>
using namespace std;
const int N = 13e5 + 5;
bool vis[N];
signed main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    for (int i = 2; i < N; i++) {
        vis[i] = true;
    }
    for (int i = 2; i * i < N; i++) {
        if (vis[i]) {
            for (int j = i * i; j < N; j += i) {
                vis[j] = false;
            }
        }
    }
    int n;
    cin >> n;
    if (vis[n]) {
        cout << 0 << "\n";
        return 0;
    }
    int lo = n - 1, hi = n + 1;
    for (; !vis[lo];) {
        lo--;
    }
    for (; !vis[hi];) {
        hi++;
    }
    cout << hi - lo << "\n";
    return 0;
}
