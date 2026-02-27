#include <bits/stdc++.h>
using namespace std;
int t1, t2, t3, i;
string n1[2][100005], n2[2][100005];
string a, b, c;
map<string, int> g;
signed main() {
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
    cin >> t1;
    for (i = 1; i <= t1; i++) {
        cin >> n1[0][i] >> n1[1][i];
    }
    cin >> t2;
    for (i = 1; i <= t2; i++) {
        cin >> n2[0][i] >> n2[1][i];
    }
    cin >> t3;
    for (i = 1; i <= t3; i++) {
        cin >> a >> b >> c;
        g[a] = g[b] = g[c] = i;
    }
    int ans = 0;
    for (i = 1; i <= t1; i++)
        if (g[n1[0][i]] != g[n1[1][i]]) {
            ans++;
        }
    for (i = 1; i <= t2; i++) {
        if (g[n2[0][i]] == g[n2[1][i]]) {
            ans++;
        }
    }
    cout << ans;
    return 0;
}
