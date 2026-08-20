#include<bits/stdc++.h>
using namespace std;
const int N=1e1;
string a[N]={"Beatrice","Belinda","Bella","Bessie","Betsy","Blue","Buttercup","Sue"};
int main(int c,char**v){ios::sync_with_stdio(0);cin.tie(0);unsigned s=c>1?stoul(v[1]):chrono::steady_clock::now().time_since_epoch().count();mt19937 g(s);shuffle(a,a+8,g);int n=uniform_int_distribution<int>(0,7)(g);cout<<n<<'\n';for(int i=0;i<n;i++)cout<<a[i]<<" must be milked beside "<<a[i+1]<<'\n';}
