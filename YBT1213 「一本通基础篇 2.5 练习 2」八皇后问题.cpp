#include <bits/stdc++.h>
using namespace std;

int a[10], cnt;

void dfs(int c, int s1, int s2, int s3) {
    if (c == 9) {
        cnt++;
        cout << "No. " << cnt << "\n";
        for (int i = 1; i <= 8; i++) {
            for (int j = 1; j <= 8; j++) {
                cout << (a[j] == i ? 1 : 0);
                if (j < 8) {
                    cout << " ";
                }
            }
            cout << "\n";
        }
        return;
    }
    for (int r = 1; r <= 8; r++) {
        int b1 = 1 << r, b2 = 1 << (r + c), b3 = 1 << (r - c + 8);
        if ((s1 & b1) || (s2 & b2) || (s3 & b3)) {
            continue;
        }
        a[c] = r;
        dfs(c + 1, s1 | b1, s2 | b2, s3 | b3);
    }
}

signed main() {
    dfs(1, 0, 0, 0);
    return 0;
}
