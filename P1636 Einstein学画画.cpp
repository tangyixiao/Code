#include <iostream>
#include <vector>
using namespace std;

const int MAXN = 1005;

int parent[MAXN];
int degree[MAXN];


void init(int n) {
    for (int i = 1; i <= n; i++) {
        parent[i] = i;
        degree[i] = 0;
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
    if (rootX != rootY) {
        parent[rootY] = rootX;
    }
}

int main() {
    int n, m;
    cin >> n >> m;

    init(n);

    
    for (int i = 0; i < m; i++) {
        int a, b;
        cin >> a >> b;
        degree[a]++;
        degree[b]++;
        unite(a, b);
    }

    
    vector<int> oddCount(n + 1, 0);     
    vector<bool> hasEdge(n + 1, false); 

    for (int i = 1; i <= n; i++) {
        int root = find(i);
        if (degree[i] % 2 == 1) {
            oddCount[root]++;
        }
        if (degree[i] > 0) {
            hasEdge[root] = true; 
        }
    }

    
    int result = 0;
    for (int i = 1; i <= n; i++) {
        if (parent[i] == i && hasEdge[i]) { 
            if (oddCount[i] == 0) {
                result += 1; 
            } else {
                result += oddCount[i] / 2; 
            }
        }
    }

    cout << result << endl;

    return 0;
}