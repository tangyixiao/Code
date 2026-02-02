#include<bits/stdc++.h>
using namespace std;
int main(){
    long long int x,y,xmx,ymx;
    cin>>x>>xmx>>y>>ymx;
    if(x*y<=2147483647&&x*y>=-2147483648){
        if(xmx*y<=2147483647&&xmx*y>=-2147483648)
            if(xmx*ymx<=2147483647&&xmx*ymx>=-2147483648)
                 if(x*ymx<=2147483647&&x*ymx>=-2147483648)
                 {cout<<"int";return 0;}
    }
    cout<<"long long int";
    return 0;
}

