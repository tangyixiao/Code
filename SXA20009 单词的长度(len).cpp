#include <bits/stdc++.h>
using namespace std;

string s, w;
int first = 1;

signed main() {
    getline(cin, s);
    stringstream ss(s);
    while (ss >> w) {
        if (!first) {
            cout << ",";
        }
        first = 0;
        cout << w.size();
    }
    cout << "\n";
    return 0;
}
