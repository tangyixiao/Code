#include <bits/stdc++.h>
using namespace std;
const int N = 1e5 + 5;
int n, i, id[N], js[N], st;
map<int, int> nx;
signed main() {
    cin >> n;
    for (i = 1; i <= n; i++) {
        cin >> id[i] >> js[i];
        nx[id[i]] = js[i];
    }
    sort(js + 1, js + n + 1);
    for (i = 1; i <= n; i++) {
        if (!binary_search(js + 1, js + n + 1, id[i])) {
            st = id[i];
        }
    }
    for (i = 1; i <= n; i++) {
        cout << st << "\n";
        st = nx[st];
    }
    return 0;
}
