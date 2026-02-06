#include <bits/stdc++.h>
#include <windows.h>
using namespace std;
const string idx = ".m4s";
const string mp4 = ".mp4";
string op;
signed main() {
    for (;;) {
        string op;
        cout << "\n Yes or No? (y/n): \n";
        getline(cin, op);
        if (op == "y") {
            string command =
                "ffmpeg -i 1" + idx + " -i 2" + idx + " -codec copy 3" + mp4;
            system(command.c_str());
            cout << "\nConversion successful!\n";
        }
    }
    system("pause");
    return 0;
}
