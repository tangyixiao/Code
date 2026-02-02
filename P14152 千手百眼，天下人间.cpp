#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

const int MAXN = 500005;

struct Operation {
    int type;      // 1:修改 2:查询 3:撤销
    int id;        // 输入顺序编号
    ll t;          // 发生时间
    int l, r;      // 对于修改/查询是序列区间，对于撤销是时间区间
    ll k;          // 修改的增量
    int tid;       // 离散化后的时间索引
};

int n, m;
vector<ll> init_a;
vector<Operation> ops;
vector<ll> times;          // 所有出现的时间值
vector<vector<int>> time_ops;  // 每个时间索引上的操作列表（操作编号）

set<int> alive_tids;       // 未被覆盖的时间索引

// ---------- 序列线段树 ----------
struct SegTree {
    struct Node {
        ll max_val;
        ll lazy;
    };
    vector<Node> tree;
    int n;

    SegTree(int _n, vector<ll>& a) {
        n = _n;
        tree.resize(4 * n);
        build(1, 1, n, a);
    }

    void build(int idx, int l, int r, vector<ll>& a) {
        if (l == r) {
            tree[idx].max_val = a[l];
            tree[idx].lazy = 0;
            return;
        }
        int mid = (l + r) / 2;
        build(idx * 2, l, mid, a);
        build(idx * 2 + 1, mid + 1, r, a);
        tree[idx].max_val = max(tree[idx * 2].max_val, tree[idx * 2 + 1].max_val);
        tree[idx].lazy = 0;
    }

    void push_down(int idx) {
        if (tree[idx].lazy != 0) {
            tree[idx * 2].max_val += tree[idx].lazy;
            tree[idx * 2].lazy += tree[idx].lazy;
            tree[idx * 2 + 1].max_val += tree[idx].lazy;
            tree[idx * 2 + 1].lazy += tree[idx].lazy;
            tree[idx].lazy = 0;
        }
    }

    void range_add(int idx, int l, int r, int L, int R, ll val) {
        if (L <= l && r <= R) {
            tree[idx].max_val += val;
            tree[idx].lazy += val;
            return;
        }
        push_down(idx);
        int mid = (l + r) / 2;
        if (L <= mid) range_add(idx * 2, l, mid, L, R, val);
        if (R > mid) range_add(idx * 2 + 1, mid + 1, r, L, R, val);
        tree[idx].max_val = max(tree[idx * 2].max_val, tree[idx * 2 + 1].max_val);
    }

    ll range_max(int idx, int l, int r, int L, int R) {
        if (L <= l && r <= R) {
            return tree[idx].max_val;
        }
        push_down(idx);
        int mid = (l + r) / 2;
        ll res = -1e18;
        if (L <= mid) res = max(res, range_max(idx * 2, l, mid, L, R));
        if (R > mid) res = max(res, range_max(idx * 2 + 1, mid + 1, r, L, R));
        return res;
    }
};

int main() {
    scanf("%d%d", &n, &m);
    init_a.resize(n + 1);
    for (int i = 1; i <= n; i++) {
        scanf("%lld", &init_a[i]);
    }

    ops.resize(m + 1);
    for (int i = 1; i <= m; i++) {
        int opt;
        scanf("%d", &opt);
        ops[i].id = i;
        ops[i].type = opt;
        if (opt == 1) {
            scanf("%lld%d%d%lld", &ops[i].t, &ops[i].l, &ops[i].r, &ops[i].k);
            times.push_back(ops[i].t);
        } else if (opt == 2) {
            scanf("%lld%d%d", &ops[i].t, &ops[i].l, &ops[i].r);
            ops[i].k = 0;
            times.push_back(ops[i].t);
        } else { // opt == 3
            scanf("%lld%d%d", &ops[i].t, &ops[i].l, &ops[i].r);
            ops[i].k = 0;
            times.push_back(ops[i].t);
            times.push_back(ops[i].l);
            times.push_back(ops[i].r);
        }
    }

    // 离散化时间
    sort(times.begin(), times.end());
    times.erase(unique(times.begin(), times.end()), times.end());
    int M = times.size();
    time_ops.resize(M + 1);

    for (int i = 1; i <= m; i++) {
        ll t = ops[i].t;
        int tid = lower_bound(times.begin(), times.end(), t) - times.begin() + 1;
        ops[i].tid = tid;
        time_ops[tid].push_back(i);
    }

    // 初始化所有时间索引为有效
    for (int tid = 1; tid <= M; tid++) {
        alive_tids.insert(tid);
    }

    // 从后往前处理撤销操作，确定有效的时间点
    for (int tid = M; tid >= 1; tid--) {
        vector<int>& op_ids = time_ops[tid];
        // 逆序遍历该时间点上的操作（id从大到小）
        for (int j = op_ids.size() - 1; j >= 0; j--) {
            int op_id = op_ids[j];
            Operation& op = ops[op_id];
            if (op.type != 3) continue;
            // 检查当前撤销操作是否有效（其时间点未被覆盖）
            if (alive_tids.find(tid) == alive_tids.end()) continue;

            // 有效，则覆盖区间 [op.l, op.r]
            ll Lv = op.l, Rv = op.r;
            int L_idx = lower_bound(times.begin(), times.end(), Lv) - times.begin() + 1;
            int R_idx = upper_bound(times.begin(), times.end(), Rv) - times.begin(); // 注意：upper_bound - begin 得到的是最后一个小于等于Rv的下标+1
            if (L_idx <= R_idx) {
                auto it = alive_tids.lower_bound(L_idx);
                while (it != alive_tids.end() && *it <= R_idx) {
                    it = alive_tids.erase(it);
                }
            }
        }
    }

    // 第二阶段：按照时间顺序执行有效操作
    SegTree seg(n, init_a);
    vector<ll> answers;

    // alive_tids 本身有序（从小到大）
    for (int tid : alive_tids) {
        vector<int>& op_ids = time_ops[tid];
        // 同一时间点内按 id 升序执行
        for (int op_id : op_ids) {
            Operation& op = ops[op_id];
            if (op.type == 1) {
                seg.range_add(1, 1, n, op.l, op.r, op.k);
            } else if (op.type == 2) {
                ll max_val = seg.range_max(1, 1, n, op.l, op.r);
                answers.push_back(max_val);
            }
            // type == 3 忽略
        }
    }

    // 输出
    printf("%d\n", (int)answers.size());
    for (ll ans : answers) {
        printf("%lld\n", ans);
    }

    return 0;
}