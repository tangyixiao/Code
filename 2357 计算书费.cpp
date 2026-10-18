#include <bits/stdc++.h>
using namespace std;

const int N = 1e1 + 5;

double p[] = {0, 28.9, 32.7, 45.6, 78, 35, 86.2, 27.8, 43, 56, 65};

signed main() {
    double s = 0;
    for (int i = 1; i <= 10; i++) {
        int n;
        cin >> n;
        s += p[i] * n;
    }
    printf("%.1f\n", s);
    return 0;
}