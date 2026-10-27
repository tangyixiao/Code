#include <bits/stdc++.h>
using namespace std;

string a;

signed main() {
    ios::sync_with_stdio(false);
    cin.tie(0);
    cin >> a;
    for (int i = 0; i < (int)a.size(); i++) {
        char c = a[i];
        if (c >= 'A' && c <= 'Z') {
            c = c - 'A' + 'a';
        }
        if (c == 'a' || c == 'e' || c == 'i' || c == 'o' || c == 'u' || c == 'y') {
            continue;
        }
        cout << "." << c;
    }
    cout << "\n";
    return 0;
}
