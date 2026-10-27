#include <bits/stdc++.h>
using namespace std;

int M, N;
long long E;
int cost[8];
char g[105][105];
int seen[105][105][2][2];
int seenpos[105][105][2][2];
long long pref[1000005];

signed main() {
    ios::sync_with_stdio(false);
    cin.tie(0);
    cin >> M >> N >> E;
    for (int i = 0; i < 8; i++) {
        cin >> cost[i];
    }
    for (int i = 0; i < M + 2; i++) {
        for (int j = 0; j < N + 2; j++) {
            g[i][j] = ' ';
        }
    }
    int r = 1, c = 1, dr = 1, dc = 1;
    long long s = 0;
    for (int loop = 0; loop < 1000000; loop++) {
        if (E <= 0 || r < 1 || r > M || c < 1 || c > N) {
            break;
        }
        int a = (dr > 0) ? 1 : 0, b = (dc > 0) ? 1 : 0;
        if (seen[r][c][a][b]) {
            int k = seenpos[r][c][a][b];
            long long cyc = pref[s] - pref[k];
            if (cyc == 0) {
                break;
            }
            long long times = (E - 1) / cyc;
            if (times > 0) {
                E -= times * cyc;
            }
            for (int i = 0; i < M + 2; i++) {
                for (int j = 0; j < N + 2; j++) {
                    seen[i][j][0][0] = seen[i][j][0][1] = 0;
                    seen[i][j][1][0] = seen[i][j][1][1] = 0;
                }
            }
            s = 0;
            pref[0] = 0;
        }
        seen[r][c][a][b] = 1;
        seenpos[r][c][a][b] = (int)s;
        if (dr * dc > 0) {
            g[r][c] = '\\';
        } else {
            g[r][c] = '/';
        }
        int lr = (dr > 0) ? r : r - 1;
        int lc = (dc > 0) ? c : c - 1;
        int cst = 0;
        int fr = 0, fc = 0;
        int top = (lr == 0), bot = (lr == M), lef = (lc == 0), rig = (lc == N);
        if (top && lef) {
            cst = cost[4], fr = 1, fc = 1;
        } else if (top && rig) {
            cst = cost[5], fr = 1, fc = 1;
        } else if (bot && rig) {
            cst = cost[6], fr = 1, fc = 1;
        } else if (bot && lef) {
            cst = cost[7], fr = 1, fc = 1;
        } else if (top) {
            cst = cost[0], fr = 1;
        } else if (rig) {
            cst = cost[1], fc = 1;
        } else if (bot) {
            cst = cost[2], fr = 1;
        } else if (lef) {
            cst = cost[3], fc = 1;
        }
        E -= cst;
        s++;
        pref[s] = pref[s - 1] + cst;
        if (E <= 0) {
            break;
        }
        if (fr) {
            dr = -dr;
        }
        if (fc) {
            dc = -dc;
        }
        r = (dr > 0) ? lr + 1 : lr;
        c = (dc > 0) ? lc + 1 : lc;
    }
    for (int i = 0; i < N; i++) {
        cout << "-";
    }
    cout << "\n";
    for (int i = 1; i <= M; i++) {
        cout << "|";
        for (int j = 1; j <= N; j++) {
            cout << g[i][j];
        }
        cout << "|\n";
    }
    cout << " ";
    for (int i = 0; i < N; i++) {
        cout << "-";
    }
    cout << "\n";
    return 0;
}
