#pragma comment(linker, "/stack:200000000")
#pragma GCC optimize("Ofast,no-stack-protector")
#pragma GCC target("sse,sse2,sse3,ssse3,sse4,popcnt,abm,mmx,avx,tune=native")
#pragma GCC optimize("unroll-loops")


# include <bits/stdc++.h>

using namespace std;


#define nl                  "\n"

//const int mx        = 1e10+5;
const int mx = 1e5+10;
bool mark[mx];
vector<long long int>prime;
void sieve()
{
    memset(mark,true,sizeof(mark));
    for(int i=3; i<=sqrt(mx); i+=2)
    {
        if(mark[i])
        {
            for(int j=i*i; j<=mx; j+=2*i)
                mark[j]=false;
        }
    }
    prime.push_back(2);

    for(int i=3; i<=mx; i+=2)
        if(mark[i])
        {
            prime.push_back(i);
        }
}
///code start here
int main()
{
    sieve();
    int t;
    cin >> t;
    long long int n,k;
    while(t--)
    {
        cin >> n >> k;
        long long int ans = 0, i;
        for(i=0; i<prime.size(); i++)
        {
            if(prime[i]*prime[i]>n) break;
            if(prime[i]*prime[i]<=k)
                ans++;
        }
        long long int z = i-ans;
        if(z<0)  z=0;

            cout << i<< " "<<z << nl;
    }
}
