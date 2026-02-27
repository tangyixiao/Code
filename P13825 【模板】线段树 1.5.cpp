#include <iostream>
#include <memory>
#include <vector>
using namespace std;
using ll = long long;

// 动态节点结构体
struct Node {
    ll sum;     // 区间和
    ll lazy;    // 懒标记
    int lc, rc; // 左右子节点索引
    Node() : sum(0), lazy(0), lc(0), rc(0) {}
};

const int MAXN = 1e5 + 10; // 操作次数限制
vector<Node> nodes;        // 动态存储节点

// 创建新节点
int newNode() {
    nodes.emplace_back();
    return nodes.size() - 1;
}

// 初始化根节点
int build() {
    nodes.emplace_back();
    return 0; // 根节点索引为0
}

// 计算等差数列和
inline ll calcSum(ll l, ll r) {
    return (l + r) * (r - l + 1) / 2;
}

// 下传懒标记
void pushDown(int p, int l, int r) {
    if (nodes[p].lazy == 0)
        return;

    int mid = l + (r - l) / 2;

    // 左孩子
    if (nodes[p].lc == 0) {
        nodes[p].lc = newNode();
        nodes[nodes[p].lc].sum = calcSum(l, mid);
    }
    nodes[nodes[p].lc].sum += nodes[p].lazy * (mid - l + 1);
    nodes[nodes[p].lc].lazy += nodes[p].lazy;

    // 右孩子
    if (nodes[p].rc == 0) {
        nodes[p].rc = newNode();
        nodes[nodes[p].rc].sum = calcSum(mid + 1, r);
    }
    nodes[nodes[p].rc].sum += nodes[p].lazy * (r - mid);
    nodes[nodes[p].rc].lazy += nodes[p].lazy;

    nodes[p].lazy = 0;
}

// 区间更新
void update(int p, int l, int r, int ql, int qr, ll k) {
    if (ql <= l && r <= qr) {
        nodes[p].sum += k * (r - l + 1);
        nodes[p].lazy += k;
        return;
    }

    pushDown(p, l, r);
    int mid = l + (r - l) / 2;

    if (ql <= mid) {
        if (nodes[p].lc == 0) {
            nodes[p].lc = newNode();
            nodes[nodes[p].lc].sum = calcSum(l, mid);
        }
        update(nodes[p].lc, l, mid, ql, qr, k);
    }

    if (qr > mid) {
        if (nodes[p].rc == 0) {
            nodes[p].rc = newNode();
            nodes[nodes[p].rc].sum = calcSum(mid + 1, r);
        }
        update(nodes[p].rc, mid + 1, r, ql, qr, k);
    }

    // 更新当前节点的和
    nodes[p].sum = 0;
    if (nodes[p].lc)
        nodes[p].sum += nodes[nodes[p].lc].sum;
    if (nodes[p].rc)
        nodes[p].sum += nodes[nodes[p].rc].sum;
}

// 区间查询
ll query(int p, int l, int r, int ql, int qr) {
    if (ql <= l && r <= qr) {
        return nodes[p].sum;
    }

    pushDown(p, l, r);
    int mid = l + (r - l) / 2;
    ll res = 0;

    if (ql <= mid) {
        if (nodes[p].lc == 0) {
            // 节点不存在，返回初始值加上懒标记的影响
            int L = max(l, ql), R = min(mid, qr);
            if (L <= R) {
                res += calcSum(L, R) + nodes[p].lazy * (R - L + 1);
            }
        } else {
            res += query(nodes[p].lc, l, mid, ql, qr);
        }
    }

    if (qr > mid) {
        if (nodes[p].rc == 0) {
            // 节点不存在，返回初始值加上懒标记的影响
            int L = max(mid + 1, ql), R = min(r, qr);
            if (L <= R) {
                res += calcSum(L, R) + nodes[p].lazy * (R - L + 1);
            }
        } else {
            res += query(nodes[p].rc, mid + 1, r, ql, qr);
        }
    }

    return res;
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int n, m;
    cin >> n >> m;

    // 初始化节点池
    nodes.reserve(MAXN * 20); // 预留足够空间
    int root = build();

    // 初始化根节点的值（整个区间的初始和）
    nodes[root].sum = calcSum(1, n);

    while (m--) {
        int op, l, r;
        cin >> op >> l >> r;

        if (op == 1) {
            ll k;
            cin >> k;
            update(root, 1, n, l, r, k);
        } else {
            cout << query(root, 1, n, l, r) << "\n";
        }
    }

    return 0;
}