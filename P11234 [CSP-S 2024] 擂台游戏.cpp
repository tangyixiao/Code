#include <iostream>
using namespace std;
const int N = 1E5 + 5;
int n, m, A[N], C[N], D[19][1 << 17], win[1 << 19], a[1 << 18], V[N];
long long M[N];
int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);
    cin >> n >> m;
    for (int i = 0; i < n; ++i)
        cin >> A[i];
    for (int i = 0; i < m; ++i)
        cin >> C[i];
    int K = 0;
    while ((1 << K) < n)
        K++;
    for (int R = 1; R <= K; ++R) {
        string s;
        cin >> s;
        for (int G = 1; G <= (1 << (K - R)); ++G)
            D[R][G] = s[G - 1] - '0';
    }
    int T;
    cin >> T;
    for (int t = 1; t <= T; ++t) {
        int X[4];
        cin >> X[0] >> X[1] >> X[2] >> X[3];
        for (int i = 0; i < n; ++i)
            a[i] = A[i] ^ X[(i + 1) % 4];
        for (int i = n; i < (1 << K); ++i)
            a[i] = 0;
        for (int i = 0; i < (1 << K); ++i)
            win[(1 << K) + i] = i;
        for (int R = 1; R <= K; ++R) {
            for (int G = 1; G <= (1 << (K - R)); ++G) {
                int u = (1 << (K - R)) + G - 1, ls = 2 * u, rs = 2 * u + 1;
                win[u] = D[R][G] ? (a[win[rs]] >= R ? win[rs] : win[ls]) : (a[win[ls]] >= R ? win[ls] : win[rs]);
            }
        }
        long long F = 0;
        for (int i = 0; i < m; ++i) {
            int c = C[i];
            if (V[c] == t) {
                F ^= 1LL * (i + 1) * M[c];
                continue;
            }
            int k = 0;
            while ((1 << k) < c)
                k++;
            long long ans = 0;
            if (c == (1 << k))
                ans = win[1 << (K - k)] + 1;
            else {
                long long Sum = c + 1;
                int cands[18], sz = 0;
                for (int R = 1; R <= k; ++R) {
                    int p = ((1 << K) + c) >> R, ls = 2 * p, rs = 2 * p + 1;
                    int d = D[R][p - (1 << (K - R)) + 1];
                    if ((c >> (R - 1)) & 1) {
                        int w = win[ls], ncands[18], nsz = 0;
                        long long RS = Sum;
                        Sum = 0;
                        if (d == 0) {
                            bool ll = (a[w] < R);
                            Sum = ll ? RS : 0;
                            if (a[w] >= R)
                                ncands[nsz++] = w;
                            if (ll)
                                for (int j = 0; j < sz; ++j)
                                    ncands[nsz++] = cands[j];
                        } else {
                            bool rl = (RS > 0);
                            for (int j = 0; !rl && j < sz; ++j)
                                if (a[cands[j]] < R)
                                    rl = true;
                            Sum = RS;
                            for (int j = 0; j < sz; ++j)
                                if (a[cands[j]] >= R)
                                    ncands[nsz++] = cands[j];
                            if (rl)
                                ncands[nsz++] = w;
                        }
                        sz = nsz;
                        for (int j = 0; j < sz; ++j)
                            cands[j] = ncands[j];
                    } else {
                        long long LS = Sum, cnt = 1LL << (R - 1);
                        long long fv = ((1LL * rs) << (R - 1)) - (1 << K) + 1;
                        long long RS = (fv * 2 + cnt - 1) * cnt / 2;
                        Sum = 0;
                        int ncands[18], nsz = 0;
                        if (d == 0) {
                            bool ll = (LS > 0);
                            for (int j = 0; !ll && j < sz; ++j)
                                if (a[cands[j]] < R)
                                    ll = true;
                            Sum = LS + (ll ? RS : 0);
                            for (int j = 0; j < sz; ++j)
                                if (a[cands[j]] >= R)
                                    ncands[nsz++] = cands[j];
                            sz = nsz;
                            for (int j = 0; j < sz; ++j)
                                cands[j] = ncands[j];
                        } else
                            Sum = RS + LS;
                    }
                }
                ans = Sum;
                for (int j = 0; j < sz; ++j)
                    ans += cands[j] + 1;
            }
            V[c] = t;
            M[c] = ans;
            F ^= 1LL * (i + 1) * ans;
        }
        cout << F << '\n';
    }
}