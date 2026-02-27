#include <bits/stdc++.h>
using namespace std;
int n;
char ch[205];
inline void output() {
    for (int i = 0; i < 2 * n + 2; i++) {
        putchar(ch[i]);
    }
    putchar('\n');
    return;
}
inline void movechess(int st, int ed) {
    swap(ch[st], ch[ed]);
    swap(ch[st + 1], ch[ed + 1]);
    output();
    return;
}
string out[4] = {"ooo*o**--*", "o--*o**oo*", "o*o*o*--o*", "--o*o*o*o*"};
int main() {
    cin >> n;
    for (int i = 0; i < n; i++) {
        ch[i] = 'o';
    }
    for (int i = n; i < 2 * n; i++) {
        ch[i] = '*';
    }
    ch[2 * n] = '-';
    ch[2 * n + 1] = '-';
    output();
    int len = n;
    while (true) {
        movechess(len - 1, 2 * len);
        if ((--len) == 3) {
            break;
        }
        movechess(len, 2 * len);
    }
    string ss;
    for (int i = 0; i < n - 4; i++) {
        ss += "o*";
    }
    for (int i = 0; i < 4; i++) {
        cout << out[i] << ss << "\n";
    }
    return 0;
}
