#include <bits/stdc++.h>
using namespace std;
const int N = 13;
signed main() {
    int n;
    cin >> n;
    if (n > 13 || !(n % 3) || n == 8 || n == 11) {
        cout << "TAK";
    } else {
        cout << "NIE";
    }
    return 0;
}