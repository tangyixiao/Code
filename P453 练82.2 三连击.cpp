#include <bits/stdc++.h>
using namespace std;

int p[9], a, b, c;
int ans[100005], cnt;

signed main() {
    cin >> a >> b >> c;
    for (int i = 1; i <= 9; i++) {
        p[i - 1] = i;
    }
    do {
        int x = p[0] * 100 + p[1] * 10 + p[2], y = p[3] * 100 + p[4] * 10 + p[5], z = p[6] * 100 + p[7] * 10 + p[8];
        if (x * b == y * a && y * c == z * b) {
            ans[++cnt] = x * 1000000 + y * 1000 + z;
        }
    } while (next_permutation(p, p + 9));
    sort(ans + 1, ans + cnt + 1);
    if (cnt == 0) {
        cout << "No!!!\n";
        return 0;
    }
    for (int i = 1; i <= cnt; i++) {
        cout << ans[i] / 1000000 << " " << ans[i] / 1000 % 1000 << " " << ans[i] % 1000 << "\n";
    }
    return 0;
}
