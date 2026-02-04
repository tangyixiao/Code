#include <bits/stdc++.h>
using namespace std;

struct Node {
    char v;
    bool isex;
    bool iscon;
    int cost;
};

int get_num(string s) {
    if (s == "n")
        return -1;
    int res = 0;
    for (char c : s) {
        res = res * 10 + (c - '0');
    }
    return res;
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(NULL);

    int t;
    cin >> t;

    while (t--) {
        int L;
        string comp;
        cin >> L >> comp;
        cin.ignore();

        int target_w = 0;
        if (comp != "O(1)") {

            int pos = comp.find('^');
            string w_str = comp.substr(pos + 1);
            w_str.pop_back();
            target_w = stoi(w_str);
        }

        stack<Node> stk;
        unordered_set<char> avs;
        vector<int> time_stack;
        bool wroer = false;
        int current_max = 0;
        bool inlop = true;

        for (int i = 0; i < L; i++) {
            string line;
            getline(cin, line);
            if (wroer)
                continue;

            if (line[0] == 'F') {

                stringstream ss(line);
                char op, v;
                string x_str, y_str;
                ss >> op >> v >> x_str >> y_str;

                if (avs.count(v)) {
                    wroer = true;
                    continue;
                }

                int x = get_num(x_str);
                int y = get_num(y_str);

                bool isex = true;
                bool iscon = true;
                int this_time = 0;

                if (x == -1 && y == -1) {

                    isex = true;
                    iscon = true;
                    this_time = 0;
                } else if (x == -1 && y != -1) {

                    isex = false;
                    iscon = true;
                    this_time = 0;
                } else if (x != -1 && y == -1) {

                    isex = true;
                    iscon = false;
                    this_time = 1;
                } else {

                    if (x <= y) {
                        isex = true;
                        iscon = true;
                        this_time = 0;
                    } else {
                        isex = false;
                        iscon = true;
                        this_time = 0;
                    }
                }

                int current_time = 0;
                if (inlop && isex) {

                    if (!iscon) {
                        current_time = 1;
                    }

                    if (!time_stack.empty()) {
                        current_time += time_stack.back();
                    }
                } else {

                    current_time = 0;
                    if (!time_stack.empty()) {

                        current_time = time_stack.back();
                    }
                }

                stk.push({v, isex, iscon, this_time});
                avs.insert(v);
                time_stack.push_back(current_time);

                inlop = inlop && isex;

                if (inlop) {
                    current_max = max(current_max, current_time);
                }

            } else if (line[0] == 'E') {

                if (stk.empty()) {
                    wroer = true;
                    continue;
                }

                Node node = stk.top();
                stk.pop();
                avs.erase(node.v);
                time_stack.pop_back();

                if (stk.empty()) {
                    inlop = true;
                } else {

                    stack<Node> temp_stk = stk;
                    bool fex = false;
                    inlop = true;

                    while (!temp_stk.empty()) {
                        Node cur = temp_stk.top();
                        temp_stk.pop();
                        if (!cur.isex) {
                            inlop = false;
                            break;
                        }
                    }
                }
            }
        }

        if (!stk.empty()) {
            wroer = true;
        }

        if (wroer) {
            cout << "ERR\n";
        } else if (current_max == target_w) {
            cout << "Yes\n";
        } else {
            cout << "No\n";
        }
    }

    return 0;
}