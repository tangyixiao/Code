from build_lib import add
E=r'''#include <bits/stdc++.h>
using namespace std;long long E(long long a,long long b,long long&x,long long&y){if(!b)return x=1,y=0,a;long long d=E(b,a%b,y,x);y-=a/b*x;return d;}
'''
A=E+r'''int main(){ios::sync_with_stdio(0);cin.tie(0);long long x,y,m,n,L,a,b;cin>>x>>y>>m>>n>>L;long long q=m-n,d=E(abs(q),L,a,b),c=y-x;if(q<0)a=-a;if(c%d)return cout<<"Impossible\n",0;L/=d;cout<<(long long)(((__int128)a*(c/d)%L+L)%L)<<'\n';}
'''
AB=r'''#include <bits/stdc++.h>
using namespace std;int main(){ios::sync_with_stdio(0);cin.tie(0);long long x,y,m,n,L;cin>>x>>y>>m>>n>>L;for(int t=0;t<=L;t++)if((x+m*t-y-n*t)%L==0)return cout<<t<<'\n',0;cout<<"Impossible\n";}
'''
AG=r'''#include <bits/stdc++.h>
using namespace std;int main(int c,char**v){ios::sync_with_stdio(0);cin.tie(0);unsigned long long s=c>1?stoull(v[1]):1,z=c>2?stoull(v[2]):100;mt19937_64 g(s);long long L=g()%max(2ULL,z)+2;cout<<g()%L+1<<' '<<g()%L+1<<' '<<g()%L+1<<' '<<g()%L+1<<' '<<L<<'\n';}
'''
AS=r'''#include <bits/stdc++.h>
using namespace std;long long E(long long a,long long b,long long&x,long long&y){if(!b)return x=1,y=0,a;long long d=E(b,a%b,y,x);y-=a/b*x;return d;}int main(int C,char**v){ios::sync_with_stdio(0);cin.tie(0);int R=C>1?stoi(v[1]):1000;unsigned long long s=C>2?stoull(v[2]):1;mt19937_64 g(s);while(R--){long long L=g()%100+1,x=g()%L,y=g()%L,m=g()%100+1,n=g()%100+1,a,b,q=m-n,d=E(abs(q),L,a,b),c=y-x,A=-1,B=-1;if(q<0)a=-a;if(c%d==0){q=L/d;A=((__int128)a*(c/d)%q+q)%q;}for(int t=0;t<=L;t++)if((x+m*t-y-n*t)%L==0){B=t;break;}if(A!=B)return cout<<"WA\n",1;}cout<<"OK\n";}
'''
add('P1516','P1516 青蛙的约会',r'相遇条件为 $(m-n)t\equiv y-x\pmod L$。扩展欧几里得求出系数；右端不能被 gcd 整除时无解，否则乘上对应倍数并对 $L/\gcd(m-n,L)$ 归一化，得到最小非负解。',{'.cpp':A,' 数据生成.cpp':AG,' 暴力.cpp':AB,' 对拍.cpp':AS},parts=[AB],extra=[('1 2 1 1 5\n','Impossible\n'),('1 3 3 1 5\n','1\n'),('5 1 1 3 7\n','2\n')])

B=E+r'''int main(){ios::sync_with_stdio(0);cin.tie(0);long long a,b,x,y;cin>>a>>b;E(a,b,x,y);cout<<(x%b+b)%b<<'\n';}
'''
BB=r'''#include <bits/stdc++.h>
using namespace std;int main(){ios::sync_with_stdio(0);cin.tie(0);long long a,b;cin>>a>>b;for(int x=1;x<b;x++)if(a*x%b==1)return cout<<x<<'\n',0;}
'''
BS=r'''#include <bits/stdc++.h>
using namespace std;long long E(long long a,long long b,long long&x,long long&y){if(!b)return x=1,y=0,a;long long d=E(b,a%b,y,x);y-=a/b*x;return d;}int main(int C,char**v){ios::sync_with_stdio(0);cin.tie(0);int R=C>1?stoi(v[1]):1000;unsigned long long s=C>2?stoull(v[2]):1;mt19937_64 g(s);while(R--){long long b=g()%1000+2,a=g()%(b-1)+1;if(__gcd(a,b)>1){R++;continue;}long long x,y;E(a,b,x,y);x=(x%b+b)%b;if(a*x%b!=1)return cout<<"WA\n",1;}cout<<"OK\n";}
'''
BG=r'''#include <bits/stdc++.h>
using namespace std;int main(int c,char**v){ios::sync_with_stdio(0);cin.tie(0);unsigned long long s=c>1?stoull(v[1]):1,z=c>2?stoull(v[2]):1000;mt19937_64 g(s);int b=g()%max(2ULL,z)+2,a=g()%(b-1)+1;while(__gcd(a,b)>1)a=a%(b-1)+1;cout<<a<<' '<<b<<'\n';}
'''
add('P1082','P1082 [NOIP 2012 提高组] 同余方程',r'扩展欧几里得求 $ax+by=1$ 的一组整数解，系数 $x$ 即为 $a$ 在模 $b$ 意义下的逆元；将它归一化到 $[0,b)$。',{'.cpp':B,' 数据生成.cpp':BG,' 暴力.cpp':BB,' 对拍.cpp':BS},parts=[BB],extra=[('3 7\n','5\n'),('1 9\n','1\n'),('17 43\n','38\n')])

