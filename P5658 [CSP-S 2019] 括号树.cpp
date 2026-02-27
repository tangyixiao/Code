#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
const int maxn = 5e5 + 10;

int n;
char s[maxn];
int fa[maxn];
vector<int> children[maxn];
int stk[maxn], top;
ll dp[maxn];
ll sum[maxn];
ll ans = 0;

void dfs(int u) {
    int tmp = 0;

    if (s[u] == '(') {

        stk[++top] = u;
        tmp = 0;
    } else {

        if (top > 0) {
            int matched = stk[top];
            top--;
            dp[u] = dp[fa[matched]] + 1;
            tmp = matched;
        }
    }

    sum[u] = sum[fa[u]] + dp[u];

    for (int v : children[u]) {
        dfs(v);
    }

    if (tmp > 0) {

        stk[++top] = tmp;
    } else if (tmp == 0 && top > 0) {

        top--;
    }
}

int main() {
    scanf("%d", &n);
    scanf("%s", s + 1);

    for (int i = 2; i <= n; i++) {
        scanf("%d", &fa[i]);
        children[fa[i]].push_back(i);
    }

    fa[1] = 0;
    dp[0] = 0;
    sum[0] = 0;
    top = 0;
    ans = 0;

    dfs(1);

    for (int i = 1; i <= n; i++) {
        ans ^= (1LL * i * sum[i]);
    }

    printf("%lld\n", ans);
    return 0;
}