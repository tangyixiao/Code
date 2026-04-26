#include <iostream>
#include <vector>
using namespace std;

struct Op {
    int v, a, b;
};

int main() {
    int n;
    cin >> n;

    bool adj[55][55] = {false};
    int deg[55] = {0};

    int a, b;
    while (cin >> a >> b) {
        if (a < 1 || a > n || b < 1 || b > n)
            continue;
        if (a == b)
            continue;
        if (!adj[a][b]) {
            adj[a][b] = adj[b][a] = true;
            deg[a]++;
            deg[b]++;
        }
    }

    bool removed[55] = {false};
    int remaining = n;
    vector<Op> ops;

    while (remaining > 2) {
        int v = -1;
        for (int i = 1; i <= n; ++i) {
            if (!removed[i] && deg[i] == 2) {
                v = i;
                break;
            }
        }
        if (v == -1)
            break;

        int nei[2], idx = 0;
        for (int i = 1; i <= n; ++i) {
            if (!removed[i] && adj[v][i]) {
                nei[idx++] = i;
            }
        }
        int a1 = nei[0], b1 = nei[1];
        ops.push_back({v, a1, b1});

        removed[v] = true;
        deg[v] = 0;
        for (int i = 1; i <= n; ++i) {
            if (adj[v][i]) {
                adj[v][i] = adj[i][v] = false;
                if (!removed[i])
                    deg[i]--;
            }
        }

        if (!adj[a1][b1]) {
            adj[a1][b1] = adj[b1][a1] = true;
            deg[a1]++;
            deg[b1]++;
        }
        remaining--;
    }

    vector<int> rest;
    for (int i = 1; i <= n; ++i)
        if (!removed[i])
            rest.push_back(i);

    int nxt[55] = {0}, prv[55] = {0};

    if (rest.size() == 2) {
        int u = rest[0], v = rest[1];
        nxt[u] = v;
        prv[v] = u;
        nxt[v] = u;
        prv[u] = v;
    } else {

        int start = rest[0];
        int cur = start, pre = -1;
        for (int i = 0; i < (int)rest.size(); ++i) {
            int next = -1;
            for (int j : rest) {
                if (j != pre && j != cur && adj[cur][j]) {
                    next = j;
                    break;
                }
            }
            nxt[cur] = next;
            prv[next] = cur;
            pre = cur;
            cur = next;
        }
    }

    for (int i = ops.size() - 1; i >= 0; --i) {
        int v = ops[i].v, a = ops[i].a, b = ops[i].b;

        if (nxt[a] == b) {
            nxt[a] = v;
            prv[v] = a;
            nxt[v] = b;
            prv[b] = v;
        } else if (prv[a] == b) {
            nxt[b] = v;
            prv[v] = b;
            nxt[v] = a;
            prv[a] = v;
        } else if (nxt[b] == a) {
            nxt[b] = v;
            prv[v] = b;
            nxt[v] = a;
            prv[a] = v;
        } else if (prv[b] == a) {
            nxt[a] = v;
            prv[v] = a;
            nxt[v] = b;
            prv[b] = v;
        }
    }

    int start = 1;
    vector<int> seq1, seq2;
    int cur = start;
    do {
        seq1.push_back(cur);
        cur = nxt[cur];
    } while (cur != start);

    cur = start;
    do {
        seq2.push_back(cur);
        cur = prv[cur];
    } while (cur != start);

    vector<int> &ans = (seq1 < seq2) ? seq1 : seq2;
    for (int i = 0; i < (int)ans.size(); ++i) {
        if (i)
            cout << ' ';
        cout << ans[i];
    }
    cout << endl;

    return 0;
}