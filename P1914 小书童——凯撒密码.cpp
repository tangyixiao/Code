#include <bits/stdc++.h>
using namespace std;
int n;
string s;
int main() {
    scanf("%d", &n);
    cin >> s;
    for (int i = 0; i < s.size(); i++) {
        s[i] = (s[i] - 'a' + n) % 26 + 'a';
    }
    cout << s;
    return 0;
}