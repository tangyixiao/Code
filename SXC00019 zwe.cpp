#include <bits/stdc++.h>
using namespace std;

const int N = 1e3 + 5;
const int L = 1e3 + 5;
char w[N][L];
int ord[N], len[N], cut[N];
int n;

bool cmp(int a, int b) {
    return strcmp(w[a], w[b]) < 0;
}

signed main() {
    scanf("%d", &n);
    for (int i = 0; i < n; i++) {
        scanf("%s", w[i]);
        len[i] = strlen(w[i]);
        ord[i] = i;
    }
    sort(ord, ord + n, cmp);
    for (int i = 0; i < n; i++) {
        int id = ord[i], best = 0;
        if (i > 0) {
            int o = ord[i - 1], k = 0;
            for (; w[id][k] && w[o][k] && w[id][k] == w[o][k]; k++) {
            }
            if (k > best) {
                best = k;
            }
        }
        if (i + 1 < n) {
            int o = ord[i + 1], k = 0;
            for (; w[id][k] && w[o][k] && w[id][k] == w[o][k]; k++) {
            }
            if (k > best) {
                best = k;
            }
        }
        if (best >= len[id]) {
            best = len[id] - 1;
        }
        cut[id] = best + 1;
    }
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < cut[i]; j++) {
            printf("%c", w[i][j]);
        }
        printf("\n");
    }
    return 0;
}
