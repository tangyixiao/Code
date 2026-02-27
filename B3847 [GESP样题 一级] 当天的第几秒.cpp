#include <bits/stdc++.h>
using namespace std;
const int base = 60, half = 60 * 60 * 12;
int h, m, s;
char c;
signed main() {
    cin >> h >> m >> s >> c;
    int t = h * base * base + m * base + s;
    if (c == 'P') {
        t += half;
    }
    cout << t;
    return 0;
}