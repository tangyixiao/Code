#include <algorithm>
#include <cstdio>
#include <cstring>
#include <vector>

const int MAXN = 200005;
const int INF = 1000000007;

struct Edge {
    int to, next;
} edges[MAXN << 1];
int head[MAXN], edge_cnt = 0;

void add_edge(int u, int v) {
    edges[++edge_cnt] = {v, head[u]};
    head[u] = edge_cnt;
}

int node_cnt;
int max_length[MAXN];
int subtree_size[MAXN];
int parent[MAXN];
int depth[MAXN];
bool removed[MAXN];
int limit[MAXN];
int current_size[MAXN];

int seg_max[MAXN << 2];

void seg_push_up(int p) {
    seg_max[p] = std::max(seg_max[p << 1], seg_max[p << 1 | 1]);
}

void seg_update_point(int p, int l, int r, int pos, int val) {
    seg_max[p] = std::max(seg_max[p], val);
    if (l == r)
        return;
    int mid = (l + r) >> 1;
    if (pos <= mid)
        seg_update_point(p << 1, l, mid, pos, val);
    else
        seg_update_point(p << 1 | 1, mid + 1, r, pos, val);
    seg_push_up(p);
}

int seg_query_range(int p, int l, int r, int ql, int qr) {
    if (ql <= l && r <= qr)
        return seg_max[p];
    int mid = (l + r) >> 1;
    if (qr <= mid)
        return seg_query_range(p << 1, l, mid, ql, qr);
    if (ql > mid)
        return seg_query_range(p << 1 | 1, mid + 1, r, ql, qr);
    return std::max(seg_query_range(p << 1, l, mid, ql, mid),
                    seg_query_range(p << 1 | 1, mid + 1, r, mid + 1, qr));
}

void seg_clear(int p, int l, int r) {
    if (seg_max[p] == 0)
        return;
    seg_max[p] = 0;
    if (l == r)
        return;
    int mid = (l + r) >> 1;
    seg_clear(p << 1, l, mid);
    seg_clear(p << 1 | 1, mid + 1, r);
}

void dfs_subtree_size(int u, int p) {
    subtree_size[u] = 1;
    for (int i = head[u]; i; i = edges[i].next) {
        int v = edges[i].to;
        if (v == p)
            continue;
        parent[v] = u;
        dfs_subtree_size(v, u);
        subtree_size[u] += subtree_size[v];
    }
}

int root, min_max_part;

void find_centroid(int u, int p, int total) {
    current_size[u] = 1;
    int max_part = -1;
    for (int i = head[u]; i; i = edges[i].next) {
        int v = edges[i].to;
        if (removed[v] || v == p)
            continue;
        find_centroid(v, u, total);
        current_size[u] += current_size[v];
        max_part = std::max(max_part, current_size[v]);
    }
    max_part = std::max(max_part, total - current_size[u]);
    if (max_part < min_max_part) {
        min_max_part = max_part;
        root = u;
    }
}

void get_centroid(int u, int total) {
    min_max_part = INF;
    find_centroid(u, 0, total);
}

void insert_subtree(int u, int p) {
    seg_update_point(1, 1, node_cnt, limit[u], depth[u]);
    for (int i = head[u]; i; i = edges[i].next) {
        int v = edges[i].to;
        if (v == p || removed[v])
            continue;
        insert_subtree(v, u);
    }
}

void query_and_update(int u, int p) {
    int best = seg_query_range(1, 1, node_cnt, limit[u], node_cnt);
    if (best)
        max_length[limit[u]] = std::max(max_length[limit[u]], depth[u] + best + 1);
    for (int i = head[u]; i; i = edges[i].next) {
        int v = edges[i].to;
        if (v == p || removed[v])
            continue;
        depth[v] = depth[u] + 1;
        query_and_update(v, u);
    }
}

void direct_update(int u, int p, int t) {
    int idx = std::min(limit[u], t);
    max_length[idx] = std::max(max_length[idx], depth[u] + 1);
    for (int i = head[u]; i; i = edges[i].next) {
        int v = edges[i].to;
        if (v == p || removed[v])
            continue;
        direct_update(v, u, t);
    }
}

void process_centroid(int u) {

    int x = parent[u], pre = u;
    while (x && !removed[x]) {
        limit[x] = node_cnt - subtree_size[pre];
        pre = x;
        x = parent[x];
    }

    std::vector<int> children;
    for (int i = head[u]; i; i = edges[i].next) {
        int v = edges[i].to;
        if (removed[v])
            continue;
        children.push_back(v);
        depth[v] = 1;
        query_and_update(v, 0);
        insert_subtree(v, 0);
    }
    seg_clear(1, 1, node_cnt);

    std::reverse(children.begin(), children.end());
    for (int v : children) {
        depth[v] = 1;
        query_and_update(v, 0);
        insert_subtree(v, 0);
    }
    seg_clear(1, 1, node_cnt);

    for (int i = head[u]; i; i = edges[i].next) {
        int v = edges[i].to;
        if (removed[v])
            continue;
        int t = (v == parent[u]) ? subtree_size[u] : node_cnt - subtree_size[v];
        direct_update(v, 0, t);
    }
    seg_clear(1, 1, node_cnt);

    x = parent[u];
    while (x && !removed[x]) {
        limit[x] = subtree_size[x];
        x = parent[x];
    }
}

void decompose(int u, int total_size) {
    removed[u] = true;
    process_centroid(u);

    for (int i = head[u]; i; i = edges[i].next) {
        int v = edges[i].to;
        if (removed[v])
            continue;
        int sz = (current_size[u] > current_size[v]) ? current_size[v] : total_size - current_size[u];
        get_centroid(v, sz);
        decompose(root, sz);
    }
}

int main() {
    scanf("%d", &node_cnt);
    for (int i = 1; i < node_cnt; ++i) {
        int u, v;
        scanf("%d%d", &u, &v);
        add_edge(u, v);
        add_edge(v, u);
    }

    dfs_subtree_size(1, 0);
    std::copy(subtree_size, subtree_size + node_cnt + 1, limit);

    get_centroid(1, node_cnt);
    int start_root = root, start_size = node_cnt;
    decompose(start_root, start_size);

    max_length[node_cnt + 1] = 1;
    for (int i = node_cnt; i >= 1; --i)
        max_length[i] = std::max(max_length[i], max_length[i + 1]);

    for (int i = 1; i <= node_cnt; ++i) {
        if (i & 1)
            puts("1");
        else
            printf("%d\n", max_length[i >> 1]);
    }
    return 0;
}