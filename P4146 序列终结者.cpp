#include <bits/stdc++.h>
using namespace std;

const int INF = 0x3f3f3f3f;
const int N = 100010;

struct Node {
    int l, r;      // 左右子树
    int val, mx;   // 当前值，子树最大值
    int add, rev;  // 加法标记，翻转标记
    int sz, rnd;   // 子树大小，随机优先级
} tr[N];

int root, idx;

int new_node(int v) {
    idx++;
    tr[idx].l = tr[idx].r = 0;
    tr[idx].val = v;
    tr[idx].mx = v;
    tr[idx].add = 0;
    tr[idx].rev = 0;
    tr[idx].sz = 1;
    tr[idx].rnd = rand();
    return idx;
}

void pushup(int p) {
    if (!p) return;
    tr[p].sz = tr[tr[p].l].sz + tr[tr[p].r].sz + 1;
    tr[p].mx = tr[p].val;
    if (tr[p].l) tr[p].mx = max(tr[p].mx, tr[tr[p].l].mx);
    if (tr[p].r) tr[p].mx = max(tr[p].mx, tr[tr[p].r].mx);
}

void pushdown(int p) {
    if (!p) return;
    
    // 处理加法标记
    if (tr[p].add) {
        if (tr[p].l) {
            tr[tr[p].l].add += tr[p].add;
            tr[tr[p].l].val += tr[p].add;
            tr[tr[p].l].mx += tr[p].add;
        }
        if (tr[p].r) {
            tr[tr[p].r].add += tr[p].add;
            tr[tr[p].r].val += tr[p].add;
            tr[tr[p].r].mx += tr[p].add;
        }
        tr[p].add = 0;
    }
    
    // 处理翻转标记
    if (tr[p].rev) {
        swap(tr[p].l, tr[p].r);
        if (tr[p].l) tr[tr[p].l].rev ^= 1;
        if (tr[p].r) tr[tr[p].r].rev ^= 1;
        tr[p].rev = 0;
    }
}

// 按大小分裂：前k个节点分到x，剩余分到y
void split(int p, int k, int &x, int &y) {
    if (!p) {
        x = y = 0;
        return;
    }
    pushdown(p);
    int lsz = tr[tr[p].l].sz;
    if (lsz < k) {
        x = p;
        split(tr[p].r, k - lsz - 1, tr[x].r, y);
        pushup(x);
    } else {
        y = p;
        split(tr[p].l, k, x, tr[y].l);
        pushup(y);
    }
}

// 合并两棵树
int merge(int x, int y) {
    if (!x || !y) return x | y;
    pushdown(x);
    pushdown(y);
    
    if (tr[x].rnd < tr[y].rnd) {
        tr[x].r = merge(tr[x].r, y);
        pushup(x);
        return x;
    } else {
        tr[y].l = merge(x, tr[y].l);
        pushup(y);
        return y;
    }
}

// 中序遍历（调试用）
void dfs(int p) {
    if (!p) return;
    pushdown(p);
    dfs(tr[p].l);
    cout << tr[p].val << " ";
    dfs(tr[p].r);
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    
    srand(time(0));
    
    int n, m;
    cin >> n >> m;
    
    // 初始化序列，所有元素为0
    for (int i = 1; i <= n; i++) {
        root = merge(root, new_node(0));
    }
    
    while (m--) {
        int op, l, r, v;
        cin >> op >> l >> r;
        
        int x, y, z;
        split(root, r, x, z);      // x: [1, r], z: [r+1, n]
        split(x, l - 1, x, y);     // x: [1, l-1], y: [l, r]
        
        if (op == 1) {  // 区间加
            cin >> v;
            if (y) {
                tr[y].add += v;
                tr[y].val += v;
                tr[y].mx += v;
            }
        } else if (op == 2) {  // 区间翻转
            if (y) {
                tr[y].rev ^= 1;
            }
        } else if (op == 3) {  // 查询区间最大值
            if (y) {
                cout << tr[y].mx << "\n";
            } else {
                cout << "0\n";  // 空区间，但实际上不会出现
            }
        }
        
        // 合并回去
        root = merge(merge(x, y), z);
    }
    
    return 0;
}