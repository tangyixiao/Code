#include <bits/stdc++.h>
using namespace std;
long long q(long long a,long long b,long long p){long long r=1%p;for(;b;b>>=1,a=(__int128)a*a%p)if(b&1)r=(__int128)r*a%p;return r;}
int main(int c,char**v){ios::sync_with_stdio(0);cin.tie(0);int n=c>1?stoi(v[1]):1000;unsigned long long s=c>2?stoull(v[2]):1;mt19937_64 g(s);while(n--){long long p=g()%100000+2,a=g()%p,b=g()%80,r=1%p;for(int i=0;i<b;i++)r=(__int128)r*a%p;if(q(a,b,p)!=r)return cout<<"WA\n",1;}cout<<"OK\n";}
