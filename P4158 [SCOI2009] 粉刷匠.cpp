#include <bits/stdc++.h>
using namespace std;

const int INF = 1e9;
int N, M, T;
string s;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);

    cin >> N >> M >> T;
    T = min(T, N * M);

    vector<vector<int>> board_val(N + 1);

    for (int b = 1; b <= N; ++b) {
        cin >> s;
        s = "0" + s;

        vector<int> pre0(M + 1, 0), pre1(M + 1, 0);
        for (int i = 1; i <= M; ++i) {
            pre0[i] = pre0[i - 1] + (s[i] == '0');
            pre1[i] = pre1[i - 1] + (s[i] == '1');
        }

        vector<vector<int>> f(M + 1, vector<int>(M + 1, -INF));
        f[0][0] = 0;
        for (int i = 1; i <= M; ++i) {
            for (int j = 1; j <= i; ++j) {
                for (int k = 0; k < i; ++k) {
                    if (f[k][j - 1] == -INF)
                        continue;
                    int cnt0 = pre0[i] - pre0[k];
                    int cnt1 = pre1[i] - pre1[k];
                    int gain = max(cnt0, cnt1);
                    f[i][j] = max(f[i][j], f[k][j - 1] + gain);
                }
            }
        }

        board_val[b].resize(M + 1);
        board_val[b][0] = 0;
        for (int j = 1; j <= M; ++j) {
            board_val[b][j] = f[M][j];
        }
    }

    vector<int> dp(T + 1, -INF);
    dp[0] = 0;
    for (int b = 1; b <= N; ++b) {
        for (int t = T; t >= 0; --t) {
            for (int j = 1; j <= M; ++j) {
                if (t >= j && board_val[b][j] >= 0) {
                    dp[t] = max(dp[t], dp[t - j] + board_val[b][j]);
                }
            }
        }
    }

    int ans = 0;
    for (int t = 0; t <= T; ++t)
        ans = max(ans, dp[t]);
    cout << ans << endl;

    return 0;
}