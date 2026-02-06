#include <bits/stdc++.h>
#include <windows.h>
using namespace std;
const string idx = ".m4s";
const string mp4 = ".mp4";
string name1, name2, name;
signed main() {
    for (;;) {
        cout << "\nEnter the name1 of the file: \n";
        getline(cin, name1);
        cout << "\nEnter the name2 of the file: \n";
        getline(cin, name2);
        cout << "\nEnter the name of the output file: \n";
        getline(cin, name);
        string command =
            "ffmpeg -i " + name1 + idx + " -i " + name2 + idx + " -codec copy " + name + mp4;
        system(command.c_str());
        cout << "\nConversion successful!\n";
    }
    system("pause");
    return 0;
}
