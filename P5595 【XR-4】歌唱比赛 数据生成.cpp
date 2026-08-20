#include<bits/stdc++.h>
using namespace std;
int main(int c,char**v){ios::sync_with_stdio(0);cin.tie(0);unsigned s=c>1?stoul(v[1]):chrono::steady_clock::now().time_since_epoch().count();mt19937 g(s);int z=c>2?stoi(v[2]):0,n=z?uniform_int_distribution<int>(1,1e6)(g):uniform_int_distribution<int>(1,4)(g);for(int i=0;i<n;i++)cout<<"XYZ"[g()%3];cout<<'\n';}
