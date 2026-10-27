#include <bits/stdc++.h>
using namespace std;
int vis[15], p, t, i, c;
signed main() {
    p = 10;
    for (t = 1; t <= 1000; t++) {
        p = (p - 1 + t) % 10 + 1;
        vis[p] = 1;
    }
    c = 0;
    for (i = 1; i <= 10; i++) {
        if (!vis[i]) {
            if (c) {
                cout << " ";
            }
            cout << i;
            c = 1;
        }
    }
    cout << "\n";
    return 0;
}
