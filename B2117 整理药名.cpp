#include <bits/stdc++.h>
using namespace std;
inline void recall(char& c) {
    if (c >= 'A' && c <= 'Z') {
        c += 32;
    }
    return;
}
inline void llacer(char& c) {
    if (c >= 'a' && c <= 'z') {
        c -= 32;
    }
    return;
}
inline void turn(string& s) {
    llacer(s[0]);
    int len = s.size();
    for (int i = 1; i < len; i++) {
        recall(s[i]);
    }
    return;
}
int main() {
    int n;
    string s;
    cin >> n;
    for (int i = 0; i < n; i++) {
        cin >> s;
        turn(s);
        cout << s << "\n";
    }
    return 0;
}