C=r'''#include <bits/stdc++.h>
using namespace std;const long long P=19260817;long long Q(string s){long long x=0;for(char c:s)x=(x*10+c-48)%P;return x;}long long F(long long a,long long b=P-2){long long r=1;for(;b;b>>=1,a=a*a%P)if(b&1)r=r*a%P;return r;}int main(){ios::sync_with_stdio(0);cin.tie(0);string a,b;cin>>a>>b;cout<<Q(a)*F(Q(b))%P<<'\n';}
'''
CB=r'''#include <bits/stdc++.h>
using namespace std;const long long P=19260817;long long F(long long a,long long b=P-2){long long r=1;for(;b;b>>=1,a=a*a%P)if(b&1)r=r*a%P;return r;}int main(){ios::sync_with_stdio(0);cin.tie(0);long long a,b;cin>>a>>b;cout<<a%P*F(b%P)%P<<'\n';}
'''
CS=r'''#include <bits/stdc++.h>
using namespace std;const long long P=19260817;long long F(long long a,long long b=P-2){long long r=1;for(;b;b>>=1,a=a*a%P)if(b&1)r=r*a%P;return r;}int main(int C,char**v){ios::sync_with_stdio(0);cin.tie(0);int R=C>1?stoi(v[1]):1000;unsigned long long s=C>2?stoull(v[2]):1;mt19937_64 g(s);while(R--){long long a=g()%P,b=g()%(P-1)+1,x=a*F(b)%P;if(x*b%P!=a)return cout<<"WA\n",1;}cout<<"OK\n";}
'''
CG=r'''#include <bits/stdc++.h>
using namespace std;const int N=10005,P=19260817;char a[N];int main(int c,char**v){ios::sync_with_stdio(0);cin.tie(0);unsigned long long s=c>1?stoull(v[1]):1,z=c>2?stoull(v[2]):100;mt19937_64 g(s);int n=min(10001ULL,max(1ULL,z));for(int k=0;k<2;k++){int q=0;a[0]=g()%9+49;for(int i=1;i<n;i++)a[i]=g()%10+48;for(int i=0;i<n;i++)q=((long long)q*10+a[i]-48)%P;if(k&&q==0)a[n-1]=a[n-1]=='9'?'8':a[n-1]+1;for(int i=0;i<n;i++)cout<<a[i];cout<<'\n';}}
'''
add('P2613','P2613 【模板】有理数取余',r'逐位读取两个大整数并对 $19260817$ 取模。模数为质数且分母在模意义下非零，用费马小定理计算 $b^{P-2}$，答案为 $a\cdot b^{-1}\bmod P$。',{'.cpp':C,' 数据生成.cpp':CG,' 暴力.cpp':CB,' 对拍.cpp':CS},extra=[('1\n1\n','1\n'),('10\n2\n','5\n'),('19260818\n3\n','12840545\n')])

D=r'''#include <bits/stdc++.h>
using namespace std;int main(){ios::sync_with_stdio(0);cin.tie(0);long long a,b;cin>>a>>b;cout<<a*b-a-b<<'\n';}
'''
DB=r'''#include <bits/stdc++.h>
using namespace std;bool v[100000];int main(){ios::sync_with_stdio(0);cin.tie(0);int a,b;cin>>a>>b;for(int i=0;i*a<100000;i++)for(int j=0;i*a+j*b<100000;j++)v[i*a+j*b]=1;for(int i=99999;i>=0;i--)if(!v[i])return cout<<i<<'\n',0;}
'''
DS=r'''#include <bits/stdc++.h>
using namespace std;bool v[10000];int main(int C,char**V){ios::sync_with_stdio(0);cin.tie(0);int R=C>1?stoi(V[1]):1000;unsigned long long s=C>2?stoull(V[2]):1;mt19937_64 g(s);while(R--){int a=g()%50+1,b=g()%50+1;if(__gcd(a,b)>1){R++;continue;}memset(v,0,sizeof v);for(int i=0;i*a<10000;i++)for(int j=0;i*a+j*b<10000;j++)v[i*a+j*b]=1;int x=9999;while(v[x])x--;if(x!=a*b-a-b)return cout<<"WA\n",1;}cout<<"OK\n";}
'''
DG=r'''#include <bits/stdc++.h>
using namespace std;int main(int c,char**v){ios::sync_with_stdio(0);cin.tie(0);unsigned long long s=c>1?stoull(v[1]):1,z=c>2?stoull(v[2]):1000;mt19937_64 g(s);int a=g()%max(2ULL,z)+1,b=g()%max(2ULL,z)+1;while(__gcd(a,b)>1)b=b%max(2ULL,z)+1;cout<<a<<' '<<b<<'\n';}
'''
add('P3951','P3951 [NOIP 2017 提高组] 小凯的疑惑',r'当 $a,b$ 互质时，两种面额不能表示出的最大正整数由 Frobenius 定理给出，直接为 $ab-a-b$。',{'.cpp':D,' 数据生成.cpp':DG,' 暴力.cpp':DB,' 对拍.cpp':DS},parts=[DB],extra=[('2 3\n','1\n'),('4 7\n','17\n'),('999999937 1000000000\n','999999935000000063\n')])
