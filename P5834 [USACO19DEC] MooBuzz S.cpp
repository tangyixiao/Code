#include <bits/stdc++.h>
using namespace std;
const int N = 1e1;
int a[N] = {1, 2, 4, 7, 8, 11, 13, 14};
int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);
    long long n;
    cin >> n;
    cout << (n - 1) / 8 * 15 + a[(n - 1) % 8] << '\n';
}
