#include <bits/stdc++.h>
using namespace std;
const int N = 3e3 + 5;
int n, k, a[N][N], h[N];
int main() {
    cin >> n >> k;
    for (int i = 0; i <= 2 * n - 1; i++) {
        a[i][0] = 1;
    }
    int p = 1;
    for (int i = 1; i <= 2 * n - 1; i++) {
        h[i] = p;
        if (i % 2 == 0) {
            p += 2;
        }
    }
    for (int i = 1; i <= n * 2 - 1; i++) {

        for (int j = 1; j <= k; j++) {
            a[i][j] = (a[i - 1][j] + a[i - 1][j - 1] * (h[i] - (j - 1))) % 504;
        }
    }
    cout << a[2 * n - 1][k];
    return 0;
}
