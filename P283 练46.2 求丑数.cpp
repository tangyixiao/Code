#include <bits/stdc++.h>
using namespace std;

int n, cnt;

signed main() {
    cin >> n;
    for (int i = 1; i <= n; i++) {
        int t = i;
        while (t % 2 == 0) {
            t /= 2;
        }
        while (t % 3 == 0) {
            t /= 3;
        }
        while (t % 5 == 0) {
            t /= 5;
        }
        if (t == 1) {
            printf("%6d", i);
            cnt++;
            if (cnt % 10 == 0) {
                printf("\n");
            }
        }
    }
    if (cnt % 10 != 0) {
        printf("\n");
    }
    printf("个数：%d\n", cnt);
    return 0;
}
