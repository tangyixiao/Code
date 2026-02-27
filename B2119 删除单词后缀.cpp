#include <bits/stdc++.h>
using namespace std;

int main() {
    string s;
    cin >> s;
    reverse(s.begin(), s.end());
    if (s.find("re", 0) == 0 || s.find("yl", 0) == 0) {
        s.erase(0, 2);
    } else {
        if (s.find("gni", 0) == 0) {
            s.erase(0, 3);
        }
    }
    reverse(s.begin(), s.end());
    cout << s;
    return 0;
}