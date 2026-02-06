#include <algorithm>
#include <cmath>
#include <cstdio>
#include <cstring>
#include <iostream>

using namespace std;

const int MAXN = 1400000;
const int MAXM = 1400000;
const int MAXC = 1000010;

int n, m, block;
int a[MAXN];
int cnt[MAXC];
int ans[MAXM];

struct Query {
    int l, r, t, id;
    bool operator<(const Query &b) const {
        if (l / block != b.l / block)
            return l / block < b.l / block;
        if (r / block != b.r / block)
            return r / block < b.r / block;
        return t < b.t;
    }
} q[MAXM];

struct Modify {
    int pos, old_color, new_color;
} c[MAXM];

int qcnt = 0, ccnt = 0;

int nowAns = 0;

void add(int x) {
    if (cnt[x] == 0) {
        nowAns++;
    }
    cnt[x]++;
}

void del(int x) {
    cnt[x]--;
    if (cnt[x] == 0) {
        nowAns--;
    }
}

void update(int cur, int l, int r) {
    int pos = c[cur].pos;
    if (l <= pos && pos <= r) {
        del(c[cur].old_color);
        add(c[cur].new_color);
    }
    a[pos] = c[cur].new_color;
}

void undo(int cur, int l, int r) {
    int pos = c[cur].pos;
    if (l <= pos && pos <= r) {
        del(c[cur].new_color);
        add(c[cur].old_color);
    }
    a[pos] = c[cur].old_color;
}

int main() {
    scanf("%d%d", &n, &m);
    for (int i = 1; i <= n; i++) {
        scanf("%d", &a[i]);
    }

    for (int i = 1; i <= m; i++) {
        char op[2];
        int x, y;
        scanf("%s%d%d", op, &x, &y);
        if (op[0] == 'Q') {
            qcnt++;
            q[qcnt] = {x, y, ccnt, qcnt};
        } else {
            ccnt++;
            c[ccnt] = {x, a[x], y};
            a[x] = y;
        }
    }

    // 恢复初始数组
    for (int i = ccnt; i >= 1; i--) {
        a[c[i].pos] = c[i].old_color;
    }

    block = pow(n, 2.0 / 3.0);
    sort(q + 1, q + qcnt + 1);

    int curL = 1, curR = 0, curT = 0;
    nowAns = 0;

    for (int i = 1; i <= qcnt; i++) {
        int L = q[i].l, R = q[i].r, T = q[i].t;
        // 调整时间
        while (curT < T) {
            curT++;
            update(curT, curL, curR);
        }
        while (curT > T) {
            undo(curT, curL, curR);
            curT--;
        }
        // 调整左右指针
        while (curL > L) {
            curL--;
            add(a[curL]);
        }
        while (curR < R) {
            curR++;
            add(a[curR]);
        }
        while (curL < L) {
            del(a[curL]);
            curL++;
        }
        while (curR > R) {
            del(a[curR]);
            curR--;
        }
        ans[q[i].id] = nowAns;
    }

    for (int i = 1; i <= qcnt; i++) {
        printf("%d\n", ans[i]);
    }
    return 0;
}