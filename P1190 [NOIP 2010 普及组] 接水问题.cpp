#include <bits/stdc++.h>
using namespace std;
const int N = 105;
int n, m, x;
int w[N];
int main() {
    scanf("%d%d", &n, &m);
    for (int i = 1; i <= n; i++) {
        scanf("%d", &x);
        w[0] += x;
        sort(w, w + m);
    }
    cout << w[m - 1];
    return 0;
}