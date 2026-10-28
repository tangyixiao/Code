#include <bits/stdc++.h>
using namespace std;

int n;
struct Node {
    int id, s;
} a[105];

bool operator<(const Node &x, const Node &y) {
    if (x.s != y.s) {
        return x.s > y.s;
    }
    return x.id < y.id;
}

signed main() {
    cin >> n;
    for (int i = 1; i <= n; i++) {
        a[i].id = i;
        for (int j = 1; j <= 3; j++) {
            int x;
            cin >> x;
            a[i].s += x;
        }
    }
    sort(a + 1, a + n + 1);
    for (int i = 1; i <= 3; i++) {
        cout << a[i].id << "\n";
    }
    return 0;
}
