#include <bits/stdc++.h>
using namespace std;
int c = 1, n;
int main() {
    cin >> n;
    for (int i = n; i >= 1; i--) {
        for (int j = 1; j <= i; j++) {
            if (c < 10) {
                cout << "0" << c;
            } else {
                cout << c;
            }
            c++;
        }
        cout << endl;
    }
    return 0;
}
