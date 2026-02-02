#include <bits/stdc++.h>
using namespace std;
const int INF = 1e9, N = 55;
int n, A[N][N], D[N][N], B[N][N], temp[N][N], res[N][N];
void multiply(int C[N][N], int A[N][N], int B[N][N]) {
    for (int i = 0; i < n; ++i) {
        for (int j = 0; j < n; ++j) {
            C[i][j] = INF;
            for (int l = 0; l < n; ++l) {
                if (A[i][l] + B[l][j] < C[i][j]) {
                    C[i][j] = A[i][l] + B[l][j];
                }
            }
        }
    }
}

void power(int k) {
    for (int i = 0; i < n; ++i) {
        for (int j = 0; j < n; ++j) {
            res[i][j] = (i == j) ? 0 : INF;
        }
    }
    for (int i = 0; i < n; ++i) {
        for (int j = 0; j < n; ++j) {
            B[i][j] = A[i][j];
        }
    }

    while (k > 0) {
        if (k & 1) {
            multiply(temp, res, B);
            for (int i = 0; i < n; ++i) {
                for (int j = 0; j < n; ++j) {
                    res[i][j] = temp[i][j];
                }
            }
        }
        multiply(temp, B, B);
        for (int i = 0; i < n; ++i) {
            for (int j = 0; j < n; ++j) {
                B[i][j] = temp[i][j];
            }
        }
        k >>= 1;
    }
}

int main() {
    freopen("plane.in", "r", stdin);
    freopen("plane.out", "w", stdout);

    int T, k;
    scanf("%d", &T);

    for (int t = 1; t <= T; ++t) {
        scanf("%d %d", &k, &n);

        for (int i = 0; i < n; ++i) {
            for (int j = 0; j < n; ++j) {
                scanf("%d", &A[i][j]);
                D[i][j] = A[i][j];
            }
            D[i][i] = 0;
        }

        for (int l = 0; l < n; ++l) {
            for (int i = 0; i < n; ++i) {
                for (int j = 0; j < n; ++j) {
                    if (D[i][l] + D[l][j] < D[i][j]) {
                        D[i][j] = D[i][l] + D[l][j];
                    }
                }
            }
        }

        power(k);

        int G[N][N];
        multiply(G, res, D);

        if (t > 1)
            printf("\n");
        printf("Region #%d:\n", t);
        for (int i = 0; i < n; ++i) {
            for (int j = 0; j < n; ++j) {
                printf("%d", G[i][j]);
                if (j < n - 1)
                    printf(" ");
            }
            printf("\n");
        }
    }

    return 0;
}