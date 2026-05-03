#include <bits/stdc++.h>
using namespace std;

using ll = long long;

struct BIT {
    int n;
    vector<int> t;
    BIT(int n) : n(n), t(n + 1) {}
    void add(int i, int v) {
        for (; i <= n; i += i & -i)
            t[i] += v;
    }
    int sum(int i) {
        int res = 0;
        for (; i > 0; i -= i & -i)
            res += t[i];
        return res;
    }
};

// KMP 前缀函数
vector<int> prefix_function(const string &s) {
    int n = s.size();
    vector<int> pi(n);
    for (int i = 1; i < n; ++i) {
        int j = pi[i - 1];
        while (j > 0 && s[i] != s[j])
            j = pi[j - 1];
        if (s[i] == s[j])
            ++j;
        pi[i] = j;
    }
    return pi;
}

void dfs(int u, const vector<vector<int>> &g, vector<int> &in, vector<int> &out,
         vector<int> &sz, int &timer) {
    in[u] = ++timer;
    for (int v : g[u]) {
        dfs(v, g, in, out, sz, timer);
        sz[u] += sz[v];
    }
    out[u] = timer;
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    string s, t;
    cin >> s >> t;
    int n = s.size(), m = t.size();

    // ------------------ 模式 A ------------------
    ll ansA = 0;
    vector<int> pi_t = prefix_function(t);
    int len = 0;
    for (int i = 0; i < n; ++i) {
        while (len > 0 && s[i] != t[len])
            len = pi_t[len - 1];
        if (s[i] == t[len])
            ++len;
        if (len == m) {
            int R = i + 1;     // 1‑based 结束位置
            int L = R - m + 1; // 开始位置
            ansA += (ll)(L - 1) * L / 2;
            ansA += (ll)(n - R) * (n - R + 1) / 2;
            len = pi_t[len - 1];
        }
    }

    // ----------------- L1 数组 ------------------
    vector<int> L1(n + 1); // 1‑based
    len = 0;
    for (int i = 0; i < n; ++i) {
        while (len > 0 && s[i] != t[len])
            len = pi_t[len - 1];
        if (s[i] == t[len])
            ++len;
        L1[i + 1] = len;
    }

    // fail1 树
    vector<int> fail1(m + 1); // fail1[len] 为长度为 len 的前缀的 border 长度
    for (int i = 1; i <= m; ++i) {
        if (i == 1)
            fail1[i] = 0;
        else
            fail1[i] = pi_t[i - 2]; // pi_t[i-2] 对应长度 i 的 border
    }
    vector<vector<int>> tree1(m + 1);
    for (int i = 1; i <= m; ++i)
        tree1[fail1[i]].push_back(i);
    vector<int> red(m + 1, 0);
    for (int i = 1; i <= n; ++i)
        if (L1[i] > 0)
            red[L1[i]]++;
    vector<int> in1(m + 1), out1(m + 1), size1(m + 1, 0);
    {
        int timer = 0;
        for (int i = 0; i <= m; ++i)
            size1[i] = red[i];
        dfs(0, tree1, in1, out1, size1, timer);
    }

    // ----------------- L2 数组（反转） ------------------
    string rev_s = s, rev_t = t;
    reverse(rev_s.begin(), rev_s.end());
    reverse(rev_t.begin(), rev_t.end());
    vector<int> pi_rev = prefix_function(rev_t);
    vector<int> L2_rev(n + 1);
    len = 0;
    for (int i = 0; i < n; ++i) {
        while (len > 0 && rev_s[i] != rev_t[len])
            len = pi_rev[len - 1];
        if (rev_s[i] == rev_t[len])
            ++len;
        L2_rev[i + 1] = len;
    }
    vector<int> L2(n + 1);
    for (int j = 1; j <= n; ++j)
        L2[j] = L2_rev[n - j + 1];

    // fail2 树
    vector<int> fail2(m + 1);
    for (int i = 1; i <= m; ++i) {
        if (i == 1)
            fail2[i] = 0;
        else
            fail2[i] = pi_rev[i - 2];
    }
    vector<vector<int>> tree2(m + 1);
    for (int i = 1; i <= m; ++i)
        tree2[fail2[i]].push_back(i);
    vector<int> blue(m + 1, 0);
    for (int j = 1; j <= n; ++j)
        if (L2[j] > 0)
            blue[L2[j]]++;
    vector<int> in2(m + 1), out2(m + 1), size2(m + 1, 0);
    {
        int timer = 0;
        for (int i = 0; i <= m; ++i)
            size2[i] = blue[i];
        dfs(0, tree2, in2, out2, size2, timer);
    }

    // ----------------- 模式 B ------------------
    ll base = 0;
    for (int k = 1; k <= m - 1; ++k) {
        base += (ll)size1[k] * size2[m - k];
    }

    // 非法对  (j = i 或 j = i+1)
    struct Point {
        int x, y;
    };
    vector<Point> illegal_pts;
    for (int i = 1; i <= n; ++i) {
        if (L1[i] > 0 && L2[i] > 0)
            illegal_pts.push_back({in1[L1[i]], in2[L2[i]]});
        if (i + 1 <= n && L1[i] > 0 && L2[i + 1] > 0)
            illegal_pts.push_back({in1[L1[i]], in2[L2[i + 1]]});
    }

    // 离线二维数点
    struct Query {
        int X, Y, sign, id;
    };
    vector<Query> queries;
    for (int k = 1; k <= m - 1; ++k) {
        int x1 = in1[k], x2 = out1[k];
        int y1 = in2[m - k], y2 = out2[m - k];
        auto addQ = [&](int X, int Y, int sign) {
            if (X >= 1 && Y >= 1)
                queries.push_back({X, Y, sign, k});
        };
        addQ(x2, y2, 1);
        addQ(x1 - 1, y2, -1);
        addQ(x2, y1 - 1, -1);
        addQ(x1 - 1, y1 - 1, 1);
    }

    sort(illegal_pts.begin(), illegal_pts.end(),
         [](const Point &a, const Point &b) { return a.x < b.x; });
    sort(queries.begin(), queries.end(),
         [](const Query &a, const Query &b) { return a.X < b.X; });

    BIT bit(m);
    vector<ll> illegal_cnt(m + 1, 0); // 下标 k
    size_t pt = 0;
    for (const auto &q : queries) {
        while (pt < illegal_pts.size() && illegal_pts[pt].x <= q.X) {
            bit.add(illegal_pts[pt].y, 1);
            ++pt;
        }
        int s = bit.sum(q.Y);
        illegal_cnt[q.id] += q.sign * s;
    }

    ll ansB = base;
    for (int k = 1; k <= m - 1; ++k)
        ansB -= illegal_cnt[k];

    ll ans = ansA + ansB;
    cout << ans << '\n';

    return 0;
}