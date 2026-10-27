#include <bits/stdc++.h>
using namespace std;

int n;

signed main() {
    cin >> n;
    if (n >= 15) {
        cout << "qingnianzu" << "\n";
    } else {
        if (n >= 11) {
            cout << "shaonianzu" << "\n";
        } else {
            cout << "ertongzu" << "\n";
        }
    }
    return 0;
}
