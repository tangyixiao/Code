#include <bits/stdc++.h>
using namespace std;
const int M = 1e5 + 5;
int q[M], tail, n, m;
set<int> s;
set<int>::iterator it;
int main() {
    scanf("%d%d", &n, &m);
    s.insert(0);
    s.insert(n + 1);
    for (int i = 1; i <= m; i++) {
        char c;
        cin >> c;
        if (c == 'D') {
            int x;
            scanf("%d", &x);
            s.insert(x);
            q[++tail] = x;
        }
        if (c == 'Q') {
            int x;
            scanf("%d", &x);
            it = s.lower_bound(x);
            if (*it == x) {
                printf("0\n");
                continue;
            }
            int ans = *it - *(--it);
            printf("%d\n", ans - 1);
        }
        if (c == 'R') {
            it = s.find(q[tail--]);
            s.erase(it);
        }
    }
    return 0;
}
