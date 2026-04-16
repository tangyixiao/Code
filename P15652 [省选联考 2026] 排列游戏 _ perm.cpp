#include <algorithm>
#include <vector>


void init(int c, int t) {
    // 不需要初始化
}

int query(int l, int r);

std::vector<int> perm(int n) {
    // 1. 二分查找 0 的位置
    int l = 0, r = n - 1;
    while (l < r) {
        int mid = (l + r) / 2;
        if (query(0, mid) > 0)
            r = mid;
        else
            l = mid + 1;
    }
    int pos0 = l;

    int L = pos0, R = pos0;
    int mex = 1; // 当前 mex

    struct Op {
        int val;
        bool is_left;
    };
    std::vector<Op> ops;

    // 2. 双指针扩展，记录操作序列
    while (L > 0 || R < n - 1) {
        if (L > 0) {
            int res = query(L - 1, R);
            if (res > mex) {
                ops.push_back({mex, true});
                mex = res;
            } else {
                ops.push_back({-1, true});
            }
            --L;
        }
        if (R < n - 1) {
            int res = query(L, R + 1);
            if (res > mex) {
                ops.push_back({mex, false});
                mex = res;
            } else {
                ops.push_back({-1, false});
            }
            ++R;
        }
    }

    // 3. 确定关键值集合
    std::vector<bool> is_key(n, false);
    is_key[0] = true;
    for (auto &op : ops)
        if (op.val != -1)
            is_key[op.val] = true;

    // 4. 非关键值升序排列
    std::vector<int> nonkeys;
    for (int i = 0; i < n; ++i)
        if (!is_key[i])
            nonkeys.push_back(i);
    std::sort(nonkeys.begin(), nonkeys.end());

    // 5. 将非关键值按操作顺序填入空位
    int nk_idx = 0;
    for (auto &op : ops)
        if (op.val == -1)
            op.val = nonkeys[nk_idx++];

    // 6. 重建排列
    std::vector<int> left_vals, right_vals;
    for (auto &op : ops) {
        if (op.is_left)
            left_vals.push_back(op.val);
        else
            right_vals.push_back(op.val);
    }
    std::reverse(left_vals.begin(), left_vals.end());

    std::vector<int> q;
    q.reserve(n);
    q.insert(q.end(), left_vals.begin(), left_vals.end());
    q.push_back(0);
    q.insert(q.end(), right_vals.begin(), right_vals.end());

    return q;
}