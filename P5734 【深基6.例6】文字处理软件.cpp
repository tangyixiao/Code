#include <bits/stdc++.h>
using namespace std;
int op, a, b, q;
string s, str;
int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);
    cin >> q >> s;
    for (int i = 1; i <= q; i++) {
        cin >> op;
        if (op == 1) {
            cin >> str;
            s += str;
            cout << s << "\n";
        } else if (op == 2) {
            cin >> a >> b;
            s = s.substr(a, b);
            cout << s << "\n";
        } else if (op == 3) {
            cin >> a >> str;
            s.insert(a, str);
            cout << s << "\n";
        } else {
            cin >> str;
            int tmp = s.find(str);
            if (tmp == string::npos) {
                cout << -1 << "\n";
            } else {
                cout << tmp << "\n";
            }
        }
    }
    return 0;
}