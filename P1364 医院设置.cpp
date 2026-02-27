#include <bits/stdc++.h>
using namespace std;

const int N = 105;
const int INF = 0x3f3f3f3f;
int n, w[N];
int dist[N][N];

int main() {
    cin >> n;

    for (int i = 1; i <= n; i++) {
        for (int j = 1; j <= n; j++) {
            dist[i][j] = (i == j) ? 0 : INF;
        }
    }
    for (int i = 1; i <= n; i++) {
        int u, v;
        cin >> w[i] >> u >> v;
        if (u) {
            dist[i][u] = dist[u][i] = 1;
        }
        if (v) {
            dist[i][v] = dist[v][i] = 1;
        }
    }

    for (int k = 1; k <= n; k++) {
        for (int i = 1; i <= n; i++) {
            for (int j = 1; j <= n; j++) {
                dist[i][j] = min(dist[i][j], dist[i][k] + dist[k][j]);
            }
        }
    }

    int ans = INT_MAX;
    for (int hospital = 1; hospital <= n; hospital++) {
        int sum = 0;
        for (int i = 1; i <= n; i++) {
            sum += w[i] * dist[hospital][i];
        }
        ans = min(ans, sum);
    }

    cout << ans << endl;
    return 0;
}