#include <bits/stdc++.h>
using namespace std;
int n = 100, cnt;
bool vis[105];

int main() {
    for (int i = 2; i <= n; i++) {
        if (vis[i]) {
            continue;
        }
        cnt++;
        for (int j = i * i; j <= n; j += i) {
            vis[j] = true;
        }
    }
    for (int i = 2; i <= n; i++) {
        if (vis[i]) {
            continue;
        }
        printf("%d ", i);
    }
    printf("\n100以内的素数个数：%d\n", cnt);
    return 0;
}