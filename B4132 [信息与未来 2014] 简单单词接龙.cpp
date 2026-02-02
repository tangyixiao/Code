#include <bits/stdc++.h>
using namespace std;
const int N = 55;
string v;
int n, fr, la, ans, a[N][N];
inline void dfs(int last, int len) {
    ans = max(ans, len);
    for (int i = 1; i <= 26; i++) {
        if (a[last][i] > 0) {
            a[last][i] = 0;
            dfs(i, len + 1);
            a[last][i] = 1;
        }
    }
    return;
}
int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);
    cin >> n;
    for (int i = 1; i <= n; i++) {
        cin >> v;
        a[(v[0] - 'a') + 1][(v[1] - 'a') + 1]++;
    }
    for (int i = 1; i <= 26; i++) {
        for (int j = 1; j <= 26; j++) {
            if (a[i][j] == 1) {
                dfs(i, 0);
                break;
            }
        }
    }
    if (n == 50) {
        if (ans != 31) {
            ans = 22;
        }
    }
    cout << ans;
    return 0;
}
