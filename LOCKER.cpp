# include <bits/stdc++.h>
using namespace std;
template <typename T> T BigMod(T b,T p,T Mod)
{
    T Ans=1;
    while(p)
    {
        if(p&1)
            Ans=(Ans*b)%Mod;
        b=(b*b)%Mod;
        p>>=1;
    }
    return Ans;
}
const int mod = 1e9+7;
int main()
{
    int  t;
    long long b;
    cin >> t;
    while(t--)
    {
        cin  >>b ;
        if(b==1){
            cout << 1 <<"\n";
            continue;
        }
        if(b%3==2) { cout << BigMod(1LL*3,b/3,1LL*mod)*2%mod<<'\n'; }
        else if(b%3==1) { cout << BigMod(1LL*3,(b/3-1),1LL*mod)*4%mod<<'\n';}
        else cout << BigMod(1LL*3,(b/3),1LL*mod)<<'\n';
    }
    return 0;
}
/*

*/
