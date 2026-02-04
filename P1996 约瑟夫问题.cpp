#include <bits/stdc++.h>
// #define DEBUG
using namespace std;
const int N = 1e2 + 5;
int n, m, cnt, a[N], id;
signed main() {
    cin >> n >> m;
    for (int i = 1; i <= n; i++) {
        a[i] = i;
    }
    a[0] = n;
    id = 1;
    for (; cnt < n; cnt++) {
#ifdef DEBUG
        cerr << "cnt:" << cnt << " ";
        cerr << "id:" << id << "\n";
        cerr << "a: ";
        for (int i = 0; i < n; i++) {
            cerr << a[i] << " ";
        }
        cerr << "\n";
#endif
        for (int j = 1;;) {
            if (j >= m && a[id] != -1) {
                break;
            }
            if (a[id] != -1) {
                j++;
            }
            id = (id + 1) % n;
        }
        cout << a[id] << " ";
        a[id] = -1;
        id = (id + 1) % n;
    }
    return 0;
}