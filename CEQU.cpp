#include <iostream>

using namespace std;

long int gcd(long long int a , long long int b){
   
    if(b==0 || a==0) {
        return 0;
    }
    if(b%a==0){
        return a;
    }
    else{
        return gcd(b%a,a);
    }
       
}

int main()
{
    long long int T,a,b,c,g;
   
    cin>>T;
   
    for (int i = 1; i <= T; ++i)
    {
       
        cin>>a>>b>>c;
       
        g=gcd(a,b);
       
        if(c%g==0)
            cout<<"Case "<<i<<": Yes"<<endl;
        else
            cout<<"Case "<<i<<": No"<<endl;
    }
    return 0;
