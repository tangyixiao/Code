#include <bits/stdc++.h>
using namespace std;

namespace TANGYIXIAO {
const int N = 305, K = 40;
const long long B = 1000000000LL;

struct Big {
    int a[K];

    Big() {
        memset(a, 0, sizeof(a));
    }
};

int n, k, m;
int fa[N][2], deg[N];
int e[N][N], ec[N];
int q[N], p[N], tot;

Big f[N][N], S;

void avg(Big &c, const Big &a, const Big &b) {
    long long v = 0;

    for (int i = 0; i < K; i++) {
        v += 1LL * a.a[i] + b.a[i];
        c.a[i] = v % B;
        v /= B;
    }

    v = 0;
    for (int i = K - 1; i >= 0; i--) {
        long long x = v * B + c.a[i];
        c.a[i] = x / 2;
        v = x & 1;
    }
}

void mul(Big &a, int x) {
    long long v = 0;

    for (int i = 0; i < K; i++) {
        v += 1LL * a.a[i] * x;
        a.a[i] = v % B;
        v /= B;
    }
}

string str(const Big &a) {
    int p = K - 1;

    for (; p > 0 && !a.a[p]; p--) {
    }

    string s = to_string(a.a[p]);

    for (int i = p - 1; i >= 0; i--) {
        string t = to_string(a.a[i]);
        s += string(9 - t.size(), '0') + t;
    }

    return s;
}

void print(const Big &a) {
    Big x = a;
    mul(x, 100);

    string s = str(x);

    if ((int)s.size() <= n) {
        s = string(n + 1 - s.size(), '0') + s;
    }

    s.insert(s.end() - n, '.');

    for (; !s.empty() && s.back() == '0';) {
        s.pop_back();
    }

    if (!s.empty() && s.back() == '.') {
        s.pop_back();
    }

    cout << s << "%\n";
}
} // namespace TANGYIXIAO

signed main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    using namespace TANGYIXIAO;

    cin >> n >> k;

    for (int i = 1; i <= k; i++) {
        int a, b, c;
        cin >> a >> b >> c;

        fa[a][0] = b;
        fa[a][1] = c;

        e[b][++ec[b]] = a;
        e[c][++ec[c]] = a;

        deg[a] += 2;
    }

    int l = 1, r = 0;

    for (int i = 1; i <= n; i++) {
        if (!deg[i]) {
            q[++r] = i;
        }
    }

    for (; l <= r; l++) {
        int x = q[l];
        p[++tot] = x;

        for (int i = 1; i <= ec[x]; i++) {
            int y = e[x][i];
            deg[y]--;

            if (!deg[y]) {
                q[++r] = y;
            }
        }
    }

    int x = 1;

    for (int i = 1; i <= n % 9; i++) {
        x *= 10;
    }

    S.a[n / 9] = x;

    for (int i = 1; i <= n; i++) {
        int x = p[i];

        f[x][x] = S;

        if (!fa[x][0]) {
            continue;
        }

        int a = fa[x][0], b = fa[x][1];

        for (int j = 1; j < i; j++) {
            int y = p[j];

            avg(f[x][y], f[a][y], f[b][y]);
            f[y][x] = f[x][y];
        }
    }

    cin >> m;

    for (int i = 1; i <= m; i++) {
        int x, y;
        cin >> x >> y;

        print(f[x][y]);
    }

    return 0;
}