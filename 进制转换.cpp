#include<bits/stdc++.h>
using namespace std;
inline int Base2Oct(int Base,string Number){
    int Result=0;
    for(int i=0,NumCode;i<Number.size();i++){
        if(Number[i]>='A'&&Number[i]<='Z'){
            NumCode=Number[i]-'A'+10;
        }
        else{
            NumCode=Number[i]-'0';
        }
        Result=Result*Base+NumCode;
    }
    return Result;
}
inline string Oct2Base(int Base,int Number){
    string Result;
    for(int NumCode;Number;){
        NumCode=Number%Base;
        Number/=Base;
        if(NumCode>=10&&NumCode<=36){
            Result+=(NumCode-10+'A');
        }
        else{
            Result+=(NumCode+'0');
        }
    }
    reverse(Result.begin(),Result.end());
    return Result;
}
signed main(){
    cout<<Base2Oct(16,"A1")<<"\n";
    cout<<Oct2Base(16,161)<<"\n";
    return 0;
}