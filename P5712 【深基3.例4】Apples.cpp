#include <bits/stdc++.h>
using namespace std;
int x;
signed main() {
    cin >> x;
    cout << "Today, I ate " << x << " apple";
    if (x > 1) {
        cout << "s";
    }
    cout << ".";
    return 0;
}