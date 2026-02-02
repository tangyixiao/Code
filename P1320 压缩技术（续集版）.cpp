#include <iostream>
#include <string>
using namespace std;
int n, x, num = 0, t = 1, ans = 0, cnt = 1;
string a, b;
int main() {
    cin >> b;
    n = b.size();
    cout << n << " ";
    while (cin >> a) {
        b += a;
    }
    if (b[0] != '0')
        cout << "0 ";
    for (int i = 1; i < n * n; i++) {
        if (b[i] == b[i - 1]) {
            t++;
        } else {
            cout << t << " ";
            t = 1;
        }
    }
    cout << t;
    return 0;
}
