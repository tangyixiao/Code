#include <bits/stdc++.h>
using namespace std;
int main() {
    char n[1001];
    int s, len;
    cin >> n >> s;
    len = strlen(n);
    for (int k = 1; k <= s; k++) {
        for (int j = 0; j < len; j++) {
            if (n[j + 1] < n[j]) {
                for (int i = j; i <= len; i++) {
                    n[i] = n[i + 1];
                }
                len--;
                break;
            }
        }
    }
    bool flag = false;
    for (int i = 0; i < len; i++) {
        if (n[i] != '0')
            flag = true;
        if (flag)
            cout << n[i];
    }
    if (!flag)
        cout << 0;
    return 0;
}
