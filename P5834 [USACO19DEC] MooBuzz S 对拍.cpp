#include<bits/stdc++.h>
using namespace std;
const int N=1e3;
char a[N];
int main(int c,char**v){ios::sync_with_stdio(0);cin.tie(0);int n=c>1?stoi(v[1]):1000;unsigned s=c>2?stoul(v[2]):1;for(int i=0;i<n;i++){snprintf(a,N,"./gen %u > in",s+i);if(system(a)||system("./std < in > out")||system("./bf < in > ans")||system("diff -wB out ans"))return cout<<s+i<<'\n',1;}cout<<"OK\n";}
