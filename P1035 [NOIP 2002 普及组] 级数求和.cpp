#include <bits/stdc++.h>
using namespace std;
int n, k;
double Sn;
int main() {
    scanf("%d", &k);
    while (Sn <= k) {
        n++;
        Sn += ((1.0) / (double)(n));
    }
    printf("%d", n);
    return 0;
}