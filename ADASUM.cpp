#include<bits/stdc++.h>
using namespace std;
#define ll long long
ll power[2000000+6];
ll mod = 1000000000+7;
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
void pre(){
    power[0]=1LL;
    for(int i=1; i<2000000+6; i++){
        power[i] = (power[i-1]*10LL)%mod;
    }
}
int main(){
    pre();
    string s;
    cin >> s;
    int n = s.length();
    ll ans = 0;
    ll inv_of_nine = BigMod((ll)9,mod-2,mod);
    for(int i=1; i<=n; i++){
        //cout << i*(ll)(s[i-1]-'0')*(power[n-i+1]-1) <<endl;
        ans = (ans + (i*(ll)(s[i-1]-'0')*(power[n-i+1]-1))%mod) %mod;
    }
    //if(ans%9==0) ans/=9;
     ans = (ans*inv_of_nine)%mod;
    cout << ans%mod;
    return 0;
}
