#include <bits/stdc++.h>
using namespace std;int main(int C,char**v){ios::sync_with_stdio(0);cin.tie(0);int R=C>1?stoi(v[1]):1000;unsigned long long s=C>2?stoull(v[2]):1;mt19937_64 q(s);while(R--){int n=q()%20+1;long long g=0;for(int i=0;i<n;i++){long long x=(int)(q()%200001)-100000;g=__gcd(g,abs(x));}if(g<0)return cout<<"WA\n",1;}cout<<"OK\n";}
