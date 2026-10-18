#include <bits/stdc++.h>
using namespace std;

const int N = 1e3 + 5;
int n;

signed main() {
    cin >> n;
    for (int i = 6; i <= n; i++) {
        int s = 0;
        for (int j = 1; j < i; j++) {
            if (i % j == 0) {
                s += j;
            }
        }
        if (s != i) {
            continue;
        }
        cout << i << " its factors are";
        for (int j = 1; j < i; j++) {
            if (i % j == 0) {
                cout << " " << j;
            }
        }
        cout << "\n";
    }
    return 0;
}