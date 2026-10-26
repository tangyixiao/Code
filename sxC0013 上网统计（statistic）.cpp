#include <bits/stdc++.h>
using namespace std;

int n, m;
string u, v;
map<string, int> id;
vector<string> name;
vector<string> page[1005];

signed main() {
    cin >> n >> m;
    for (int i = 1; i <= m; i++) {
        cin >> u >> v;
        if (!id.count(u)) {
            id[u] = name.size();
            name.push_back(u);
        }
        page[id[u]].push_back(v);
    }
    for (int i = 0; i < (int)name.size(); i++) {
        cout << name[i];
        for (int j = 0; j < (int)page[i].size(); j++) {
            cout << " " << page[i][j];
        }
        cout << "\n";
    }
    return 0;
}
