#include <bits/stdc++.h>

using namespace std;

const int Z = 2000005;
int A[Z], B[Z], D[Z], E[Z], F[Z], G[Z], H[Z], I[Z];
bool C[Z];

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int t;
    cin >> t;
    while (t--) {
        int n;
        cin >> n;
        int xc = 0, yc = 0;
        for (int i = 0; i < n; ++i) {
            int x, y;
            cin >> x >> y;
            if (!B[x]) {
                A[x] = B[x] = y;
                D[xc++] = x;
            } else {
                if (y < A[x])
                    A[x] = y;
                if (y > B[x])
                    B[x] = y;
            }
            if (!C[y]) {
                C[y] = 1;
                E[yc++] = y;
            }
        }
        if (xc < 2 || yc < 2) {
            cout << 0 << '\n';
            for (int i = 0; i < xc; ++i)
                A[D[i]] = B[D[i]] = 0;
            for (int i = 0; i < yc; ++i)
                C[E[i]] = 0;
            continue;
        }
        sort(D, D + xc);
        sort(E, E + yc);

        F[0] = A[D[0]];
        G[0] = B[D[0]];
        for (int i = 1; i < xc; ++i) {
            F[i] = min(F[i - 1], A[D[i]]);
            G[i] = max(G[i - 1], B[D[i]]);
        }
        H[xc - 1] = A[D[xc - 1]];
        I[xc - 1] = B[D[xc - 1]];
        for (int i = xc - 2; i >= 0; --i) {
            H[i] = min(H[i + 1], A[D[i]]);
            I[i] = max(I[i + 1], B[D[i]]);
        }

        long long ans = 0;
        for (int i = 0; i < xc - 1; ++i) {
            int low = max(F[i], H[i + 1]);
            int high = min(G[i], I[i + 1]);
            if (low < high) {
                int p = lower_bound(E, E + yc, low) - E;
                int q = upper_bound(E, E + yc, high) - E - 1;
                if (q >= p)
                    ans += (q - p);
            }
        }
        cout << ans << '\n';

        for (int i = 0; i < xc; ++i)
            A[D[i]] = B[D[i]] = 0;
        for (int i = 0; i < yc; ++i)
            C[E[i]] = 0;
    }
    return 0;
}