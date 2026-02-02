#include <bits/stdc++.h>
#include <sys/timeb.h>
using namespace std;
int main() {
    /*
    
    struct _timeb T;
    _ftime(&T);
    srand(T.millitm);

    */

    freopen("pow.in", "w", stdout);

    random_device rd;  // 获取真随机数种子
    mt19937 gen(rd()); // 用随机种子初始化MT19937
    
    // 2. 创建分布（指定随机数范围）
    uniform_int_distribution<> dis(1, 9); // 生成1-100的均匀分布整数
    
    // 3. 生成随机数

  
    for (int i = 0; i < 10000; ++i) {
        cout << dis(gen);
    }
    
   cout<<"\n";
   for(int i = 0; i < 10000; ++i){
    
        cout << dis(gen);
   }

    return 0;
}