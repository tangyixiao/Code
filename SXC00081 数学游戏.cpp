#include <bits/stdc++.h>
using namespace std;

long long X, Y, K, B;
long long C[70][70];
int dig[70];

long long cnt(long long N) {
    if (N < 1) {
        return 0;
    }
    int len = 0;
    long long t = N;
    for (; t > 0;) {
        dig[len++] = t % B;
        t /= B;
    }
    for (int i = 0; i < len / 2; i++) {
        int tmp = dig[i];
        dig[i] = dig[len - 1 - i];
        dig[len - 1 - i] = tmp;
    }
    long long total = 0;
    long long used = 0;
    int bad = 0;
    for (int i = 0; i < len; i++) {
        int d = dig[i];
        long long rem = len - 1 - i;
        if (d >= 1) {
            long long need = K - used;
            if (need >= 0 && need <= rem) {
                total += C[rem][need];
            }
        }
        if (d > 1) {
            bad = 1;
            break;
        }
        if (d == 1) {
            used++;
        }
        if (used > K) {
            bad = 1;
            break;
        }
    }
    if (bad == 0 && used == K) {
        total++;
    }
    return total;
}

signed main() {
    FILE *fp = fopen("maga.in", "r");
    if (fp != NULL) {
        fclose(fp);
        freopen("maga.in", "r", stdin);
        freopen("maga.out", "w", stdout);
    }
    cin >> X >> Y >> K >> B;
    for (int i = 0; i <= 64; i++) {
        C[i][0] = 1;
        for (int j = 1; j <= i; j++) {
            C[i][j] = C[i - 1][j - 1] + C[i - 1][j];
        }
    }
    cout << cnt(Y) - cnt(X - 1) << "\n";
    return 0;
}
