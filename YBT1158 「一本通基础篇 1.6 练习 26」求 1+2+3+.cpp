#include <bits/stdc++.h>
using namespace std;

const int N = 1 << 21;
const double PI = acos(-1.0);

complex<double> fa[N], fb[N], tw[N >> 1];
int dg[N >> 1], n1[N >> 1], aa[N >> 1], bb[N >> 1], cc[N];
char s[N];

void fft(complex<double> *f, int n, int inv) {
    int i, j, len, half, sh;
    for (i = 1, j = 0; i < n; i++) {
        int bit = n >> 1;
        for (; j & bit; bit >>= 1) {
            j ^= bit;
        }
        j ^= bit;
        if (i < j) {
            swap(f[i], f[j]);
        }
    }
    for (len = 2; len <= n; len <<= 1) {
        half = len >> 1, sh = n / len;
        for (i = 0; i < n; i += len) {
            for (j = 0; j < half; j++) {
                complex<double> w = tw[j * sh], u = f[i + j], v;
                if (inv) {
                    w = conj(w);
                }
                v = f[i + j + half] * w;
                f[i + j] = u + v, f[i + j + half] = u - v;
            }
        }
    }
    if (inv) {
        for (i = 0; i < n; i++) {
            f[i] /= n;
        }
    }
}

int half(int *x, int n, int *y) {
    int i, r = 0, cur, m = n;
    for (i = n - 1; i >= 0; i--) {
        cur = r * 10 + x[i];
        y[i] = cur / 2, r = cur % 2;
    }
    while (m > 1 && y[m - 1] == 0) {
        m--;
    }
    return m;
}

signed main() {
    scanf("%s", s);
    int L = strlen(s), i, j, na, nb, len = 1, top, total;
    for (i = 0; i < L; i++) {
        dg[i] = s[L - 1 - i] - '0', n1[i] = dg[i];
    }
    int l1 = L, r = 1, v;
    for (i = 0; i < L && r > 0; i++) {
        v = n1[i] + r;
        n1[i] = v % 10, r = v / 10;
    }
    if (r > 0) {
        n1[L] = r, l1 = L + 1;
    }
    if (dg[0] % 2 == 0) {
        na = half(dg, L, aa), nb = l1;
        for (i = 0; i < l1; i++) {
            bb[i] = n1[i];
        }
    } else {
        na = half(n1, l1, aa), nb = L;
        for (i = 0; i < L; i++) {
            bb[i] = dg[i];
        }
    }
    total = na + nb;
    while (len < total) {
        len <<= 1;
    }
    for (i = 0; i < (len >> 1); i++) {
        tw[i] = complex<double>(cos(2 * PI * i / len), sin(2 * PI * i / len));
    }
    for (i = 0; i < len; i++) {
        fa[i] = 0, fb[i] = 0;
    }
    for (i = 0; i < na; i++) {
        fa[i] = aa[i];
    }
    for (i = 0; i < nb; i++) {
        fb[i] = bb[i];
    }
    fft(fa, len, 0), fft(fb, len, 0);
    for (i = 0; i < len; i++) {
        fa[i] *= fb[i];
    }
    fft(fa, len, 1);
    for (i = 0; i <= total; i++) {
        cc[i] = 0;
    }
    for (i = 0; i < total; i++) {
        cc[i] = (int)floor(fa[i].real() + 0.5);
    }
    for (i = 0; i < total; i++) {
        if (cc[i] >= 10) {
            cc[i + 1] += cc[i] / 10, cc[i] %= 10;
        }
    }
    top = total;
    while (top > 0 && cc[top] == 0) {
        top--;
    }
    for (i = top; i >= 0; i--) {
        putchar('0' + cc[i]);
    }
    putchar('\n');
    return 0;
}
