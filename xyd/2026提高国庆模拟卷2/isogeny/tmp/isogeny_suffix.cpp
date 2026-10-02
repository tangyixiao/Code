namespace TANGYIXIAO {
const int N = 2e5 + 5, M = 1e6 + 5, mod = 9.98244353e8;
int a[N], b[N], p[M], f[M], ans[M], cnt[M], c[M], s[M], v[M], u[M], vis[M];
int n, q, g, A, B, U, V, pc, sz, d, t, H, k, w, x, y, e, old, mul, r, pr[M], dv[1000], ep[16], pp[16];
long long h, choose;

inline int qpow(int x, int y) {
    r = 1;
    for (; y; y >>= 1, x = (long long)x * x % mod) {
        if (y & 1) { r = (long long)r * x % mod; }
    }
    return r;
}

inline void init(int lim) {
    for (int i = 2; i <= lim; i++) {
        if (!p[i]) { p[i] = i, pr[++pc] = i; }
        for (int j = 1; j <= pc && pr[j] <= p[i] && (long long)i * pr[j] <= lim; j++) { p[i * pr[j]] = pr[j]; }
    }
    f[1] = 1;
    for (int i = 2; i <= lim; i++) {
        x = i, e = 0;
        for (; x % p[i] == 0;) { x /= p[i], e++; }
        f[i] = (long long)f[x] * (e + 1) * (e + 2) / 2 % mod;
    }
    return;
}

inline void get(int x, int &sz) {
    k = 0;
    for (; x > 1;) {
        y = p[x], e = 0;
        for (; x % y == 0;) { x /= y, e++; }
        pp[k] = y, ep[k++] = e;
    }
    dv[0] = 1, sz = 1;
    for (int i = 0; i < k; i++) {
        old = sz, mul = 1;
        for (int j = 1; j <= ep[i]; j++) {
            mul *= pp[i];
            for (int z = 0; z < old; z++) { dv[sz++] = dv[z] * mul; }
        }
    }
    return;
}

inline void solve(int Task_Id) {
    cin >> n >> q;
    g = 0, A = B = 1, U = V = 0;
    for (int i = 1; i <= n; i++) { cin >> a[i], g = MATH::gcd(g, a[i]); }
    for (int i = 1; i <= q; i++) { cin >> b[i], B = max(B, b[i]); }
    for (int i = 1; i <= n; i++) {
        a[i] /= g, A = max(A, a[i]), c[a[i]]++;
        if (c[a[i]] == 1) { u[U++] = a[i]; }
    }
    init(max(A, B));
    for (int d0 = 1; d0 <= A; d0++) {
        for (int x0 = d0; x0 <= A; x0 += d0) { s[d0] += c[x0]; }
    }
    if (n == 3) {
        for (int d0 = 1; d0 <= B; d0++) { v[V++] = d0; }
    } else {
        for (int i = 1; i <= min(n, 4); i++) {
            get(a[i], sz);
            for (int j = 0; j < sz; j++) {
                d = dv[j];
                if (d <= B && s[d] >= n - 3 && !vis[d]) { vis[d] = 1, v[V++] = d; }
            }
        }
    }
    for (int z = 0; z < V; z++) {
        d = v[z], t = 0, h = 1;
        for (int i = 0; i < U; i++) {
            x = u[i], y = d / MATH::gcd(d, x), k = c[x];
            if (y > 1) {
                t += k;
                if (t > 3) { break; }
                for (int j = 0; j < k; j++) {
                    if (h > B / y) {
                        h = (long long)B + 1;
                        break;
                    }
                    h *= y;
                }
                if (h > B) { break; }
            }
        }
        if (t > 3 || h > B) { continue; }
        H = h, k = 3 - t, choose = 1;
        for (int i = 0; i < k; i++) { choose = choose * (n - t - i) % mod; }
        choose = choose * qpow(k == 3 ? 6 : (k == 2 ? 2 : 1), mod - 2) % mod;
        w = (long long)6 * choose % mod;
        for (int m = H; m <= B; m += H) {
            if (ans[m] < d) { ans[m] = d, cnt[m] = (long long)w * f[m / H] % mod; }
        }
    }
    for (int i = 1; i <= q; i++) { x = b[i], cout << (long long)g * ans[x] << ' ' << cnt[x] << '\n'; }
    return;
}
} // namespace TANGYIXIAO
