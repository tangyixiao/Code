#include <algorithm>
#include <climits>
#include <cstdlib>
#include <ctime>
#include <iostream>

using namespace std;

const int MAXN = 50010;
const int INF = 2147483647;

// ==================== Treap部分 ====================
struct TreapNode {
    int val;  // 节点值
    int cnt;  // 相同值的个数
    int size; // 子树大小（包括重复值）
    int pri;  // 随机优先级
    TreapNode *left, *right;

    TreapNode(int v) : val(v), cnt(1), size(1), pri(rand()), left(nullptr), right(nullptr) {}
};

// 更新节点大小
void update(TreapNode *node) {
    if (node) {
        node->size = node->cnt;
        if (node->left)
            node->size += node->left->size;
        if (node->right)
            node->size += node->right->size;
    }
}

// Treap旋转操作
void zig(TreapNode *&root) { // 右旋
    TreapNode *temp = root->left;
    root->left = temp->right;
    temp->right = root;
    update(root);
    update(temp);
    root = temp;
}

void zag(TreapNode *&root) { // 左旋
    TreapNode *temp = root->right;
    root->right = temp->left;
    temp->left = root;
    update(root);
    update(temp);
    root = temp;
}

// 插入值到Treap
void treap_insert(TreapNode *&root, int val) {
    if (!root) {
        root = new TreapNode(val);
        return;
    }

    if (val == root->val) {
        root->cnt++;
    } else if (val < root->val) {
        treap_insert(root->left, val);
        if (root->left->pri > root->pri) {
            zig(root);
        }
    } else {
        treap_insert(root->right, val);
        if (root->right->pri > root->pri) {
            zag(root);
        }
    }
    update(root);
}

// 从Treap中删除值
void treap_erase(TreapNode *&root, int val) {
    if (!root)
        return;

    if (val < root->val) {
        treap_erase(root->left, val);
    } else if (val > root->val) {
        treap_erase(root->right, val);
    } else {
        if (root->cnt > 1) {
            root->cnt--;
        } else if (!root->left || !root->right) {
            TreapNode *temp = root;
            root = (root->left) ? root->left : root->right;
            delete temp;
        } else {
            if (!root->right || (root->left && root->left->pri > root->right->pri)) {
                zig(root);
                treap_erase(root->right, val);
            } else {
                zag(root);
                treap_erase(root->left, val);
            }
        }
    }
    if (root)
        update(root);
}

// 查询Treap中严格小于val的值的个数
int treap_rank(TreapNode *root, int val) {
    if (!root)
        return 0;

    if (val < root->val) {
        return treap_rank(root->left, val);
    } else if (val == root->val) {
        return root->left ? root->left->size : 0;
    } else {
        int left_size = root->left ? root->left->size : 0;
        return left_size + root->cnt + treap_rank(root->right, val);
    }
}

// 查询Treap中严格小于val的最大值（前驱）
int treap_pre(TreapNode *root, int val) {
    if (!root)
        return INT_MIN;

    if (root->val >= val) {
        return treap_pre(root->left, val);
    } else {
        return max(root->val, treap_pre(root->right, val));
    }
}

// 查询Treap中严格大于val的最小值（后继）
int treap_suc(TreapNode *root, int val) {
    if (!root)
        return INT_MAX;

    if (root->val <= val) {
        return treap_suc(root->right, val);
    } else {
        return min(root->val, treap_suc(root->left, val));
    }
}

// ==================== 线段树部分 ====================
struct SegmentNode {
    int l, r;
    TreapNode *treap_root;
    SegmentNode *left, *right;

    SegmentNode() : treap_root(nullptr), left(nullptr), right(nullptr) {}
};

int arr[MAXN];

// 构建线段树
SegmentNode *build_segment_tree(int l, int r) {
    SegmentNode *node = new SegmentNode();
    node->l = l;
    node->r = r;

    // 将区间内的所有值插入Treap
    for (int i = l; i <= r; i++) {
        treap_insert(node->treap_root, arr[i]);
    }

    if (l != r) {
        int mid = (l + r) / 2;
        node->left = build_segment_tree(l, mid);
        node->right = build_segment_tree(mid + 1, r);
    }

    return node;
}

