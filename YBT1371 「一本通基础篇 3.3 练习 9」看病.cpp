#include <bits/stdc++.h>
using namespace std;
int n, i, pri;
char op[15], nm[25];
priority_queue<pair<int, pair<int, string>>> q;
signed main() {
    scanf("%d", &n);
    for (i = 0; i < n; i++) {
        scanf("%s", op);
        if (op[0] == 'p' && op[1] == 'u') {
            scanf("%s %d", nm, &pri);
            q.push(make_pair(pri, make_pair(i, string(nm))));
        } else {
            if (q.empty()) {
                printf("none\n");
            } else {
                printf("%s %d\n", q.top().second.second.c_str(), q.top().first);
                q.pop();
            }
        }
    }
    return 0;
}
