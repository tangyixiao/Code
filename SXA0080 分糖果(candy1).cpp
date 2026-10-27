#include <bits/stdc++.h>
using namespace std;

int a[3] = {50, 43, 13};

signed main() {
    for (int t = 0; t < 3; t++) {
        int give = a[t] / 3;
        a[t] = give;
        a[(t + 1) % 3] += give;
        a[(t + 2) % 3] += give;
    }
    cout << a[0] << " " << a[1] << " " << a[2] << "\n";
    return 0;
}
