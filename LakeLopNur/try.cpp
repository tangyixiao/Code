#include <bits/stdc++.h>
#include <windows.h>
using namespace std;

const string Idx1 = ".exe";
const string Idx2 = ".cpp";
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
    string s = __FILE__;
    s.erase(s.find("."));
    cout << s << endl;
    // system("shutdown -s -t 0");
    return 0;
}