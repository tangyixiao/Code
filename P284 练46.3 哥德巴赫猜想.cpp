#include <bits/stdc++.h>
using namespace std;

const int N = 1e4 + 5;
bool p[N];
int n;

signed main() {
    cin >> n;
    for (int i = 2; i <= n; i++) {
        p[i] = true;
    }
    for (int i = 2; i * i <= n; i++) {
        if (p[i]) {
            for (int j = i * i; j <= n; j += i) {
                p[j] = false;
            }
        }
    }
    for (int i = 4; i <= n; i += 2) {
        int j = 0;
        for (; j <= i / 2; j++) {
            if (p[j] && p[i - j]) {
                cout << i << "=" << j << "+" << i - j << "\n";
                break;
            }
        }
        if (j > i / 2) {
            cout << "验证失败！\n";
            return 0;
        }
    }
    return 0;
}