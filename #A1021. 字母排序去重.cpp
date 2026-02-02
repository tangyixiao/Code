#include <bits/stdc++.h>
using namespace std;
string s;
stack<char> st;
set<char> sett;
signed main() {
    cin >> s;
    for (char c : s) {
        sett.insert(c);
    }
    for (char c : sett) {
        st.push(c);
    }
    string res = "";
    while (!st.empty()) {
        res += st.top();
        st.pop();
    }
    cout << res << endl;
    return 0;
}