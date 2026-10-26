#include <bits/stdc++.h>
using namespace std;
double x, y;
signed main() {
    scanf("%lf%lf", &x, &y);
    if ((x >= 60 && y < 60) || (y >= 60 && x < 60)) {
        printf("green\n");
    } else {
        printf("red\n");
    }
    return 0;
}
