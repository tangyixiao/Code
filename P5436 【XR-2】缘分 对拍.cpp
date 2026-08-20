#include <bits/stdc++.h>
using namespace std;int main(int C,char**v){ios::sync_with_stdio(0);cin.tie(0);int R=C>1?stoi(v[1]):1000;unsigned long long s=C>2?stoull(v[2]):1;mt19937_64 g(s);while(R--){int n=g()%100+1;long long a=n==1?1:1LL*n*(n-1),b=1;for(int i=1;i<=n;i++)for(int j=1;j<=n;j++)b=max(b,1LL*i/__gcd(i,j)*j);if(a!=b)return cout<<"WA\n",1;}cout<<"OK\n";}
