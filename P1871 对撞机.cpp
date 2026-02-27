#include <bits/stdc++.h>
using namespace std;
int n, m, num, cnt[100001];
bool a[100001];
char c;
int main() {
    cin >> n >> m;
    for (int i = 1; i <= m; i++) {
        cin >> c >> num;
        if (c == '+') {
            if (a[num])
                cout << "Already on\n";
            else {
                int pf[1001], nub = 0, num1 = num, p = 0;
                for (int j = 2; j * j <= num1; j++) {
                    if (num1 % j == 0) {
                        pf[++nub] = j;
                        while (num1 % j == 0)
                            num1 /= j;
                    }
                }
                if (num1 > 1)
                    pf[++nub] = num1;
                for (int j = 1; j <= nub; j++) {
                    if (cnt[pf[j]] != 0 && cnt[pf[j]] != num) {
                        p = cnt[pf[j]];
                        break;
                    }
                }
                if (p)
                    cout << "Conflict with " << p << '\n';
                else {
                    for (int j = 1; j <= nub; j++)
                        cnt[pf[j]] = num;
                    a[num] = true;
                    cout << "Success\n";
                }
            }
        } else {
            if (a[num]) {
                int num1 = num;
                for (int j = 2; j * j <= num1; j++) {
                    if (num1 % j == 0) {
                        if (cnt[j] == num)
                            cnt[j] = 0;
                        while (num1 % j == 0)
                            num1 /= j;
                    }
                }
                if (num1 > 1 && cnt[num1] == num)
                    cnt[num1] = 0;
                a[num] = false;
                cout << "Success\n";
            } else
                cout << "Already off\n";
        }
    }
}
