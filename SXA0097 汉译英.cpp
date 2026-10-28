#include <bits/stdc++.h>
using namespace std;
int n;
string w[10] = {"", "one", "two", "three", "four", "five", "six", "seven", "eight", "nine"};
signed main() {
    cin >> n;
    if (n >= 1 && n <= 9) {
        cout << w[n] << "\n";
    } else {
        cout << "out" << "\n";
    }
    return 0;
}
