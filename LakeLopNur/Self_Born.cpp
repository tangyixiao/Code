#include <iostream>
#include <fstream>
#include <string>
#include <cstdlib>
#include <thread>
#include <chrono>

using namespace std;

// 递归复制函数
void replicateSelf(int remainingCopies) {
    if (remainingCopies <= 0) {
        cout << "复制完成，共创建 " << -remainingCopies << " 个副本" << endl;
        return;
    }
    
    // 读取自身源代码
    ifstream sourceFile(__FILE__);
    if (!sourceFile) {
        cerr << "无法读取源文件" << endl;
        return;
    }
    
    // 生成新文件名
    string newFileName = "copy_" + to_string(remainingCopies) + ".cpp";
    
    // 复制源代码
    ofstream copyFile(newFileName);
    string line;
    while (getline(sourceFile, line)) {
        copyFile << line << endl;
    }
    copyFile.close();
    
    cout << "创建副本: " << newFileName << endl;
    
    // 编译并运行新副本（实际项目中需要更安全的编译命令）
    string compileCommand = "g++ -o copy_" + to_string(remainingCopies) + 
                           " " + newFileName + " 2>/dev/null";
    
    if (system(compileCommand.c_str()) == 0) {
        // 运行新副本
        string runCommand = "./copy_" + to_string(remainingCopies) + 
                           " " + to_string(remainingCopies - 1) + " &";
        system(runCommand.c_str());
        
        // 短暂延迟
        this_thread::sleep_for(chrono::milliseconds(100));
    }
    
    // 递归创建更多副本
    replicateSelf(remainingCopies - 1);
}

int main(int argc, char* argv[]) {
    int copies = 100; // 默认复制次数
    
    if (argc > 1) {
        copies = atoi(argv[1]);
    }
    
    cout << "=== 自递归复制程序 ===" << endl;
    cout << "将创建 " << copies << " 个副本" << endl;
    
    // 开始递归复制
    replicateSelf(copies);
    
    // 等待所有副本完成
    this_thread::sleep_for(chrono::seconds(1));
    cout << "主程序结束" << endl;
    
    return 0;
}