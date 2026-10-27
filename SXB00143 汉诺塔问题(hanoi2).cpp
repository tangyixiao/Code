#include <bits/stdc++.h>
using namespace std;

int n;

void mv(int x, char a, char b, char c) {
    if (x == 0) {
        return;
    }
    mv(x - 1, a, c, b);
    cout << a << " To " << c << "\n";
    mv(x - 1, b, a, c);
}

signed main() {
    cin >> n;
    mv(n, 'A', 'B', 'C');
    return 0;
}
