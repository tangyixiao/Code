#include <bits/stdc++.h>
using namespace std;
struct node {
    int s, t;
};
int n, t, m, x, temp_nation[1000005], ans;
queue<node> ship;
node h;

int main() {
    scanf("%d", &n);
    for (int i = 1; i <= n; i++) {
        scanf("%d%d", &t, &m);
        while (!ship.empty()) {
            h = ship.front();
            if (h.t + 86400 <= t) {
                temp_nation[h.s]--;
                if (temp_nation[h.s] == 0)
                    ans--;
                ship.pop();
                continue;
            }
            break;
        }
        for (int j = 1; j <= m; ++j) {
            scanf("%d", &x);
            h.s = x, h.t = t;
            ship.push(h);
            temp_nation[x]++;
            if (temp_nation[x] == 1)
                ans++;
        }
        printf("%d\n", ans);
    }
    return 0;
}
F