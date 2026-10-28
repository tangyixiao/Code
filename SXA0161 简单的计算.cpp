#include <bits/stdc++.h>
using namespace std;

double l, r, v;

signed main() {
    cin >> l >> r >> v;
    printf("Q:%.10g\n", l * r);
    printf("C:%.10g\n", (l + r) * v);
    return 0;
}
