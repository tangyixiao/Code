#include <bits/stdc++.h>
using namespace std;
int num[3], GCD;
int main() {
    for (int i = 0; i < 3; i++)
        cin >> num[i];
    sort(num, num + 3); // 排序
    for (GCD = num[0]; GCD > 1; GCD--)
        if (num[0] % GCD == 0 && num[2] % GCD == 0)
            break;
    cout << num[0] / GCD << "/" << num[2] / GCD;
}
