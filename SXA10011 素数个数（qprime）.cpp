#include <bits/stdc++.h>
using namespace std;
const int N = 4e6 + 5;
int a, b, d, cnt, prime[N];
signed main() {
    prime[1] = 1;
    for (int i = 2; 1LL * i * i <= N - 5; i++) {
        if (!prime[i]) {
            for (int j = i * i; j <= N - 5; j += i) {
                prime[j] = 1;
            }
        }
    }
    scanf("%d%d%d", &a, &b, &d);
    for (int x = a; x <= b; x++) {
        if (prime[x]) {
            continue;
        }
        int t = x, ok = 0;
        for (; t > 0; t /= 10) {
            if (t % 10 == d) {
                ok = 1;
                break;
            }
        }
        if (ok) {
            cnt++;
        }
    }
    printf("%d\n", cnt);
    return 0;
}
