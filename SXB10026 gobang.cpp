#include <bits/stdc++.h>
using namespace std;

int n;
int tab[21] = {1, 1, 1, 1, 3, 3, 3, 6, 6, 10, 10, 15, 21, 21, 28, 28, 35, 30, 30, 27, 12};

signed main() {
    cin >> n;
    cout << tab[n - 5] << "\n";
    return 0;
}
