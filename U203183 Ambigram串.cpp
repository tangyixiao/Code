#include <bits/stdc++.h>
using namespace std;

string s;
int n;
int del[256];
vector<char> self = {'H', 'I', 'N', 'O', 'S', 'X', 'Z'};
vector<pair<char, char>> pairs;

struct Node {
    int cost;
    int len;
    string s;
    Node(int c = 0, int l = 0, string str = "") : cost(c), len(l), s(str) {}
};

struct State {
    Node all;
    Node nonempty;
};

State dp[55][55];
bool vis[55][55];

Node better(const Node &a, const Node &b) {
    if (a.cost < b.cost)
        return a;
    if (a.cost > b.cost)
        return b;
    if (a.len > b.len)
        return a;
    if (a.len < b.len)
        return b;
    if (a.s < b.s)
        return a;
    return b;
}

State solve(int l, int r) {
    if (l > r) {
        Node empty(0, 0, "");
        return {empty, Node(INT_MAX, 0, "")};
    }
    if (vis[l][r])
        return dp[l][r];

    vector<Node> candidates;

    if (l == r) {

        candidates.emplace_back(del[s[l]], 0, "");

        int min_c = INT_MAX;
        string best_s;
        for (char x : self) {
            int c = abs(s[l] - x);
            if (c < min_c || (c == min_c && (best_s.empty() || x < best_s[0]))) {
                min_c = c;
                best_s = string(1, x);
            }
        }
        candidates.emplace_back(min_c, 1, best_s);
    } else {

        State left = solve(l + 1, r);
        if (left.all.cost != INT_MAX) {
            candidates.emplace_back(left.all.cost + del[s[l]], left.all.len, left.all.s);
        }
        if (left.nonempty.cost != INT_MAX) {
            candidates.emplace_back(left.nonempty.cost + del[s[l]], left.nonempty.len, left.nonempty.s);
        }

        State right = solve(l, r - 1);
        if (right.all.cost != INT_MAX) {
            candidates.emplace_back(right.all.cost + del[s[r]], right.all.len, right.all.s);
        }
        if (right.nonempty.cost != INT_MAX) {
            candidates.emplace_back(right.nonempty.cost + del[s[r]], right.nonempty.len, right.nonempty.s);
        }

        State mid = solve(l + 1, r - 1);
        int best_pair_cost = INT_MAX;
        vector<Node> pair_cands;
        for (auto [x, y] : pairs) {
            int c = abs(s[l] - x) + abs(s[r] - y);

            if (mid.nonempty.cost != INT_MAX) {
                int tot_cost = c + mid.nonempty.cost;
                string tot_str = string(1, x) + mid.nonempty.s + string(1, y);
                pair_cands.emplace_back(tot_cost, mid.nonempty.len + 2, tot_str);
            }

            if (mid.all.cost != INT_MAX && mid.all.len == 0) {
                int tot_cost = c + mid.all.cost;
                string tot_str = string(1, x) + string(1, y);
                pair_cands.emplace_back(tot_cost, 2, tot_str);
            }
        }
        if (!pair_cands.empty()) {
            Node best_all = pair_cands[0];
            Node best_nonempty = pair_cands[0];
            for (size_t i = 1; i < pair_cands.size(); ++i) {
                best_all = better(best_all, pair_cands[i]);
                best_nonempty = better(best_nonempty, pair_cands[i]);
            }
            candidates.push_back(best_all);
            candidates.push_back(best_nonempty);
        }
    }

    Node best_all = candidates[0];
    Node best_nonempty = (candidates[0].len > 0 ? candidates[0] : Node(INT_MAX, 0, ""));
    for (size_t i = 1; i < candidates.size(); ++i) {
        best_all = better(best_all, candidates[i]);
        if (candidates[i].len > 0) {
            if (best_nonempty.cost == INT_MAX)
                best_nonempty = candidates[i];
            else
                best_nonempty = better(best_nonempty, candidates[i]);
        }
    }

    vis[l][r] = true;
    dp[l][r] = {best_all, best_nonempty};
    return dp[l][r];
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);

    cin >> s;
    n = (int)s.length();

    for (char c = 'A'; c <= 'Z'; ++c) {
        int d1 = c - 'A';
        int d2 = 'Z' - c;
        del[c] = min(d1, d2) + 1;
    }

    pairs.clear();
    for (char x : self)
        pairs.emplace_back(x, x);
    pairs.emplace_back('M', 'W');
    pairs.emplace_back('W', 'M');

    memset(vis, 0, sizeof(vis));
    State ans = solve(0, n - 1);
    cout << ans.nonempty.s << '\n';

    return 0;
}