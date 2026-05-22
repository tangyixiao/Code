#include <bits/stdc++.h>
#include <windows.h>
using namespace std;

int main() {
    srand(time(0));
    for (int i = 1;; i++) {
        system("P3178generator.exe > P3178.in");
        system("P3178std.exe");
        system("P3178brute.exe");
        if (system("fc P3178.out P3178.ans")) {
            cout << "WA on test " << i << endl;
            break;
        }
        Sleep(1000);
    }
    return 0;
}