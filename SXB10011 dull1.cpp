#include <bits/stdc++.h>
using namespace std;

const int N = 1e5 + 5;
int n, q, a[N], b[N];

signed main() {
    ios::sync_with_stdio(false);
    cin.tie(0);
    cin >> n >> q;
    for (int i = 1; i <= n; i++) {
        cin >> a[i];
    }
    int top = 0;
    for (int i = n; i >= 1; i--) {
        while (top > 0 && a[b[top]] <= a[i]) {
            top--;
        }
        if (top > 0) {
            printf("%d ", b[top]);
        } else {
            printf("0 ");
        }
        b[++top] = i;
    }
    printf("\n");
    return 0;
}
