#include <bits/stdc++.h>
#include <windows.h>
using namespace std;
const string idx = ".m4s";
const string mp4 = ".mp4";
const string del = "del";
string op;
signed main() {
    for (;;) {
        string op;
        cout << "\n Yes or No? (y/n): \n";
        getline(cin, op);
        if (op == "y") {
            string command = "ffmpeg -i 1" + idx + " -i 2" + idx + " -codec copy 3" + mp4;
            system(command.c_str());
            cout << "\nConversion successful!\n";
            string del_command1 = "del 1" + idx;
            string del_command2 = "del 2" + idx;
            system(del_command1.c_str());
            system(del_command2.c_str());
            cout << "\nDeleted original files.\n";
        }
    }
    system("pause");
    return 0;
}
