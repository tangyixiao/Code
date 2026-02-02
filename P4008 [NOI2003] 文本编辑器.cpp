#include <bits/stdc++.h>
#include <ext/rope>
using namespace __gnu_cxx;
using namespace std;
rope<char> editor;
char ch;
string op;
int pos, n, rela;
int main() {
    scanf("%d", &n);
    while (n--) {
        cin >> op;
        scanf("%d", &rela);

        if (op == "Insert") {
            int pos1 = pos;
            while (rela) {
                ch = getchar();
                if ((int)ch >= 32 && (int)ch <= 126) {
                    editor.insert(pos1, ch);
                    rela--;
                    pos1++;
                }
            }
        }

        else if (op == "Move") {
            pos = rela;
        }

        else if (op == "Next") {
            pos++;
        }

        else if (op == "Prev") {
            pos--;
        }

        else if (op == "Get") {
            cout << editor.substr(pos, rela) << endl;
        }

        else if (op == "Delete") {
            editor.erase(pos, rela);
        }
    }
    return 0;
}
