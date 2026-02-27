#include <bits/stdc++.h>
#define int long long
using namespace std;
const int N = 5e3 + 5, M = 2e5 + 10;
struct node {
    int u, v, w;
} e[M];
bool operator<(const node& x, const node& y) {
    return x.w < y.w;
}
int n, m, father[N];
int findfather(int v) {
    if (father[v] == v)
        return v;
    else {
        father[v] = findfather(father[v]);
        return father[v];
    }
}
int Kruskal() {
    int ans = 0, num_edge = 0;
    for (int i = 1; i <= n; i++) {
        father[i] = i;
    }
    sort(e + 1, e + 1 + m);
    for (int i = 1; i <= m; i++) {
        int fu = findfather(e[i].u), fv = findfather(e[i].v);
        if (fu != fv) {
            ans += e[i].w;
            father[fu] = fv;
            num_edge++;
            if (num_edge == n - 1)
                break;
        }
    }
    if (num_edge != n - 1) {
        printf("orz");
        exit(0);
    }
    return ans;
}

signed main() {
    scanf("%lld%lld", &n, &m);
    for (int i = 1; i <= m; i++) {
        scanf("%lld%lld%lld", &e[i].u, &e[i].v, &e[i].w);
    }
    printf("%lld\n", Kruskal());
    return 0;
}