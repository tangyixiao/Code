#include <algorithm>
#include <cstring>
#include <iostream>

using namespace std;

const int MAXN = 1000;
const int MAXV = 5000;   
const int OFFSET = 5000; 
const int INF = 0x3f3f3f3f;

int n;
int a[MAXN + 5], b[MAXN + 5];
int dp[2][2 * MAXV + 10]; 

int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);

    cin >> n;
    for (int i = 1; i <= n; ++i) {
        cin >> a[i] >> b[i];
    }

    memset(dp, 0x3f, sizeof(dp));
    dp[0][OFFSET] = 0; 

    for (int i = 1; i <= n; ++i) {
        int diff = a[i] - b[i]; 
        int cur = i & 1;
        int pre = cur ^ 1;

        
        memset(dp[cur], 0x3f, sizeof(dp[cur]));

        for (int j = 0; j <= 2 * MAXV; ++j) {
            if (dp[pre][j] == INF)
                continue;

            int nd = j + diff; 
            if (0 <= nd && nd <= 2 * MAXV) {
                dp[cur][nd] = min(dp[cur][nd], dp[pre][j]);
            }

            nd = j - diff; 
            if (0 <= nd && nd <= 2 * MAXV) {
                dp[cur][nd] = min(dp[cur][nd], dp[pre][j] + 1);
            }
        }
    }

    int ans = INF;
    for (int delta = 0; delta <= MAXV; ++delta) {
        int pos = OFFSET + delta;
        int neg = OFFSET - delta;
        int val = min(dp[n & 1][pos], dp[n & 1][neg]);
        if (val < INF) {
            ans = val;
            break;
        }
    }

    cout << ans << endl;
    return 0;
}