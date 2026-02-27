#include <bits/stdc++.h>
using namespace std;
const int MAXN = 1145141;
struct node {
    int x, y;
} m[MAXN];
bool cmp(node q, node w) { return q.y < w.y; }
int main() {
    int n, s, a, b;
    int apples = 0;
    scanf("%d%d%d%d", &n, &s, &a, &b);
    for (int i = 1; i <= n; i++) {
        cin >> m[i].x;
        cin >> m[i].y;
    }
    sort(m + 1, m + 1 + n, cmp);
    for (int i = 1; i <= n && s >= 0; i++) {
        if (m[i].x <= a + b && s - m[i].y >= 0) {
            s -= m[i].y;
            apples++;
        }
    }
    printf("%d", apples);
    return 0;
}