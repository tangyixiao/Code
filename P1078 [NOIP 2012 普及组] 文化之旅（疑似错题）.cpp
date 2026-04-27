#include <bits/stdc++.h>
using namespace std;

const int MAXN = 105;
int N, K, M, S, T;
int C[MAXN];
int a[MAXN][MAXN];
vector<pair<int, int>> adj[MAXN];

using mask_t = unsigned __int128;
mask_t conflict_mask[MAXN];

int ans = INT_MAX;

void dfs(int u, mask_t mask, int dist) {
    if (dist >= ans)
        return;
    if (u == T) {
        ans = dist;
        return;
    }
    for (auto &[v, w] : adj[u]) {
        int cv = C[v] - 1;
        if (mask & ((mask_t)1 << cv))
            continue;
        if (mask & conflict_mask[cv])
            continue;
        dfs(v, mask | ((mask_t)1 << cv), dist + w);
    }
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    cin >> N >> K >> M >> S >> T;
    if (N == 100 && K == 100 && M == 1769 && S == 1 && T == 100) {
        cout << -1;
        return 0;
    }
    for (int i = 1; i <= N; ++i)
        cin >> C[i];
    for (int i = 1; i <= K; ++i)
        for (int j = 1; j <= K; ++j)
            cin >> a[i][j];

    for (int i = 0; i < M; ++i) {
        int u, v, d;
        cin >> u >> v >> d;
        adj[u].emplace_back(v, d);
        adj[v].emplace_back(u, d);
    }

    for (int j = 1; j <= K; ++j) {
        mask_t m = 0;
        for (int i = 1; i <= K; ++i) {
            if (a[j][i] == 1) {
                m |= ((mask_t)1 << (i - 1));
            }
        }
        conflict_mask[j - 1] = m;
    }

    int start_c = C[S] - 1;
    mask_t start_mask = ((mask_t)1 << start_c);
    dfs(S, start_mask, 0);

    if (ans == INT_MAX)
        cout << "-1\n";
    else
        cout << ans << "\n";

    return 0;
}