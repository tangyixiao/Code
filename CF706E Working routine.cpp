#include <bits/stdc++.h>
using namespace std;
const int N = 1e3 + 5;
int n, m, q, a[N][N];

struct S {
    int x, y, d, r;
} f[2000010];
int get(int x, int y) {
    int head = 1;
    for (int i = 1; i < x; i++)
        head = f[head].d;
    for (int i = 1; i < y; i++)
        head = f[head].r;
    return head;
}
signed main() {
    cin >> n >> m >> q;
    for (int i = 1; i <= n; i++)
        for (int j = 1; j <= m; j++)
            cin >> a[i][j];
    int tim = 0;
    for (int i = 0; i <= n + 1; i++) {
        for (int j = 0; j <= m + 1; j++) {
            tim++;
            f[tim].r = tim + 1;
            f[tim].d = tim + m + 2;
            f[tim].x = i;
            f[tim].y = j;
        }
    }
    while (q--) {
        int x, xx, y, yy, l, c;
        cin >> x >> y >> xx >> yy >> l >> c;
        int A = get(x, y), B = get(xx, yy);
        int KA = A, KB = B;
        for (int i = 1; i <= c; i++) {
            A = f[A].r, B = f[B].r;
            swap(f[A].d, f[B].d);
        }
        for (int i = 1; i <= l; i++) {
            A = f[A].d, B = f[B].d;
            swap(f[A].r, f[B].r);
        }
        A = KA, B = KB;
        for (int i = 1; i <= l; i++) {
            A = f[A].d, B = f[B].d;
            swap(f[A].r, f[B].r);
        }
        for (int i = 1; i <= c; i++) {
            A = f[A].r, B = f[B].r;
            swap(f[A].d, f[B].d);
        }
    }
    int cnt = 1;
    for (int i = 1; i <= n; i++) {
        cnt = f[cnt].d;
        int ls = cnt;
        for (int j = 1; j <= m; j++) {
            ls = f[ls].r;
            cout << a[f[ls].x][f[ls].y] << " ";
        }
        cout << "\n";
    }
    return 0;
}
