#include <iostream>
#include <sstream>
#include <stack>
#include <string>
#include <unordered_map>
#include <vector>

using namespace std;

struct Node {
    int type;        // 0:变量，1:!，2:&，3:|
    int left, right; // 子节点索引，变量和!只有left有效，!的right=-1
    int var_id;      // 变量下标（仅变量节点有效）
    bool val;        // 节点值
    bool important;  // 是否重要（改变会影响根节点）
};

int main() {
    // 读入表达式
    string s;
    getline(cin, s);
    stringstream ss(s);
    vector<Node> nodes;
    stack<int> st;               // 构建树时使用的栈，存放节点索引
    unordered_map<int, int> pos; // 变量下标 -> 节点索引

    string token;
    while (ss >> token) {
        if (token[0] == 'x') {
            // 变量
            int id = stoi(token.substr(1));
            int idx = nodes.size();
            nodes.push_back({0, -1, -1, id, false, false});
            st.push(idx);
            pos[id] = idx;
        } else if (token == "!") {
            // 一元取反
            int child = st.top();
            st.pop();
            int idx = nodes.size();
            nodes.push_back({1, child, -1, -1, false, false});
            st.push(idx);
        } else if (token == "&") {
            // 二元与
            int right = st.top();
            st.pop();
            int left = st.top();
            st.pop();
            int idx = nodes.size();
            nodes.push_back({2, left, right, -1, false, false});
            st.push(idx);
        } else if (token == "|") {
            // 二元或
            int right = st.top();
            st.pop();
            int left = st.top();
            st.pop();
            int idx = nodes.size();
            nodes.push_back({3, left, right, -1, false, false});
            st.push(idx);
        }
    }
    int root = st.top(); // 根节点索引

    // 读入变量个数和初始值
    int n;
    cin >> n;
    vector<bool> init_val(n + 1);
    for (int i = 1; i <= n; i++) {
        int v;
        cin >> v;
        init_val[i] = (v == 1);
    }

    // 非递归后序遍历，计算每个节点的值
    stack<pair<int, int>> calc_stack; // (节点索引, 状态) 状态0:未处理子节点，1:已处理子节点
    calc_stack.push({root, 0});
    while (!calc_stack.empty()) {
        auto [u, state] = calc_stack.top();
        calc_stack.pop();
        Node &node = nodes[u];
        if (state == 0) {
            calc_stack.push({u, 1});
            if (node.type == 1) { // !
                calc_stack.push({node.left, 0});
            } else if (node.type == 2 || node.type == 3) { // & 或 |
                calc_stack.push({node.right, 0});
                calc_stack.push({node.left, 0});
            }
        } else {
            // 计算当前节点的值
            if (node.type == 0) { // 变量
                node.val = init_val[node.var_id];
            } else if (node.type == 1) { // !
                node.val = !nodes[node.left].val;
            } else if (node.type == 2) { // &
                node.val = nodes[node.left].val && nodes[node.right].val;
            } else if (node.type == 3) { // |
                node.val = nodes[node.left].val || nodes[node.right].val;
            }
        }
    }

    bool root_val = nodes[root].val;

    // 传递重要标记
    stack<int> imp_stack;
    nodes[root].important = true;
    imp_stack.push(root);
    while (!imp_stack.empty()) {
        int u = imp_stack.top();
        imp_stack.pop();
        Node &node = nodes[u];
        if (node.type == 0)
            continue;         // 叶子节点，无子节点
        if (node.type == 1) { // !
            int v = node.left;
            nodes[v].important = node.important;
            imp_stack.push(v);
        } else if (node.type == 2 || node.type == 3) { // & 或 |
            int l = node.left;
            int r = node.right;
            bool val_l = nodes[l].val;
            bool val_r = nodes[r].val;
            if (node.type == 2) { // &
                nodes[l].important = node.important && (val_r == 1);
                nodes[r].important = node.important && (val_l == 1);
            } else { // |
                nodes[l].important = node.important && (val_r == 0);
                nodes[r].important = node.important && (val_l == 0);
            }
            imp_stack.push(l);
            imp_stack.push(r);
        }
    }

    // 处理询问
    int q;
    cin >> q;
    for (int i = 0; i < q; i++) {
        int id;
        cin >> id;
        int idx = pos[id];
        bool ans = root_val;
        if (nodes[idx].important) {
            ans = !ans;
        }
        cout << ans << endl;
    }

    return 0;
}