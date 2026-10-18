#include <bits/stdc++.h>
using namespace std;

const int N = 7010 + 5;
int A, B, n;
bool s[N];
long long f[N];

signed main() {
    cin >> A >> B >> n;
    memset(s, 0, sizeof s);
    int a[] = {0, 990, 1010, 1970, 2030, 2940, 3060, 3930,
               4060, 4970, 5030, 5990, 6010, 7000};
    for (int i = 0; i < 14; i++) {
        s[a[i]] = true;
    }
    for (int i = 0; i < n; i++) {
        int m;
        cin >> m, s[m] = true;
    }
    f[0] = 1;
    for (int i = 1; i <= 7000; i++) {
        if (!s[i]) {
            continue;
        }
        for (int j = i - B; j <= i - A; j++) {
            if (j >= 0) {
                f[i] += f[j];
            }
        }
    }
    cout << f[7000] << "\n";
    return 0;
}