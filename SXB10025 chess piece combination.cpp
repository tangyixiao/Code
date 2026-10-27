#include <bits/stdc++.h>
using namespace std;

const int M = 7e5 + 5;
const int dr[4] = {-1, 1, 0, 0}, dc[4] = {0, 0, -1, 1};
int v1[M], v2[M], cur[M], nxt[M];
bool occ[64];
int s0[4], s1[4], w[4];
int cf[70][6];

signed main() {
    for (int i = 0; i < 70; i++) {
        cf[i][0] = 1;
    }
    for (int i = 1; i < 65; i++) {
        for (int j = 1; j <= 4; j++) {
            cf[i][j] = cf[i - 1][j - 1] + cf[i - 1][j];
        }
    }
    for (int i = 0; i < 4; i++) {
        int x, y;
        cin >> x >> y;
        s0[i] = (x - 1) * 8 + (y - 1);
    }
    for (int i = 0; i < 4; i++) {
        int x, y;
        cin >> x >> y;
        s1[i] = (x - 1) * 8 + (y - 1);
    }
    for (int i = 0; i < 4; i++) {
        for (int j = 0; j < 3 - i; j++) {
            if (s0[j] > s0[j + 1]) {
                swap(s0[j], s0[j + 1]);
            }
            if (s1[j] > s1[j + 1]) {
                swap(s1[j], s1[j + 1]);
            }
        }
    }
    int ok = 0;
    for (int ps = 0; ps < 2; ps++) {
        int *v = ps ? v2 : v1;
        int *src = ps ? s1 : s0;
        for (int i = 0; i < 4; i++) {
            w[i] = src[i];
        }
        int key = cf[w[0]][1] + cf[w[1]][2] + cf[w[2]][3] + cf[w[3]][4];
        v[key] = 1;
        cur[0] = (w[0] << 18) | (w[1] << 12) | (w[2] << 6) | w[3];
        int cn = 1, nn = 0;
        for (int d = 1; d <= 4; d++) {
            nn = 0;
            for (int q = 0; q < cn; q++) {
                int ky = cur[q];
                w[0] = (ky >> 18) & 63;
                w[1] = (ky >> 12) & 63;
                w[2] = (ky >> 6) & 63;
                w[3] = ky & 63;
                for (int i = 0; i < 64; i++) {
                    occ[i] = false;
                }
                for (int i = 0; i < 4; i++) {
                    occ[w[i]] = true;
                }
                for (int i = 0; i < 4; i++) {
                    int r = w[i] / 8, c = w[i] % 8;
                    for (int e = 0; e < 4; e++) {
                        int nr = r + dr[e], nc = c + dc[e];
                        if (nr < 0 || nr > 7 || nc < 0 || nc > 7) {
                            continue;
                        }
                        int np = nr * 8 + nc;
                        if (occ[np]) {
                            nr += dr[e];
                            nc += dc[e];
                            if (nr < 0 || nr > 7 || nc < 0 || nc > 7) {
                                continue;
                            }
                            np = nr * 8 + nc;
                            if (occ[np]) {
                                continue;
                            }
                        }
                        int z[4];
                        for (int t = 0; t < 4; t++) {
                            z[t] = w[t];
                        }
                        z[i] = np;
                        for (int a = 0; a < 4; a++) {
                            for (int b = 0; b < 3 - a; b++) {
                                if (z[b] > z[b + 1]) {
                                    swap(z[b], z[b + 1]);
                                }
                            }
                        }
                        int k2 = cf[z[0]][1] + cf[z[1]][2] + cf[z[2]][3] + cf[z[3]][4];
                        if (v[k2]) {
                            continue;
                        }
                        v[k2] = d + 1;
                        nxt[nn++] = (z[0] << 18) | (z[1] << 12) | (z[2] << 6) | z[3];
                    }
                }
            }
            for (int q = 0; q < nn; q++) {
                cur[q] = nxt[q];
            }
            cn = nn;
            if (cn == 0) {
                break;
            }
        }
    }
    for (int i = 0; i < M && !ok; i++) {
        if (v1[i] && v2[i] && v1[i] + v2[i] - 2 <= 8) {
            ok = 1;
        }
    }
    if (ok) {
        cout << "YES" << "\n";
    } else {
        cout << "NO" << "\n";
    }
    return 0;
}
