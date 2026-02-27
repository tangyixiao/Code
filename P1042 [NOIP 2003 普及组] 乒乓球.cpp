#pragma G++ optimize("O3", "unroll-loops", "omit-frame-pointer", "inline")
#include <bits/stdc++.h>
using namespace std;
char C;
string S;
int n, A, B;
int main() {
    while (cin >> C) {
        if (C == 'E')
            break;
        S += C;
    }
    for (char i : S) {
        if (i == 'W')
            A++;
        if (i == 'L')
            B++;
        if (max(A, B) >= 11 && abs(A - B) >= 2) {
            cout << A << ":" << B << endl;
            A = 0, B = 0;
        }
    }
    printf("%d:%d\n", A, B);
    A = B = 0;
    puts("");
    for (char i : S) {
        if (i == 'W')
            A++;
        if (i == 'L')
            B++;
        if (max(A, B) >= 21 && abs(A - B) >= 2) {
            cout << A << ":" << B << endl;
            A = 0, B = 0;
        }
    }
    printf("%d:%d\n", A, B);
    return 0;
}
