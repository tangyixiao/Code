#include <bits/stdc++.h>
using namespace std;
int n, h, m;
string one[25], tens[10];
string say(int x) {
    if (x <= 20) {
        return one[x];
    }
    string s = tens[x / 10];
    if (x % 10 != 0) {
        s = s + " " + one[x % 10];
    }
    return s;
}
signed main() {
    one[0] = "zero";
    one[1] = "one";
    one[2] = "two";
    one[3] = "three";
    one[4] = "four";
    one[5] = "five";
    one[6] = "six";
    one[7] = "seven";
    one[8] = "eight";
    one[9] = "nine";
    one[10] = "ten";
    one[11] = "eleven";
    one[12] = "twelve";
    one[13] = "thirteen";
    one[14] = "fourteen";
    one[15] = "fifteen";
    one[16] = "sixteen";
    one[17] = "seventeen";
    one[18] = "eighteen";
    one[19] = "nineteen";
    one[20] = "twenty";
    tens[2] = "twenty";
    tens[3] = "thirty";
    tens[4] = "forty";
    tens[5] = "fifty";
    cin >> h >> m;
    if (m == 0) {
        cout << say(h) << " o'clock" << "\n";
    } else {
        cout << say(h) << " " << say(m) << "\n";
    }
    return 0;
}
