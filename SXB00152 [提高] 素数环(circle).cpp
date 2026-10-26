#include <bits/stdc++.h>
using namespace std;
int n, i, tot;
int a[20];
bool used[20], pr[50];
bool isp(int x) {
    if (x < 2) {
        return false;
    }
    for (int d = 2; d * d <= x; d++) {
        if (x % d == 0) {
            return false;
        }
    }
    return true;
}
void dfs(int d) {
    if (d == n) {
        if (isp(a[n] + a[1])) {
            tot++;
            cout << tot << ":";
            for (int j = 1; j <= n; j++) {
                cout << a[j];
                if (j < n) {
                    cout << " ";
                }
            }
            cout << "\n";
        }
        return;
    }
    for (int v = 1; v <= n; v++) {
        if (!used[v] && isp(a[d] + v)) {
            used[v] = true, a[d + 1] = v;
            dfs(d + 1);
            used[v] = false;
        }
    }
}
signed main() {
    cin >> n;
    for (i = 1; i <= n; i++) {
        a[1] = i;
        used[i] = true;
        dfs(1);
        used[i] = false;
    }
    cout << "total:" << tot << "\n";
    return 0;
}
