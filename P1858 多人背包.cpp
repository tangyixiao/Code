#include <bits/stdc++.h>
using namespace std;

const int INF = 0xc0c0c0c0;
const int MAXV = 5010;
const int MAXK = 55;

int K, V, N;
int w[210], v[210];
int dp[MAXV][MAXK];

int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);

    cin >> K >> V >> N;
    for (int i = 1; i <= N; ++i)
        cin >> w[i] >> v[i];

    for (int j = 0; j <= V; ++j)
        for (int k = 0; k < K; ++k)
            dp[j][k] = INF;
    dp[0][0] = 0;

    for (int i = 1; i <= N; ++i) {
        for (int j = V; j >= w[i]; --j) {
            int tmp[2 * MAXK];
            int p1 = 0, p2 = 0, cnt = 0;

            while (cnt < K) {
                int val1 = (p1 < K) ? dp[j][p1] : INF;
                int val2 = INF;
                if (p2 < K && dp[j - w[i]][p2] != INF)
                    val2 = dp[j - w[i]][p2] + v[i];

                if (val1 == INF && val2 == INF)
                    break;

                if (val1 > val2) {
                    tmp[cnt++] = val1;
                    p1++;
                } else if (val1 < val2) {
                    tmp[cnt++] = val2;
                    p2++;
                } else {
                    if (cnt < K)
                        tmp[cnt++] = val1;
                    if (cnt < K && val1 != INF)
                        tmp[cnt++] = val2;
                    p1++;
                    p2++;
                }
            }

            for (int t = 0; t < cnt; ++t)
                dp[j][t] = tmp[t];
            for (int t = cnt; t < K; ++t)
                dp[j][t] = INF;
        }
    }

    int ans = 0;
    for (int k = 0; k < K; ++k) {
        if (dp[V][k] != INF)
            ans += dp[V][k];
        else
            break;
    }
    cout << ans << endl;

    return 0;
}