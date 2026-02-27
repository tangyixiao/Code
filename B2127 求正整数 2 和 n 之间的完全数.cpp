#include <bits/stdc++.h>
// 6 28 496 8128
using namespace std;
int main() {
    int n, i = 6, j = 28, l = 496, k = 8128;
    cin >> n;
    if (n < j)
        cout << i;
    if (n >= j && n < l)
        cout << i << endl << j;
    if (n >= l && n < k)
        cout << i << endl << j << endl << l;
    if (n >= k)
        cout << i << endl << j << endl << l << endl << k;
    return 0;
}