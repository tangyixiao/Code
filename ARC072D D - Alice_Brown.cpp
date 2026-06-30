// By Tangyixiao
// Problem: D - Alice&Brown
// Contest: AtCoder - AtCoder Beginner Contest 059
// URL: https://atcoder.jp/contests/abc059/tasks/arc072_b
// Memory Limit: 256 MB
// Time Limit: 2000 ms
//
// Powered by CP Editor (https://cpeditor.org)
#include <cmath>
#include <iostream>
using namespace std;
int main() {
    long long x, y;
    cin >> x >> y;
    cout << (abs(x - y) <= 1 ? "Brown" : "Alice");

    return 0;
}