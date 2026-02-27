#include <bits/stdc++.h>
using namespace std;
const int MAXN = 1e5 + 5;
int k, num = 1;
string a;
int main() {
    cin >> k >> a;
    for (int i = 1; i < a.length(); ++i) {
        if (a[i] == a[i - 1]) {
            num++;
            if (num >= k) {
                cout << a[i];
                return 0;
            }
        } else
            num = 1;
    }
    puts("No");
    return 0;
}