// 操作1：查询k在区间[l,r]中的排名（严格小于k的个数+1）
int query_rank(SegmentNode *node, int l, int r, int k) {
    if (node->l >= l && node->r <= r) {
        return treap_rank(node->treap_root, k);
    }

    int mid = (node->l + node->r) / 2;
    int res = 0;
    if (l <= mid) {
        res += query_rank(node->left, l, r, k);
    }
    if (r > mid) {
        res += query_rank(node->right, l, r, k);
    }
    return res;
}

// 操作2：查询区间[l,r]中排名为k的值（二分答案）
int query_kth(SegmentNode *root, int l, int r, int k) {
    // 二分答案：值域[0, 1e8]
    int left = 0, right = 100000000;
    int ans = 0;

    while (left <= right) {
        int mid = (left + right) / 2;
        // 查询mid在区间中的排名
        int rank = query_rank(root, l, r, mid) + 1;

        if (rank <= k) {
            ans = mid;
            left = mid + 1;
        } else {
            right = mid - 1;
        }
    }
    return ans;
}

// 操作3：修改位置pos的值为k
void update(SegmentNode *node, int pos, int old_val, int new_val) {
    // 在当前节点的Treap中更新
    treap_erase(node->treap_root, old_val);
    treap_insert(node->treap_root, new_val);

    if (node->l == node->r) {
        return;
    }

    int mid = (node->l + node->r) / 2;
    if (pos <= mid) {
        update(node->left, pos, old_val, new_val);
    } else {
        update(node->right, pos, old_val, new_val);
    }
}

// 操作4：查询区间[l,r]中k的前驱（严格小于k的最大值）
int query_pre(SegmentNode *node, int l, int r, int k) {
    if (node->l >= l && node->r <= r) {
        return treap_pre(node->treap_root, k);
    }

    int mid = (node->l + node->r) / 2;
    int res = INT_MIN;

    if (l <= mid) {
        res = max(res, query_pre(node->left, l, r, k));
    }
    if (r > mid) {
        res = max(res, query_pre(node->right, l, r, k));
    }

    return res;
}

// 操作5：查询区间[l,r]中k的后继（严格大于k的最小值）
int query_suc(SegmentNode *node, int l, int r, int k) {
    if (node->l >= l && node->r <= r) {
        return treap_suc(node->treap_root, k);
    }

    int mid = (node->l + node->r) / 2;
    int res = INT_MAX;

    if (l <= mid) {
        res = min(res, query_suc(node->left, l, r, k));
    }
    if (r > mid) {
        res = min(res, query_suc(node->right, l, r, k));
    }

    return res;
}

// 释放线段树内存（可选）
void free_segment_tree(SegmentNode *node) {
    if (!node)
        return;
    // 注意：这里没有释放Treap的内存，实际使用中应该释放
    free_segment_tree(node->left);
    free_segment_tree(node->right);
    delete node;
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);

    srand(time(0)); // 初始化随机数种子

    int n, m;
    cin >> n >> m;

    for (int i = 1; i <= n; i++) {
        cin >> arr[i];
    }

    // 构建线段树
    SegmentNode *root = build_segment_tree(1, n);

    for (int i = 0; i < m; i++) {
        int op, l, r, k, pos;
        cin >> op;

        if (op == 1) {
            // 查询k在区间[l,r]中的排名
            cin >> l >> r >> k;
            int rank = query_rank(root, l, r, k) + 1;
            cout << rank << '\n';
        } else if (op == 2) {
            // 查询区间[l,r]中排名为k的值
            cin >> l >> r >> k;
            int val = query_kth(root, l, r, k);
            cout << val << '\n';
        } else if (op == 3) {
            // 修改位置pos的值为k
            cin >> pos >> k;
            update(root, pos, arr[pos], k);
            arr[pos] = k;
        } else if (op == 4) {
            // 查询区间[l,r]中k的前驱
            cin >> l >> r >> k;
            int pre = query_pre(root, l, r, k);
            if (pre == INT_MIN) {
                cout << -INF << '\n';
            } else {
                cout << pre << '\n';
            }
        } else if (op == 5) {
            // 查询区间[l,r]中k的后继
            cin >> l >> r >> k;
            int suc = query_suc(root, l, r, k);
            if (suc == INT_MAX) {
                cout << INF << '\n';
            } else {
                cout << suc << '\n';
            }
        }
    }

    // 实际使用时，应该释放内存，这里为了清晰省略
    // free_segment_tree(root);

    return 0;
}