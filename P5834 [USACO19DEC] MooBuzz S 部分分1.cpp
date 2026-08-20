#include<bits/stdc++.h>
using namespace std;
int main(){ios::sync_with_stdio(0);cin.tie(0);int n,c=0;cin>>n;for(int i=1;;i++)if(i%3&&i%5&&++c==n)return cout<<i<<'\n',0;}
