#include <bits/stdc++.h>

using namespace std;

struct Node {
    long long weight;
    Node *left, *right;
    int index;
    int id;

    Node(long long w, int idx, int iid)
        : weight(w), left(nullptr), right(nullptr), index(idx), id(iid) {}
    Node(long long w, Node *l, Node *r, int iid)
        : weight(w), left(l), right(r), index(-1), id(iid) {}
};

struct Compare {
    bool operator()(const Node *a, const Node *b) const {
        if (a->weight != b->weight)
            return a->weight > b->weight;
        return a->id > b->id;
    }
};

void dfs(Node *root, string code, vector<string> &codes) {
    if (!root)
        return;
    if (root->index != -1) {
        codes[root->index] = code;
        return;
    }
    if (root->left)
        dfs(root->left, code + "0", codes);
    if (root->right)
        dfs(root->right, code + "1", codes);
}

void deleteTree(Node *root) {
    if (!root)
        return;
    deleteTree(root->left);
    deleteTree(root->right);
    delete root;
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int n;
    cin >> n;
    vector<string> words(n);
    vector<long long> weights(n);
    for (int i = 0; i < n; ++i) {
        cin >> words[i] >> weights[i];
    }

    if (n == 1) {
        cout << words[0] << " 0\n";
        return 0;
    }

    priority_queue<Node *, vector<Node *>, Compare> pq;
    int id_counter = 0;
    for (int i = 0; i < n; ++i) {
        Node *node = new Node(weights[i], i, ++id_counter);
        pq.push(node);
    }

    while (pq.size() > 1) {
        Node *left = pq.top();
        pq.pop();
        Node *right = pq.top();
        pq.pop();
        Node *parent = new Node(left->weight + right->weight,
                                left, right, ++id_counter);
        pq.push(parent);
    }

    Node *root = pq.top();

    vector<string> codes(n);
    dfs(root, "", codes);

    for (int i = 0; i < n; ++i) {
        cout << words[i] << " " << codes[i] << "\n";
    }

    deleteTree(root);

    return 0;
}