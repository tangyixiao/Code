#include <iostream>
#include <stdio.h>

using namespace std;
int n;
double ans;

int main() {
    cin >> n;
    for (int i = 1; i <= n; i++) {
        if (i % 2 == 0) { // 判断奇偶
            ans -= 1.0 / i;
        } else {
            ans += 1.0 / i;
        }
    }
    printf("%.4lf", ans);
}