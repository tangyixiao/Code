#include <cstring>
#include <iostream>
#include <vector>

using namespace std;

typedef long long ll;
const int MOD = 1e9 + 7;

struct Matrix {
    ll m[4][4];
    Matrix() { memset(m, 0, sizeof(m)); }
    Matrix operator*(const Matrix &other) const {
        Matrix res;
        for (int i = 0; i < 4; i++) {
            for (int k = 0; k < 4; k++) {
                if (m[i][k] == 0)
                    continue;
                for (int j = 0; j < 4; j++) {
                    res.m[i][j] = (res.m[i][j] + m[i][k] * other.m[k][j]) % MOD;
                }
            }
        }
        return res;
    }
};

Matrix mat_pow(Matrix base, ll exp) {
    Matrix res;
    for (int i = 0; i < 4; i++)
        res.m[i][i] = 1;
    while (exp > 0) {
        if (exp & 1)
            res = res * base;
        base = base * base;
        exp >>= 1;
    }
    return res;
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int T;
    cin >> T;
    while (T--) {
        ll n, a1, a2, x, y;
        cin >> n >> a1 >> a2 >> x >> y;
        a1 %= MOD;
        a2 %= MOD;
        x %= MOD;
        y %= MOD;

        if (n == 1) {
            cout << (a1 * a1 % MOD) << '\n';
            continue;
        }

        Matrix M;
        M.m[0][0] = x * x % MOD;
        M.m[0][1] = y * y % MOD;
        M.m[0][2] = 2 * x % MOD * y % MOD;
        M.m[0][3] = 0;
        M.m[1][0] = 1;
        M.m[2][0] = x;
        M.m[2][2] = y;
        M.m[3][0] = x * x % MOD;
        M.m[3][1] = y * y % MOD;
        M.m[3][2] = 2 * x % MOD * y % MOD;
        M.m[3][3] = 1;

        Matrix Mn = mat_pow(M, n - 2);

        ll a2_sq = a2 * a2 % MOD;
        ll a1_sq = a1 * a1 % MOD;
        ll prod = a2 * a1 % MOD;
        ll s2 = (a1_sq + a2_sq) % MOD;

        ll ans = 0;

        ans = (ans + Mn.m[3][0] * a2_sq) % MOD;
        ans = (ans + Mn.m[3][1] * a1_sq) % MOD;
        ans = (ans + Mn.m[3][2] * prod) % MOD;
        ans = (ans + Mn.m[3][3] * s2) % MOD;

        cout << ans << '\n';
    }
    return 0;
}