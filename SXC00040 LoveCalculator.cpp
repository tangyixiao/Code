#include <bits/stdc++.h>
using namespace std;

int L, O, V, E;
int best;
string bs, line, all, cur, mm;
vector<string> boys;

int calc(const string &na, const string &nb) {
    L = O = V = E = 0;
    for (int i = 0; i < (int)na.size(); i++) {
        if (na[i] == 'L') {
            L++;
        }
        if (na[i] == 'O') {
            O++;
        }
        if (na[i] == 'V') {
            V++;
        }
        if (na[i] == 'E') {
            E++;
        }
    }
    for (int i = 0; i < (int)nb.size(); i++) {
        if (nb[i] == 'L') {
            L++;
        }
        if (nb[i] == 'O') {
            O++;
        }
        if (nb[i] == 'V') {
            V++;
        }
        if (nb[i] == 'E') {
            E++;
        }
    }
    return ((L + O) * (L + V) * (L + E) * (O + V) * (O + E) * (V + E)) % 100;
}

signed main() {
    FILE *fp = fopen("calc.in", "r");
    if (fp != NULL) {
        fclose(fp);
        freopen("calc.in", "r", stdin);
        freopen("calc.out", "w", stdout);
    }
    getline(cin, line);
    for (int i = 0; i < (int)line.size(); i++) {
        if (line[i] >= 'A' && line[i] <= 'Z') {
            mm += line[i];
        }
    }
    for (; getline(cin, line);) {
        all += line;
        all += ' ';
    }
    for (int i = 0; i < (int)all.size(); i++) {
        char ch = all[i];
        if (ch >= 'A' && ch <= 'Z') {
            cur += ch;
        } else if (!cur.empty()) {
            boys.push_back(cur);
            cur.clear();
        }
    }
    if (!cur.empty()) {
        boys.push_back(cur);
    }
    best = -1;
    for (int i = 0; i < (int)boys.size(); i++) {
        int p = calc(mm, boys[i]);
        if (p > best || (p == best && boys[i] < bs)) {
            best = p, bs = boys[i];
        }
    }
    cout << bs << "\n";
    return 0;
}
