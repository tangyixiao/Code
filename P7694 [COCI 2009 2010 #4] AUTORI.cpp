#include <bits/stdc++.h>
using namespace std;
string s;
bool isbigletter(char c) {
    return (c >= 'A' && c <= 'Z');
}
int main() {
    cin >> s;
    for (int i = 0; i < s.length(); i++) {
        if (isbigletter(s[i])) {
            cout << s[i];
        }
    }
    return 0;
}