#include <bits/stdc++.h>
using namespace std;

struct Road {
    int x, y, t;
};

vector<Road> roads;
int N, M;

class UnionFind {
private:
    vector<int> parent, rank;

public:
    UnionFind(int n) {
        parent.resize(n + 1);
        rank.resize(n + 1, 0);
        for (int i = 1; i <= n; i++) {
            parent[i] = i;
        }
    }

    int find(int x) {
        if (parent[x] != x) {
            parent[x] = find(parent[x]);
        }
        return parent[x];
    }

    void unite(int x, int y) {
        int rootX = find(x);
        int rootY = find(y);
        if (rootX == rootY)
            return;
        if (rank[rootX] < rank[rootY]) {
            parent[rootX] = rootY;
        } else if (rank[rootX] > rank[rootY]) {
            parent[rootY] = rootX;
        } else {
            parent[rootY] = rootX;
            rank[rootX]++;
        }
    }

    bool isConnected() {
        int root = find(1);
        for (int i = 2; i <= N; i++) {
            if (find(i) != root) {
                return false;
            }
        }
        return true;
    }
};

bool check(int T) {
    UnionFind uf(N);
    for (const auto& road : roads) {
        if (road.t <= T) {
            uf.unite(road.x, road.y);
        }
    }
    return uf.isConnected();
}

int main() {
    cin >> N >> M;
    roads.resize(M);
    int max_t = 0;
    for (int i = 0; i < M; i++) {
        cin >> roads[i].x >> roads[i].y >> roads[i].t;
        max_t = max(max_t, roads[i].t);
    }

    int left = 0, right = max_t + 1;
    while (left < right) {
        int mid = left + (right - left) / 2;
        if (check(mid)) {
            right = mid;
        } else {
            left = mid + 1;
        }
    }

    if (left == max_t + 1) {
        cout << -1 << endl;
    } else {
        cout << left << endl;
    }

    return 0;
}