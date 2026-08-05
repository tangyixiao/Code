#include <bits/stdc++.h>
using namespace std;
const int N = 1e5 + 5;
struct E {
    int a, b, c;
} e[N];
int n, k, x, fa[N], s[N];
long long ans;
int g(int x) { return fa[x] == x ? x : fa[x] = g(fa[x]); }
int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);
    cin >> n >> k;
    for (int i = 0; i < n; i++)
        fa[i] = i;
    for (int i = 0; i < k; i++)
        cin >> x, s[x] = 1;
    for (int i = 1; i < n; i++)
        cin >> e[i].a >> e[i].b >> e[i].c;
    sort(e + 1, e + n, [](E p, E q) { return p.c > q.c; });
    for (int i = 1; i < n; i++) {
        int ra = g(e[i].a), rb = g(e[i].b);
        if (ra == rb)
            continue;
        if (s[ra] && s[rb])
            ans += e[i].c;
        else
            fa[ra] = rb, s[rb] |= s[ra];
    }
    cout << ans;
}