#include <bits/stdc++.h>
using namespace std;
struct node {
    int id, tot, chinese;
    bool operator<(const node& b) const {
        if (tot != b.tot) {
            return tot < b.tot;
        }
        if (chinese != b.chinese) {
            return chinese < b.chinese;
        }
        return id > b.id;
    }
} a[301];
int n;
signed main() {
    cin >> n;
    for (int i = 1, x, b, c; i <= n; i++) {
        cin >> x >> b >> c;
        a[i].tot = x + b + c;
        a[i].chinese = x;
        a[i].id = i;
    }
    sort(a + 1, a + n + 1);
    for (int i = n; i >= n - 4; i--) {
        cout << a[i].id << " " << a[i].tot << "\n";
    }
    return 0;
}