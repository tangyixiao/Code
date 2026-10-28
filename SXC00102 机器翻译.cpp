#include <bits/stdc++.h>
using namespace std;

const int N = 1e3 + 5;
int M, n, a, ans;
int q[N];
bool in[N];

signed main() {
    cin >> M >> n;
    int h = 1, t = 0;
    for (int i = 1; i <= n; i++) {
        cin >> a;
        if (in[a]) {
            continue;
        }
        ans++;
        if (t - h + 1 == M) {
            in[q[h]] = 0;
            h++;
        }
        q[++t] = a;
        in[a] = 1;
    }
    cout << ans << "\n";
    return 0;
}
