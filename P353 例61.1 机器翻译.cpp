#include <bits/stdc++.h>
using namespace std;
const int N = 1e3 + 5;
int m, n, i, x, head, tail, ans;
int q[N];
bool in[N];
signed main() {
    scanf("%d%d", &m, &n);
    head = 1, tail = 0, ans = 0;
    for (i = 1; i <= n; i++) {
        scanf("%d", &x);
        if (in[x]) {
            continue;
        }
        ans++;
        if (tail - head + 1 == m) {
            in[q[head]] = false;
            head++;
        }
        q[++tail] = x;
        in[x] = true;
    }
    printf("%d\n", ans);
    return 0;
}
