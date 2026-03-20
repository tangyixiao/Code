#include <bits/stdc++.h>
using namespace std;

const int MAXN = 2000;
int c[MAXN + 5][MAXN + 5];
int sum[MAXN + 5][MAXN + 5];

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int t, k;
    cin >> t >> k;

    c[0][0] = 1 % k;
    for (int i = 1; i <= MAXN; ++i) {
        c[i][0] = 1 % k;
        c[i][i] = 1 % k;
        for (int j = 1; j < i; ++j) {
            c[i][j] = (c[i - 1][j] + c[i - 1][j - 1]) % k;
        }
    }

    for (int i = 0; i <= MAXN; ++i) {
        for (int j = 0; j <= i; ++j) {
            sum[i][j] = (c[i][j] == 0) ? 1 : 0;
        }
    }

    for (int i = 0; i <= MAXN; ++i) {
        for (int j = 0; j <= MAXN; ++j) {
            if (i > 0)
                sum[i][j] += sum[i - 1][j];
            if (j > 0)
                sum[i][j] += sum[i][j - 1];
            if (i > 0 && j > 0)
                sum[i][j] -= sum[i - 1][j - 1];
        }
    }

    while (t--) {
        int n, m;
        cin >> n >> m;
        cout << sum[n][m] << '\n';
    }

    return 0;
}