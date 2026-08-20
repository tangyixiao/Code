#include<bits/stdc++.h>
using namespace std;
const int N=1e3;
char c[N];
string s;
int f(string p){ifstream q(p);string x,y;if(!(q>>x))return 0;if(x=="-1")return -1;if(!(q>>y)||x.size()!=s.size()||y.size()!=s.size())return 0;char z='Z';string t;for(int i=s.size()-1;i>=0;i--){if(x[i]>y[i])z='X';else if(x[i]<y[i])z='Y';t+=z;}return t==s;}
int main(int n,char**v){ios::sync_with_stdio(0);cin.tie(0);int r=n>1?stoi(v[1]):1000;unsigned d=n>2?stoul(v[2]):1;for(int i=0;i<r;i++){snprintf(c,N,"./gen %u > in",d+i);if(system(c)||system("./std < in > out")||system("./bf < in > ans"))return 1;ifstream q("in");q>>s;int a=f("out"),b=f("ans");if(!a||!b||(a<0)!=(b<0))return cout<<d+i<<'\n',1;}cout<<"OK\n";}
