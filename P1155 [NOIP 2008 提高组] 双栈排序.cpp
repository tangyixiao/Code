#include <bits/stdc++.h>
using namespace std;

namespace TANGYIXIAO {
const int N = 1e3 + 5;

int n, a[N], mn[N], col[N];
int s1[N], s2[N], t1, t2, now = 1, pos = 1, cnt;
bool g[N][N];
char ans[N << 1];

bool dfs(int x, int c) {
    col[x] = c;
    for (int i = 1; i <= n; i++) {
        if (!g[x][i]) {
            continue;
        }
        if (col[i] == -1) {
            if (!dfs(i, c ^ 1)) {
                return false;
            }
        } else if (col[i] == c) {
            return false;
        }
    }
    return true;
}
} // namespace TANGYIXIAO

signed main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    using namespace TANGYIXIAO;

    cin >> n;
    for (int i = 1; i <= n; i++) {
        cin >> a[i];
    }

    mn[n + 1] = n + 1;
    for (int i = n; i >= 1; i--) {
        mn[i] = min(mn[i + 1], a[i]);
    }

    for (int i = 1; i <= n; i++) {
        for (int j = i + 1; j <= n; j++) {
            if (a[i] < a[j] && mn[j + 1] < a[i]) {
                g[i][j] = g[j][i] = true;
            }
        }
    }

    memset(col, -1, sizeof(col));
    for (int i = 1; i <= n; i++) {
        if (col[i] != -1) {
            continue;
        }
        if (!dfs(i, 0)) {
            cout << 0 << '\n';
            return 0;
        }
    }

    for (; cnt < 2 * n;) {
        if (pos <= n && !col[pos] && (!t1 || s1[t1] > a[pos])) {
            s1[++t1] = a[pos++];
            ans[++cnt] = 'a';
        } else if (t1 && s1[t1] == now) {
            t1--;
            now++;
            ans[++cnt] = 'b';
        } else if (pos <= n && col[pos] && (!t2 || s2[t2] > a[pos])) {
            s2[++t2] = a[pos++];
            ans[++cnt] = 'c';
        } else if (t2 && s2[t2] == now) {
            t2--;
            now++;
            ans[++cnt] = 'd';
        } else {
            cout << 0 << '\n';
            return 0;
        }
    }

    for (int i = 1; i <= cnt; i++) {
        cout << ans[i];
        if (i < cnt) {
            cout << ' ';
        }
    }
    cout << '\n';

    return 0;
}