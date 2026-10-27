#include <bits/stdc++.h>
using namespace std;

const int N = 2e1 + 5;
int n;

struct node {
    string name;
    int score;
} a[N];

bool cmp(node x, node y) {
    if (x.score != y.score) {
        return x.score > y.score;
    }
    return x.name < y.name;
}

signed main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cin >> n;
    for (int i = 1; i <= n; i++) {
        cin >> a[i].name >> a[i].score;
    }
    sort(a + 1, a + n + 1, cmp);
    for (int i = 1; i <= n; i++) {
        cout << a[i].name << " " << a[i].score << "\n";
    }
    return 0;
}
