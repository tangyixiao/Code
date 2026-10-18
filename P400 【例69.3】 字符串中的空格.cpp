#include <bits/stdc++.h>
using namespace std;

const int N = 105, M = 1e4 + 5;
char s[N], a[M][N];
int n, k;

signed main() {
    cin >> n, cin.getline(s, N);
    for (int i = 1; i <= n; i++) {
        cin.getline(s, N);
        int j = 0;
        for (int q = 0; s[q]; q++) {
            if (s[q] == ' ') {
                k++;
            } else {
                a[i][j++] = s[q];
            }
        }
        a[i][j] = 0;
    }
    cout << k << "\n";
    for (int i = 1; i <= n; i++) {
        cout << a[i] << "\n";
    }
    return 0;
}