// By Tangyixiao
// Problem: Cutting Game
// Contest: POJ - POJ Monthly
// URL: http://poj.org/problem?id=2311
// Memory Limit: 65 MB
// Time Limit: 1000 ms
//
// Powered by CP Editor (https://cpeditor.org)
#include <iostream>
using namespace std;
int sg[201][201];
int main() {
    for (int w = 2; w <= 200; ++w)
        for (int h = 2; h <= 200; ++h) {
            if (w <= 3 && h <= 3)
                continue;
            bool v[500] = {0};
            for (int i = 2; i <= w - 2; ++i) {
                int t = sg[i][h] ^ sg[w - i][h];
                if (t < 500)
                    v[t] = 1;
            }
            for (int j = 2; j <= h - 2; ++j) {
                int t = sg[w][j] ^ sg[w][h - j];
                if (t < 500)
                    v[t] = 1;
            }
            int m = 0;
            while (v[m])
                ++m;
            sg[w][h] = m;
        }
    int w, h;
    while (cin >> w >> h)
        cout << (sg[w][h] ? "WIN" : "LOSE") << '\n';
    return 0;
}