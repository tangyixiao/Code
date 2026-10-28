#include <bits/stdc++.h>
using namespace std;
char line[505];
string tk[205];
int nt;
signed main() {
    while (fgets(line, sizeof(line), stdin)) {
        string s = line;
        nt = 0;
        string cur = "";
        for (int i = 0; i <= (int)s.size(); i++) {
            if (i == (int)s.size() || !isgraph((unsigned char)s[i])) {
                if (!cur.empty()) {
                    tk[nt++] = cur;
                    cur = "";
                }
            } else {
                cur += s[i];
            }
        }
        if (nt == 0) {
            continue;
        }
        if (nt == 1 && tk[0] == "0") {
            break;
        }
        double sm = 0, c = 0;
        int p = 0;
        c = atof(tk[p++].c_str());
        while (p < nt) {
            char op = tk[p++][0];
            double v = atof(tk[p++].c_str());
            if (op == '*') {
                c *= v;
            } else if (op == '/') {
                c /= v;
            } else if (op == '+') {
                sm += c;
                c = v;
            } else {
                sm += c;
                c = -v;
            }
        }
        sm += c;
        printf("%.2f\n", sm);
    }
    return 0;
}
