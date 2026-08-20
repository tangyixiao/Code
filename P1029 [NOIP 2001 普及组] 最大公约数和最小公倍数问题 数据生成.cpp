#include <bits/stdc++.h>
using namespace std;int main(int c,char**v){ios::sync_with_stdio(0);cin.tie(0);unsigned long long s=c>1?stoull(v[1]):1,z=c>2?stoull(v[2]):100000;mt19937_64 g(s);int m=min(100000ULL,max(2ULL,z)),x=g()%(m-1)+2,y=x*(g()%max(1,100000/x)+1);cout<<x<<' '<<y<<'\n';}
