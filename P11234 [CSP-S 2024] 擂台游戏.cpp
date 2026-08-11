#include <bits/stdc++.h>
using namespace std;
#define ls x << 1
#define rs x << 1 | 1
#define ll long long
const int N = (1 << 17) + 5;

int mx[20][N << 2], lg[N], aa[N], ok[N], a[N], c[N];
int n, m, nn = 1;
bool vis[N];
ll ans[N], sum;

struct node {
    ll sum;
    int x;
    bool tp, d;
} t[N << 2];

void build(int x, int l, int r) {
    if (l == r) {
        t[x].x = l;
        return;
    }
    int mid = (l + r) >> 1, k = lg[r - l + 1], d = t[x].d;
    build(ls, l, mid);
    build(rs, mid + 1, r);
    int w = a[t[x << 1 | d].x] >= k;
    t[x].x = t[x << 1 | (d ^ !w)].x;
    if (!d && w)
        t[x].tp = 1, ok[r]++, ok[mid]--;
    else
        t[x].tp = 0;
}

void build2(int x, int l, int r, int *m) {
    t[x].sum = 1LL * (l + r) * (r - l + 1) / 2;
    if (l == r)
        return;
    int mid = (l + r) >> 1, k = lg[r - l + 1];
    if (~m[x])
        m[ls] = m[rs] = m[x];
    else
        m[x << 1 | t[x].d] = k;
    build2(ls, l, mid, m);
    build2(rs, mid + 1, r, m);
}

void up(int x) {
    if (!vis[x]) {
        sum += x;
        vis[x] = 1;
    }
}

int rd() {
    char c;
    int f = 1;
    while (!isdigit(c = getchar()))
        if (c == '-')
            f = -1;
    int x = c - '0';
    while (isdigit(c = getchar()))
        x = x * 10 + (c ^ 48);
    return x * f;
}

char gc() {
    char c;
    while ((c = getchar()) <= ' ')
        ;
    return c;
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    n = rd();
    m = rd();

    for (int i = 1; i <= n; i++)
        aa[i] = rd();
    for (int i = 1; i <= m; i++)
        c[i] = rd();

    while (nn < n)
        nn <<= 1;

    for (int i = 2; i <= nn; i++)
        lg[i] = lg[i >> 1] + 1;

    for (int i = nn / 2; i; i >>= 1)
        for (int j = i; j < i * 2; j++)
            t[j].d = gc() - '0';

    memset(mx, -1, sizeof mx);

    for (int s = 0; (1 << s) <= nn; s++)
        build2(1 << s, 1, nn >> s, mx[s]);

    int T = rd();

    while (T--) {
        int y[4] = {rd(), rd(), rd(), rd()};

        for (int i = 1; i <= n; i++)
            a[i] = aa[i] ^ y[i & 3];

        memset(ok, 0, sizeof ok);

        build(1, 1, nn);

        unsigned long long res = 0;

        for (int i = nn, rt = 1, s = 0; i; i--) {
            if ((1 << lg[i]) == i) {
                if (i != nn) {
                    rt <<= 1;
                    s++;
                }
                memset(vis, 0, sizeof vis);
                sum = 0;
                up(t[rt].x);
            }

            ans[i] = sum;

            if ((ok[i] += ok[i + 1]))
                continue;

            up(i);

            int x = i + nn - 1;

            while (x != rt) {
                int d = x & 1;
                x >>= 1;

                if (!d) {
                    if (t[x].tp)
                        sum += t[rs].sum;
                    else
                        break;
                } else {
                    if (a[t[ls].x] >= mx[s][ls])
                        up(t[ls].x);
                }
            }
        }

        unsigned long long out = 0;

        for (int i = 1; i <= m; i++)
            out ^= (unsigned long long)i * (unsigned long long)ans[c[i]];

        cout << out << "\n";
    }

    return 0;
}