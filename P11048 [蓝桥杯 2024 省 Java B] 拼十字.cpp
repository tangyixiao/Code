#include <bits/stdc++.h>
using namespace std;

const int MOD = 1e9 + 7;
const int MAXW = 100000;

struct Rect {
    int l, w, c;
};

bool cmp(const Rect &a, const Rect &b) {
    return a.l < b.l;
}

struct BIT {
    vector<int> tree;
    int n;

    BIT(int size) {
        n = size;
        tree.assign(size + 2, 0);
    }

    void add(int idx, int delta) {
        while (idx <= n) {
            tree[idx] += delta;
            idx += idx & -idx;
        }
    }

    int sum(int idx) {
        int res = 0;
        while (idx > 0) {
            res += tree[idx];
            idx -= idx & -idx;
        }
        return res;
    }
};

int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);

    int N;
    cin >> N;
    vector<Rect> rects(N);
    for (int i = 0; i < N; ++i) {
        cin >> rects[i].l >> rects[i].w >> rects[i].c;
    }

    sort(rects.begin(), rects.end(), cmp);

    vector<BIT> bits;
    for (int col = 0; col < 3; ++col) {
        bits.emplace_back(MAXW);
    }

    long long ans = 0;
    int i = 0;
    while (i < N) {
        int j = i;

        while (j < N && rects[j].l == rects[i].l)
            ++j;

        for (int k = i; k < j; ++k) {
            int w = rects[k].w;
            int c = rects[k].c;
            for (int other = 0; other < 3; ++other) {
                if (other == c)
                    continue;
                int total = bits[other].sum(MAXW);
                int le = bits[other].sum(w);
                int greater = total - le;
                ans += greater;
            }
        }

        for (int k = i; k < j; ++k) {
            bits[rects[k].c].add(rects[k].w, 1);
        }

        i = j;
    }

    cout << ans % MOD << '\n';
    return 0;
}