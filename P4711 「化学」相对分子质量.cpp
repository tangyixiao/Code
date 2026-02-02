#include <bits/stdc++.h>
using namespace std;
map<string, double> mp;
double now, ans;
string s;

inline void init() {
    mp["H"] = 1;
    mp["C"] = 12;
    mp["N"] = 14;
    mp["O"] = 16;
    mp["F"] = 19;
    mp["Na"] = 23;
    mp["Mg"] = 24;
    mp["Al"] = 27;
    mp["Si"] = 28;
    mp["P"] = 31;
    mp["S"] = 32;
    mp["Cl"] = 35.5;
    mp["K"] = 39;
    mp["Ca"] = 40;
    mp["Mn"] = 55;
    mp["Fe"] = 56;
    mp["Cu"] = 64;
    mp["Zn"] = 65;
    mp["Ag"] = 108;
    mp["I"] = 127;
    mp["Ba"] = 137;
    mp["Hf"] = 178.5;
    mp["Pt"] = 195;
    mp["Au"] = 197;
    mp["Hg"] = 201;
}

// 提取元素名
string getElement() {
    string element;
    element += s[now++];
    if (now < s.size() && islower(s[now])) {
        element += s[now++];
    }
    return element;
}

int getnum() {
    int num = 0;
    for (; now < s.size() && isdigit(s[now]); now++) {
        num = num * 10 + s[now] - '0';
    }
    return num;
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    init();
    cin >> s;

    double cur = 0; // 括号内的累计值
    bool inParenthesis = false;

    while (now < s.size()) {
        if (isupper(s[now])) {
            string element = getElement();
            double mass = mp[element];

            if (now < s.size() && s[now] == '_') {
                // 处理下标
                now += 2; // 跳过"_{"
                int cnt = getnum();
                now++; // 跳过"}"
                mass *= cnt;
            }

            if (inParenthesis) {
                cur += mass;
            } else {
                ans += mass;
            }
        } else if (s[now] == '(') {
            inParenthesis = true;
            cur = 0;
            now++;
        } else if (s[now] == ')') {
            now++;
            int cnt = 1;
            if (now < s.size() && s[now] == '_') {
                now += 2; // 跳过"_{"
                cnt = getnum();
                now++; // 跳过"}"
            }
            ans += cur * cnt;
            inParenthesis = false;
        } else if (s[now] == '~') {
            now++;
            int cnt = 1;
            if (now < s.size() && isdigit(s[now])) {
                cnt = getnum();
            }
            ans += cnt * 18.0; // H₂O的相对分子质量
            break;
        }
    }

    // 处理可能的小数部分
    if (abs(ans - round(ans)) < 1e-9) {
        cout << (int)round(ans);
    } else {
        cout << fixed << setprecision(1) << ans;
    }

    return 0;
}