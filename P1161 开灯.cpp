#include <bits/stdc++.h>
using namespace std;
const int N = 2e6 + 5;
double a;
int n, t;
bool mp[N];
signed main() {
    scanf("%d", &n);
    for (int i = 1; i <= n; i++) {
        scanf("%lf %d", &a, &t);
        for (int j = 1; j <= t; j++) {
            mp[(int)(a * j)] = !mp[(int)(a * j)];
        }
    }
    for (int i = 1;; i++) {
        if (mp[i]) {
            printf("%d ", i);
            exit(0);
        }
    }
    return 0;
}