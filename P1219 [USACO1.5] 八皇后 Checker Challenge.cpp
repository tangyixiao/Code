#include <bits/stdc++.h>
using namespace std;
int n, xhz, visy[114], visl[114], visr[114], a[114];
void dfs(int x) {
    if (x == n + 1) {
        xhz++;
        if (xhz <= 3) {
            for (int i = 1; i <= n; i++)
                printf("%d ", a[i]);
            printf("\n");
        }
        return;
    }
    for (int y = 1; y <= n; y++) {
        if (visy[y] == 0 && visl[y - x + n] == 0 && visr[y + x - 1] == 0) {
            visy[y] = visl[y - x + n] = visr[y + x - 1] = 1;
            a[x] = y;
            dfs(x + 1);
            visy[y] = visl[y - x + n] = visr[y + x - 1] = 0;
        }
    }
}
int main() {
    cin >> n;
    dfs(1);
    cout << xhz << endl;
    return 0;
}