#include <bits/stdc++.h>
using namespace std;int main(){ios::sync_with_stdio(0);cin.tie(0);unsigned long long a,b;cin>>a>>b;while(b){a%=b;swap(a,b);}cout<<a<<'\n';}
