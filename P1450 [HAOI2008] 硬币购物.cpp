#include <iostream>
using namespace std;

long long dp[100005];
int c[5];

int main() {
    int n;
    cin >> c[1] >> c[2] >> c[3] >> c[4] >> n;

    dp[0] = 1;
    for (int i = 1; i <= 4; ++i)
        for (int j = c[i]; j <= 100000; ++j)
            dp[j] += dp[j - c[i]];

    while (n--) {
        int d[5], s;
        cin >> d[1] >> d[2] >> d[3] >> d[4] >> s;

        long long ans = 0;

        for (int mask = 0; mask < 16; ++mask) {
            int rest = s, cnt = 0;
            for (int i = 1; i <= 4; ++i) {
                if (mask >> (i - 1) & 1) {
                    rest -= (d[i] + 1) * c[i];
                    ++cnt;
                }
            }
            if (rest < 0)
                continue;
            if (cnt & 1)
                ans -= dp[rest];
            else
                ans += dp[rest];
        }

        cout << ans << endl;
    }
    return 0;
}