#include <bits/stdc++.h>
using namespace std;

const int N = 1e7 + 5;

int t, x;
char np[N];

signed main() {
    np[1] = 1;
    for (int i = 2; i * i < N; i++) {
        if (np[i] == 0) {
            for (long long j = 1LL * i * i; j < N; j += i) {
                np[j] = 1;
            }
        }
    }
    scanf("%d", &t);
    while (t > 0) {
        t--;
        scanf("%d", &x);
        if (x < N && np[x] == 0) {
            printf("yes\n");
        } else {
            printf("no\n");
        }
    }
    return 0;
}
