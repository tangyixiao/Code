#include <bits/stdc++.h>
using namespace std;
const int N = 1e2 + 5;
int k, i, r, ans;
string t;
bool sold[20][5];
signed main() {
    cin >> k;
    for (i = 1; i <= k; i++) {
        cin >> t;
        r = 0;
        for (int j = 0; j + 1 < (int)t.size(); j++) {
            r = r * 10 + (t[j] - '0');
        }
        int c = t[(int)t.size() - 1] - 'A';
        sold[r][c] = !sold[r][c];
    }
    for (i = 1; i <= 13; i++) {
        if (!sold[i][0] && !sold[i][1]) {
            ans++;
        }
        if (!sold[i][2] && !sold[i][3]) {
            ans++;
        }
    }
    cout << ans << "\n";
    return 0;
}
