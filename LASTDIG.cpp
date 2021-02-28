#include<bits/stdc++.h>
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
 
int main()
 
{
    int a, t;
    long long int b;
    cin >> t;
    while(t--)
    {
        cin  >>a  >> b;
    cout << BigMod(1LL*a,b,1LL*10)<<"\n";
    }
    return 0;
