#include <bits/stdc++.h>
using namespace std;
const int N = 1000010;
const int H[] = {0, -50, -2, -3, -4, -5, -6, -7, -8, -9, -10, -20, -30, -40};
const int S12 = -100;
const int D11 = 100;
int n, cntbr, cnttot;
vector<string> s;
struct node {
    int a, b, c, d;
} sco[N];
int score() {
    int ans = 0;
    int cntH = 0, cntC10 = 0;
    int cntS12 = 0, cntD11 = 0;
    int bothS12D11 = 0;
    for (int i = 0; i < s.size(); i++) {
        if (s[i][0] == 'H')
            cntH++;
        if (s[i][0] == 'C' && s[i][1] == '1' && s[i][2] == '0')
            cntC10++;
        if (s[i][0] == 'S' && s[i][1] == '1' && s[i][2] == '2')
            cntS12++;
        if (s[i][0] == 'D' && s[i][1] == '1' && s[i][2] == '1')
            cntD11++;
        if (cntD11 && cntS12)
            bothS12D11++;
    }
    if (cntH == 13 && !bothS12D11)
        ans += 200;
    else if (cntH == 13 && bothS12D11)
        ans += 500;
    if (s.size() == 1 && cntC10)
        ans += 50;
    if (cntS12 && !bothS12D11)
        ans += S12;
    if (cntD11 && !bothS12D11)
        ans += D11;
    if (cntH < 13) {
        for (int i = 0; i < s.size(); i++) {
            if (s[i][0] == 'H' && s[i][1] == '1' && s[i].size() == 2)
                ans += H[1];
            if (s[i][0] == 'H' && s[i][1] == '2' && s[i].size() == 2)
                ans += H[2];
            if (s[i][0] == 'H' && s[i][1] == '3' && s[i].size() == 2)
                ans += H[3];
            if (s[i][0] == 'H' && s[i][1] == '4' && s[i].size() == 2)
                ans += H[4];
            if (s[i][0] == 'H' && s[i][1] == '5' && s[i].size() == 2)
                ans += H[5];
            if (s[i][0] == 'H' && s[i][1] == '6' && s[i].size() == 2)
                ans += H[6];
            if (s[i][0] == 'H' && s[i][1] == '7' && s[i].size() == 2)
                ans += H[7];
            if (s[i][0] == 'H' && s[i][1] == '8' && s[i].size() == 2)
                ans += H[8];
            if (s[i][0] == 'H' && s[i][1] == '9' && s[i].size() == 2)
                ans += H[9];
            if (s[i][0] == 'H' && s[i][1] == '1' && s[i][2] == '0' && s[i].size() == 3)
                ans += H[10];
            if (s[i][0] == 'H' && s[i][1] == '1' && s[i][2] == '1' && s[i].size() == 3)
                ans += H[11];
            if (s[i][0] == 'H' && s[i][1] == '1' && s[i][2] == '2' && s[i].size() == 3)
                ans += H[12];
            if (s[i][0] == 'H' && s[i][1] == '1' && s[i][2] == '3' && s[i].size() == 3)
                ans += H[13];
        }
    }
    if (s.size() > 1 && cntC10)
        ans <<= 1;
    return ans;
}
int main() {
    while (1) {
        cntbr = 0;
        cnttot++;
        for (int i = 1; i <= 4; i++) {
            s.clear();
            cin >> n;
            if (n == 0)
                cntbr++;
            for (int j = 1; j <= n; j++) {
                string str;
                cin >> str;
                s.push_back(str);
            }
            if (i == 1)
                sco[cnttot].a = score();
            if (i == 2)
                sco[cnttot].b = score();
            if (i == 3)
                sco[cnttot].c = score();
            if (i == 4)
                sco[cnttot].d = score();
        }
        if (cntbr == 4)
            break;
    }
    for (int i = 1; i < cnttot; i++) {
        if (sco[i].a > 0)
            printf("+%d ", sco[i].a);
        if (sco[i].a <= 0)
            printf("%d ", sco[i].a);
        if (sco[i].b > 0)
            printf("+%d ", sco[i].b);
        if (sco[i].b <= 0)
            printf("%d ", sco[i].b);
        if (sco[i].c > 0)
            printf("+%d ", sco[i].c);
        if (sco[i].c <= 0)
            printf("%d ", sco[i].c);
        if (sco[i].d > 0)
            printf("+%d ", sco[i].d);
        if (sco[i].d <= 0)
            printf("%d ", sco[i].d);
        puts("");
    }
    return 0;
}
