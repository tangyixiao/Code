#include <algorithm>
#include <cstring>
#include <iostream>
#include <stack>
#include <vector>

using namespace std;

const int MAXN = 205;

vector<int> adj[MAXN];
int dfn[MAXN], low[MAXN], scc_id[MAXN], in_deg[MAXN];
bool in_stack[MAXN];
stack<int> st;
int idx = 0, scc_cnt = 0;

void tarjan(int u) {
    dfn[u] = low[u] = ++idx;
    st.push(u);
    in_stack[u] = true;
    for (int v : adj[u]) {
        if (!dfn[v]) {
            tarjan(v);
            low[u] = min(low[u], low[v]);
        } else if (in_stack[v]) {
            low[u] = min(low[u], dfn[v]);
        }
    }
    if (dfn[u] == low[u]) {
        scc_cnt++;
        int v;
        do {
            v = st.top();
            st.pop();
            in_stack[v] = false;
            scc_id[v] = scc_cnt;
        } while (v != u);
    }
}

int main() {
    int n;
    cin >> n;
    for (int i = 1; i <= n; i++) {
        int x;
        while (cin >> x && x != 0) {
            adj[i].push_back(x);
        }
    }

    memset(dfn, 0, sizeof(dfn));
    memset(in_stack, false, sizeof(in_stack));
    for (int i = 1; i <= n; i++) {
        if (!dfn[i])
            tarjan(i);
    }

    memset(in_deg, 0, sizeof(in_deg));
    for (int u = 1; u <= n; u++) {
        for (int v : adj[u]) {
            if (scc_id[u] != scc_id[v]) {
                in_deg[scc_id[v]]++;
            }
        }
    }

    int ans = 0;
    for (int i = 1; i <= scc_cnt; i++) {
        if (in_deg[i] == 0)
            ans++;
    }

    cout << ans << endl;
    return 0;
}