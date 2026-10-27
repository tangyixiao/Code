#include <bits/stdc++.h>
using namespace std;
const int N = 2e5 + 5;
int n, i, p;
long long k, pos, crew;
long long a[N], b[N];
struct node {
    long long a, b;
} e[N];
bool cmp(node x, node y) { return x.a < y.a; }
signed main() {
    cin >> n >> k;
    for (i = 1; i <= n; i++) {
        cin >> e[i].a >> e[i].b;
    }
    sort(e + 1, e + n + 1, cmp);
    pos = 0, crew = k;
    for (i = 1; i <= n; i = p) {
        for (p = i; p <= n && e[p].a == e[i].a; p++) {
        }
        long long nb = 0;
        for (int j = i; j < p; j++) {
            nb += e[j].b;
        }
        long long d = e[i].a - pos;
        if (crew < d) {
            cout << pos + crew << "\n";
            return 0;
        }
        crew -= d, pos = e[i].a;
        crew += nb;
    }
    cout << pos + crew << "\n";
    return 0;
}
