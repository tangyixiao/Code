#include <bits/stdc++.h>
#include <windows.h>
using namespace std;

int main() {
    srand(time(0));
    for (int i = 1;; i++) {
        system("P3178generator.exe > P3178.in");
        system("P3178std.exe <  P3178.in > P3178.out");
        system("P3178brute.exe <  P3178.in > P3178.ans");
        system("fc P3178.out P3178.ans");
        Sleep(1000);
    }
    return 0;
}