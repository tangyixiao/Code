#include <cstdio>
#define ls (rt << 1)
#define rs (rt << 1 | 1)
int n, m;

struct node {
    int val, pre, suf, pure;
} tree[200005 << 2];

node Merge(node x, node y) {
    node ans;
    ans.pre = x.pre;
    if (x.pure)
        ans.pre |= y.pre;
    ans.suf = y.suf;
    if (y.pure)
        ans.suf |= x.suf;
    ans.pure = x.pure & y.pure;
    if (x.suf && y.pre) {
        ans.val = x.val + y.val + 1;
    } else {
        ans.val = x.val + y.val;
    }
    return ans;
}

void build(int rt, int l, int r) {
    if (l == r) {
        if (l == 1)
            tree[rt].suf = 1;
        else if (r == n)
            tree[rt].pre = 1;
        else
            tree[rt].pure = 1;
        return;
    }
    int mid = l + r >> 1;
    build(ls, l, mid);
    build(rs, mid + 1, r);
    tree[rt] = Merge(tree[ls], tree[rs]);
}

void upload(int rt, int l, int r, int id, char C) {
    if (l == r) {
        tree[rt] = {0, 0, 0, 0};
        if (C == '(')
            tree[rt].suf = 1;
        else if (C == ')')
            tree[rt].pre = 1;
        else
            tree[rt].pure = 1;
        return;
    }
    int mid = l + r >> 1;
    if (id <= mid) {
        upload(ls, l, mid, id, C);
    } else {
        upload(rs, mid + 1, r, id, C);
    }
    tree[rt] = Merge(tree[ls], tree[rs]);
}

node query(int rt, int l, int r, int L, int R) {
    if (l == L && r == R) {
        return tree[rt];
    }
    int mid = l + r >> 1;
    if (R <= mid) {
        return query(ls, l, mid, L, R);
    } else if (L > mid) {
        return query(rs, mid + 1, r, L, R);
    } else {
        return Merge(query(ls, l, mid, L, mid), query(rs, mid + 1, r, mid + 1, R));
    }
}

int main() {
    scanf("%d%d", &n, &m);
    build(1, 1, n);
    int op;
    for (int i = 1; i <= m; i++) {
        scanf("%d", &op);
        if (op == 1) {
            int x;
            char c;
            scanf("%d %c", &x, &c);
            upload(1, 1, n, x, c);
        } else {
            int l, r;
            scanf("%d%d", &l, &r);
            node ans = query(1, 1, n, l, r);
            printf("%d\n", ans.val);
        }
    }
    return 0;
}
