#include <bits/stdc++.h>
using namespace std;
const int N = 1e2 + 5;
int n, i;
string s;
string w[N];
signed main() {
    string line;
    getline(cin, line);
    stringstream ss(line);
    while (ss >> s) {
        w[n++] = s;
    }
    sort(w, w + n);
    for (i = 0; i < n; i++) {
        if (i == 0 || w[i] != w[i - 1]) {
            cout << w[i] << "\n";
        }
    }
    return 0;
}
