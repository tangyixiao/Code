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

bool g[201][201];

int main() {
    for (int w = 1; w <= 200; ++w) {
        for (int h = 1; h <= 200; ++h) {
            if (w == 1 || h == 1) {
                g[w][h] = 1;
                continue;
            }
            bool win = 0;
            for (int i = 1; i < w && !win; ++i)
                if (!g[i][h] && !g[w - i][h])
                    win = 1;
            for (int j = 1; j < h && !win; ++j)
                if (!g[w][j] && !g[w][h - j])
                    win = 1;
            g[w][h] = win;
        }
    }
    int w, h;
    while (cin >> w >> h)
        cout << (g[w][h] ? "WIN" : "LOSE") << '\n';
}