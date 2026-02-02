#include <bits/stdc++.h>
using namespace std;
const int N = 12;
int a, sum, ans;
signed main() {
    for (int i = 1; i <= N; i++) {
        cin >> a;
        sum += 300;
        sum -= a;
        if (sum < 0) {
            printf("%d\n", -i);
            exit(0);
        }
        ans += (sum / 100);
        sum %= 100;
    }
    printf("%d\n", ans * 120 + sum);
    return 0;
}