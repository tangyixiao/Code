#include <algorithm>
#include <cstring>
#include <iostream>

using namespace std;

const int N = 100005, B = 800, K = 130;
int n, m, a[N], bl[N], L[K], R[K], sz[K];
int srt[K][B];
int p[K][N];
long long f[K][K];
int tmp[N], tmp2[N], cnt[N];

long long mg(int *arr, int l, int r) {
    if (l >= r)
        return 0;
    int mid = (l + r) >> 1;
    long long res = mg(arr, l, mid) + mg(arr, mid + 1, r);
    int i = l, j = mid + 1, k = l;
    while (i <= mid && j <= r) {
        if (arr[i] <= arr[j])
            tmp2[k++] = arr[i++];
        else {
            res += mid - i + 1;
            tmp2[k++] = arr[j++];
        }
    }
    while (i <= mid)
        tmp2[k++] = arr[i++];
    while (j <= r)
        tmp2[k++] = arr[j++];
    for (i = l; i <= r; ++i)
        arr[i] = tmp2[i];
    return res;
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);
    cin >> n >> m;
    for (int i = 1; i <= n; ++i)
        cin >> a[i];
    int kc = (n + B - 1) / B;
    for (int i = 1; i <= kc; ++i) {
        L[i] = (i - 1) * B + 1;
        R[i] = min(i * B, n);
        sz[i] = R[i] - L[i] + 1;
    }
    for (int i = 1; i <= n; ++i)
        bl[i] = (i - 1) / B + 1;

    for (int i = 1; i <= kc; ++i) {
        for (int j = 0; j < sz[i]; ++j)
            srt[i][j] = a[L[i] + j];
        sort(srt[i], srt[i] + sz[i]);
    }

    for (int i = 1; i <= kc; ++i) {
        int len = sz[i];
        for (int j = 0; j < len; ++j)
            tmp[j] = a[L[i] + j];
        f[i][i] = mg(tmp, 0, len - 1);
    }

    for (int i = 1; i <= kc; ++i) {
        memcpy(p[i], p[i - 1], sizeof(int) * (n + 1));
        memset(cnt, 0, sizeof(int) * (n + 1));
        for (int j = L[i]; j <= R[i]; ++j)
            ++cnt[a[j]];
        int sum = 0;
        for (int v = 1; v <= n; ++v) {
            sum += cnt[v];
            p[i][v] += sum;
        }
    }

    for (int len = 2; len <= kc; ++len) {
        for (int i = 1; i + len - 1 <= kc; ++i) {
            int j = i + len - 1;
            long long cr = 0;
            int pp = 0;
            for (int x = 0; x < sz[i]; ++x) {
                int v = srt[i][x];
                while (pp < sz[j] && srt[j][pp] < v)
                    ++pp;
                cr += pp;
            }
            if (i + 1 <= j - 1)
                f[i][j] = f[i][j - 1] + f[i + 1][j] - f[i + 1][j - 1] + cr;
            else
                f[i][j] = f[i][i] + f[j][j] + cr;
        }
    }

    long long last = 0;
    int Lv[800], Rv[800];
    while (m--) {
        int l, r;
        cin >> l >> r;
        l ^= last;
        r ^= last;
        if (l > r)
            swap(l, r);
        int bl_l = bl[l], bl_r = bl[r];
        long long ans = 0;
        if (bl_l == bl_r) {
            int len = r - l + 1;
            for (int i = 0; i < len; ++i)
                tmp[i] = a[l + i];
            ans = mg(tmp, 0, len - 1);
        } else {
            if (bl_l + 1 <= bl_r - 1) {
                ans += f[bl_l + 1][bl_r - 1];
                int tot_mid = R[bl_r - 1] - L[bl_l + 1] + 1;
                for (int i = l; i <= R[bl_l]; ++i) {
                    int v = a[i];
                    int le = p[bl_r - 1][v] - p[bl_l][v];
                    ans += tot_mid - le;
                }
                for (int i = L[bl_r]; i <= r; ++i) {
                    int v = a[i];
                    int le = p[bl_r - 1][v] - p[bl_l][v];
                    ans += tot_mid - le;
                }
            }
            int L_len = R[bl_l] - l + 1;
            for (int i = 0; i < L_len; ++i)
                tmp[i] = a[l + i];
            ans += mg(tmp, 0, L_len - 1);

            int R_len = r - L[bl_r] + 1;
            for (int i = 0; i < R_len; ++i)
                tmp[i] = a[L[bl_r] + i];
            ans += mg(tmp, 0, R_len - 1);

            for (int i = 0; i < L_len; ++i)
                Lv[i] = a[l + i];
            for (int i = 0; i < R_len; ++i)
                Rv[i] = a[L[bl_r] + i];
            sort(Lv, Lv + L_len);
            sort(Rv, Rv + R_len);
            int pv = 0;
            for (int i = 0; i < L_len; ++i) {
                while (pv < R_len && Rv[pv] < Lv[i])
                    ++pv;
                ans += pv;
            }
        }
        cout << ans << '\n';
        last = ans;
    }
    return 0;
}