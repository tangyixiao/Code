#include <bits/stdc++.h>
using namespace std;

const int N = 2e5 + 5, SZ = 1 << 18;
int q, cnt, tp, tr[2 * SZ];
long long bs[N], be[N], bx[N], fp, tot, x, y, z, tg, v;
char dummy[N];

void upd(int p, int v) {
    int i = p + SZ;
    tr[i] = v;
    for (i >>= 1; i; i >>= 1) {
        tr[i] = max(tr[i << 1], tr[i << 1 | 1]);
    }
}

int qry(int l, int r) {
    int res = 0, a = l + SZ, b = r + SZ;
    for (; a <= b;) {
        if (a & 1) {
            res = max(res, tr[a++]);
        }
        if (!(b & 1)) {
            res = max(res, tr[b--]);
        }
        a >>= 1;
        b >>= 1;
    }
    return res;
}

int loc(long long t) {
    int l = 1, r = cnt;
    for (; l < r;) {
        int mid = (l + r) >> 1;
        if (be[mid] >= t) {
            r = mid;
        } else {
            l = mid + 1;
        }
    }
    return l;
}

signed main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cin >> q;
    fp = 1;
    for (int i = 1; i <= q; i++) {
        cin >> tp;
        if (tp == 1) {
            cin >> x;
            cnt++;
            bs[cnt] = tot + 1;
            be[cnt] = tot + x;
            bx[cnt] = x;
            tot += x;
            upd(cnt, (int)x);
        } else if (tp == 2) {
            cin >> y;
            fp += y;
        } else if (tp == 3) {
            cin >> z;
            tg = fp + z - 1;
            int id = loc(tg);
            cout << tg - bs[id] + 1 << "\n";
        } else {
            int id = loc(fp);
            cout << qry(id, cnt) << "\n";
        }
    }
    return 0;
}
