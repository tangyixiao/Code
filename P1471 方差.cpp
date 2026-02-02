#include <iomanip>
#include <iostream>
#include <vector>
using namespace std;

struct Node {
    double sum;  // 区间和
    double sum2; // 区间平方和
    double lazy; // 懒标记

    Node() : sum(0), sum2(0), lazy(0) {}
};

class SegmentTree {
private:
    int n;
    vector<Node> tree;
    vector<double> arr;

    // 合并子节点信息到父节点
    void pushUp(int rt) {
        tree[rt].sum = tree[rt << 1].sum + tree[rt << 1 | 1].sum;
        tree[rt].sum2 = tree[rt << 1].sum2 + tree[rt << 1 | 1].sum2;
    }

    // 下推懒标记
    void pushDown(int rt, int l, int r) {
        if (tree[rt].lazy != 0) {
            int mid = (l + r) >> 1;
            int leftLen = mid - l + 1;
            int rightLen = r - mid;

            // 更新左子节点
            tree[rt << 1].sum2 += 2 * tree[rt].lazy * tree[rt << 1].sum + leftLen * tree[rt].lazy * tree[rt].lazy;
            tree[rt << 1].sum += leftLen * tree[rt].lazy;
            tree[rt << 1].lazy += tree[rt].lazy;

            // 更新右子节点
            tree[rt << 1 | 1].sum2 += 2 * tree[rt].lazy * tree[rt << 1 | 1].sum + rightLen * tree[rt].lazy * tree[rt].lazy;
            tree[rt << 1 | 1].sum += rightLen * tree[rt].lazy;
            tree[rt << 1 | 1].lazy += tree[rt].lazy;

            // 清空当前节点的懒标记
            tree[rt].lazy = 0;
        }
    }

    // 构建线段树
    void build(int rt, int l, int r) {
        tree[rt].lazy = 0;
        if (l == r) {
            tree[rt].sum = arr[l];
            tree[rt].sum2 = arr[l] * arr[l];
            return;
        }
        int mid = (l + r) >> 1;
        build(rt << 1, l, mid);
        build(rt << 1 | 1, mid + 1, r);
        pushUp(rt);
    }

    // 区间更新
    void update(int rt, int l, int r, int L, int R, double val) {
        if (L <= l && r <= R) {
            int len = r - l + 1;
            tree[rt].sum2 += 2 * val * tree[rt].sum + len * val * val;
            tree[rt].sum += len * val;
            tree[rt].lazy += val;
            return;
        }
        pushDown(rt, l, r);
        int mid = (l + r) >> 1;
        if (L <= mid)
            update(rt << 1, l, mid, L, R, val);
        if (R > mid)
            update(rt << 1 | 1, mid + 1, r, L, R, val);
        pushUp(rt);
    }

    // 区间查询
    pair<double, double> query(int rt, int l, int r, int L, int R) {
        if (L <= l && r <= R) {
            return {tree[rt].sum, tree[rt].sum2};
        }
        pushDown(rt, l, r);
        int mid = (l + r) >> 1;
        pair<double, double> left = {0, 0}, right = {0, 0};
        if (L <= mid)
            left = query(rt << 1, l, mid, L, R);
        if (R > mid)
            right = query(rt << 1 | 1, mid + 1, r, L, R);
        return {left.first + right.first, left.second + right.second};
    }

public:
    SegmentTree(vector<double>& nums) {
        n = nums.size() - 1;
        arr = nums;
        tree.resize(4 * (n + 1));
        build(1, 1, n);
    }

    // 区间加
    void add(int l, int r, double k) {
        update(1, 1, n, l, r, k);
    }

    // 查询区间平均数
    double queryAverage(int l, int r) {
        auto res = query(1, 1, n, l, r);
        double len = r - l + 1;
        return res.first / len;
    }

    // 查询区间方差
    double queryVariance(int l, int r) {
        auto res = query(1, 1, n, l, r);
        double sum = res.first;
        double sum2 = res.second;
        double len = r - l + 1;
        double avg = sum / len;
        return sum2 / len - avg * avg;
    }
};

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int n, m;
    cin >> n >> m;

    vector<double> arr(n + 1);
    for (int i = 1; i <= n; i++) {
        cin >> arr[i];
    }

    SegmentTree seg(arr);

    cout << fixed << setprecision(4);
    for (int i = 0; i < m; i++) {
        int op;
        cin >> op;

        if (op == 1) {
            int x, y;
            double k;
            cin >> x >> y >> k;
            seg.add(x, y, k);
        } else if (op == 2) {
            int x, y;
            cin >> x >> y;
            cout << seg.queryAverage(x, y) << "\n";
        } else {
            int x, y;
            cin >> x >> y;
            cout << seg.queryVariance(x, y) << "\n";
        }
    }

    return 0;
}