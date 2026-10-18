#include <bits/stdc++.h>
using namespace std;

const int N = 13;
int w, dd[N] = {0, 31, 28, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31};

signed main() {
    cin >> w;
    for (int m = 1; m <= 12; m++) {
        int d = (w + 12) % 7;
        if (d == 5) {
            cout << m << "\n";
        }
        w = (w + dd[m]) % 7;
    }
    return 0;
}
