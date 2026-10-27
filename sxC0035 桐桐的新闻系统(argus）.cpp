#include <bits/stdc++.h>
using namespace std;

const int N = 1e5 + 5;

int k, q[N], p[N], t[N];
char s[105];

struct node {
    int tm, id;
};

bool operator<(node a, node b) {
    if (a.tm != b.tm) {
        return a.tm > b.tm;
    }
    return a.id > b.id;
}

signed main() {
    int tot = 0;
    while (scanf("%s", s) == 1) {
        if (s[0] == '#') {
            break;
        }
        tot++;
        scanf("%d %d", &q[tot], &p[tot]);
    }
    scanf("%d", &k);
    priority_queue<node> pq;
    for (int i = 1; i <= tot; i++) {
        node x;
        x.tm = p[i];
        x.id = q[i];
        pq.push(x);
    }
    for (int i = 1; i <= k; i++) {
        node x = pq.top();
        pq.pop();
        printf("%d\n", x.id);
        for (int j = 1; j <= tot; j++) {
            if (q[j] == x.id) {
                x.tm += p[j];
                break;
            }
        }
        pq.push(x);
    }
    return 0;
}
