#include <bits/stdc++.h>
using namespace std;
int main() {
    int n;
    scanf("%d", &n);
    double sign = (n % 2 == 0) ? 1.0 : -1.0;
    double term = pow(2.0, 1.0 - n);
    double p = (2.0 - sign * term) / 3.0;
    double q = 1.0 - p;
    printf("%.8f\n%.8f\n", p, q);
    return 0;
}