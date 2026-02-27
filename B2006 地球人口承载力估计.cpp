#include <bits/stdc++.h>
using namespace std;
double x, a, y, b;
int main() {
    cin >> x >> a >> y >> b;
    printf("%.2lf", (x * a - y * b) / (a - b));
    return 0;
}