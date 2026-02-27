#include <bits/stdc++.h>
using namespace std;
const int N = 6;
int n;
string s, ans[N];
signed main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cin >> n;
    cin >> s;
    for (int i = 1; i <= n; i++) {
        if (s[i - 1] == '0') {
            ans[1] += "XXX";
            ans[2] += "X.X";
            ans[3] += "X.X";
            ans[4] += "X.X";
            ans[5] += "XXX";
        } else {
            if (s[i - 1] == '1') {
                ans[1] += "..X";
                ans[2] += "..X";
                ans[3] += "..X";
                ans[4] += "..X";
                ans[5] += "..X";
            } else {
                if (s[i - 1] == '2') {
                    ans[1] += "XXX";
                    ans[2] += "..X";
                    ans[3] += "XXX";
                    ans[4] += "X..";
                    ans[5] += "XXX";
                } else {
                    if (s[i - 1] == '3') {
                        ans[1] += "XXX";
                        ans[2] += "..X";
                        ans[3] += "XXX";
                        ans[4] += "..X";
                        ans[5] += "XXX";
                    } else {
                        if (s[i - 1] == '4') {
                            ans[1] += "X.X";
                            ans[2] += "X.X";
                            ans[3] += "XXX";
                            ans[4] += "..X";
                            ans[5] += "..X";
                        } else {
                            if (s[i - 1] == '5') {
                                ans[1] += "XXX";
                                ans[2] += "X..";
                                ans[3] += "XXX";
                                ans[4] += "..X";
                                ans[5] += "XXX";
                            } else {
                                if (s[i - 1] == '6') {
                                    ans[1] += "XXX";
                                    ans[2] += "X..";
                                    ans[3] += "XXX";
                                    ans[4] += "X.X";
                                    ans[5] += "XXX";
                                } else {
                                    if (s[i - 1] == '7') {
                                        ans[1] += "XXX";
                                        ans[2] += "..X";
                                        ans[3] += "..X";
                                        ans[4] += "..X";
                                        ans[5] += "..X";
                                    } else {
                                        if (s[i - 1] == '8') {
                                            ans[1] += "XXX";
                                            ans[2] += "X.X";
                                            ans[3] += "XXX";
                                            ans[4] += "X.X";
                                            ans[5] += "XXX";
                                        } else {
                                            if (s[i - 1] == '9') {
                                                ans[1] += "XXX";
                                                ans[2] += "X.X";
                                                ans[3] += "XXX";
                                                ans[4] += "..X";
                                                ans[5] += "XXX";
                                            }
                                        }
                                    }
                                }
                            }
                        }
                    }
                }
            }
        }
        if (i != n) {
            ans[1] += ".";
            ans[2] += ".";
            ans[3] += ".";
            ans[4] += ".";
            ans[5] += ".";
        }
    }
    for (int i = 1; i <= 5; i++) {
        cout << ans[i] << '\n';
    }
    return 0;
}