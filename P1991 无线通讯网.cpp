#include <bits/stdc++.h>
using namespace std;

struct Edge {
    int u, v;
    double w;
    bool operator<(const Edge &other) const {
        return w < other.w;
    }
};

vector<int> parent;

int find(int x) {
    if (parent[x] != x)
        parent[x] = find(parent[x]);
    return parent[x];
}

bool unite(int x, int y) {
    int rx = find(x), ry = find(y);
    if (rx == ry)
        return false;
    parent[ry] = rx;
    return true;
}

int main() {
    int S, P;
    cin >> S >> P;
    vector<pair<int, int>> points(P);
    for (int i = 0; i < P; ++i) {
        cin >> points[i].first >> points[i].second;
    }

    vector<Edge> edges;
    for (int i = 0; i < P; ++i) {
        for (int j = i + 1; j < P; ++j) {
            double dx = points[i].first - points[j].first;
            double dy = points[i].second - points[j].second;
            double dist = sqrt(dx * dx + dy * dy);
            edges.push_back({i, j, dist});
        }
    }

    sort(edges.begin(), edges.end());

    parent.resize(P);
    for (int i = 0; i < P; ++i)
        parent[i] = i;

    vector<double> mst_edges;
    for (const auto &e : edges) {
        if (unite(e.u, e.v)) {
            mst_edges.push_back(e.w);
            if (mst_edges.size() == P - 1)
                break;
        }
    }

    double ans = mst_edges[P - S - 1];
    cout << fixed << setprecision(2) << ans << endl;

    return 0;
}