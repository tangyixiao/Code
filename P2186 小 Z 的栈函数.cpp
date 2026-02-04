#include <algorithm>
#include <cmath>
#include <iostream>
#include <string>
#include <vector>

using namespace std;

const long long LIMIT = 1000000000;

enum OpType { NUM, POP, INV, DUP, SWP, ADD, SUB, MUL, DIV, MOD, END };

struct Op {
    OpType type;
    long long val;
};

int main() {
    vector<Op> ops;
    string s;
    while (cin >> s) {
        if (s == "NUM") {
            long long x;
            cin >> x;
            ops.push_back({NUM, x});
        } else if (s == "POP")
            ops.push_back({POP, 0});
        else if (s == "INV")
            ops.push_back({INV, 0});
        else if (s == "DUP")
            ops.push_back({DUP, 0});
        else if (s == "SWP")
            ops.push_back({SWP, 0});
        else if (s == "ADD")
            ops.push_back({ADD, 0});
        else if (s == "SUB")
            ops.push_back({SUB, 0});
        else if (s == "MUL")
            ops.push_back({MUL, 0});
        else if (s == "DIV")
            ops.push_back({DIV, 0});
        else if (s == "MOD")
            ops.push_back({MOD, 0});
        else if (s == "END") {
            ops.push_back({END, 0});
            break;
        }
    }

    int n;
    cin >> n;
    for (int i = 0; i < n; i++) {
        long long x;
        cin >> x;
        vector<long long> st;
        st.push_back(x);
        if (abs(x) > LIMIT) {
            cout << "ERROR\n";
            continue;
        }
        bool error = false;
        for (const Op &op : ops) {
            if (op.type == END) {
                if (st.size() != 1)
                    error = true;
                break;
            } else if (op.type == NUM) {
                long long num = op.val;
                if (abs(num) > LIMIT) {
                    error = true;
                    break;
                }
                st.push_back(num);
            } else if (op.type == POP) {
                if (st.size() < 1) {
                    error = true;
                    break;
                }
                st.pop_back();
            } else if (op.type == INV) {
                if (st.size() < 1) {
                    error = true;
                    break;
                }
                long long a = st.back();
                st.pop_back();
                long long res = -a;
                if (abs(res) > LIMIT) {
                    error = true;
                    break;
                }
                st.push_back(res);
            } else if (op.type == DUP) {
                if (st.size() < 1) {
                    error = true;
                    break;
                }
                long long a = st.back();
                st.push_back(a);
            } else if (op.type == SWP) {
                if (st.size() < 2) {
                    error = true;
                    break;
                }
                long long a = st.back();
                st.pop_back();
                long long b = st.back();
                st.pop_back();
                st.push_back(a);
                st.push_back(b);
            } else if (op.type == ADD) {
                if (st.size() < 2) {
                    error = true;
                    break;
                }
                long long a = st.back();
                st.pop_back();
                long long b = st.back();
                st.pop_back();
                long long res = b + a;
                if (abs(res) > LIMIT) {
                    error = true;
                    break;
                }
                st.push_back(res);
            } else if (op.type == SUB) {
                if (st.size() < 2) {
                    error = true;
                    break;
                }
                long long a = st.back();
                st.pop_back();
                long long b = st.back();
                st.pop_back();
                long long res = b - a;
                if (abs(res) > LIMIT) {
                    error = true;
                    break;
                }
                st.push_back(res);
            } else if (op.type == MUL) {
                if (st.size() < 2) {
                    error = true;
                    break;
                }
                long long a = st.back();
                st.pop_back();
                long long b = st.back();
                st.pop_back();
                long long res = b * a;
                if (abs(res) > LIMIT) {
                    error = true;
                    break;
                }
                st.push_back(res);
            } else if (op.type == DIV) {
                if (st.size() < 2) {
                    error = true;
                    break;
                }
                long long a = st.back();
                st.pop_back();
                long long b = st.back();
                st.pop_back();
                if (a == 0) {
                    error = true;
                    break;
                }
                long long res = b / a;
                if (abs(res) > LIMIT) {
                    error = true;
                    break;
                }
                st.push_back(res);
            } else if (op.type == MOD) {
                if (st.size() < 2) {
                    error = true;
                    break;
                }
                long long a = st.back();
                st.pop_back();
                long long b = st.back();
                st.pop_back();
                if (a == 0) {
                    error = true;
                    break;
                }
                long long res = b % a;
                if (abs(res) > LIMIT) {
                    error = true;
                    break;
                }
                st.push_back(res);
            }
        }
        if (!error && st.size() == 1) {
            cout << st[0] << "\n";
        } else {
            cout << "ERROR\n";
        }
    }
    return 0;
}