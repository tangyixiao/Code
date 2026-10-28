#include <bits/stdc++.h>
using namespace std;

int n, a, b;
map<int, int> nxt, pre;
char op[10];

signed main() {
    cin >> n;
    nxt[-1] = -2;
    pre[-2] = -1;
    for (int i = 1; i <= n; i++) {
        cin >> op;
        if (op[0] == 'A') {
            cin >> a >> b;
            int t = nxt[a];
            nxt[a] = b;
            pre[b] = a;
            nxt[b] = t;
            pre[t] = b;
        } else {
            cin >> a;
            int l = pre[a], r = nxt[a];
            nxt[l] = r;
            pre[r] = l;
        }
    }
    int cur = nxt[-1], first = 1;
    while (cur != -2) {
        if (!first) {
            cout << " ";
        }
        first = 0;
        cout << cur;
        cur = nxt[cur];
    }
    cout << "\n";
    return 0;
}
