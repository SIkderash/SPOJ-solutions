#include<bits/stdc++.h>
using namespace std;
#define ll long long int
#define fast            ios_base::sync_with_stdio(false),cin.tie(NULL),cout.tie(NULL)
ll tree[1030][1030];
ll g[1030][1030];
int n;
void update(int x, int y, ll val){
    for(int i=x; i<=n; i+=i&-i){
        for(int j=y; j<=n; j+=j&-j){
            tree[i][j]+=val;
        }
    }
}
ll read(int x, int y){
    ll sum = 0;
    for(int i=x; i>0; i-=i&-i){
        for(int j=y; j>0; j-=j&-j){
            sum+=tree[i][j];
        }
    }
    return sum;
}
ll get(int a, int b, int c, int d){
    //cout<< read(c,d)<< " " << read(a-1,d)<< " " << read(c,b-1)<<" " <<read(a-1,b-1) << endl;
    return read(c,d)-read(a-1,d)-read(c,b-1)+read(a-1,b-1);
}
int main(){
    fast;
    int t;
    cin >> t;
    while(t--){
        for(int i=0; i<1030; i++)
            for(int j=0; j<1030; j++)
                {tree[i][j]=0; g[i][j]=0;}
        cin >> n;
        while(1)
        {string s;
        cin >> s;
        if(s=="END") break;
        if(s=="SET"){
            int a, b;
            ll val;
            cin >> a >> b >> val;
            update(a+1,b+1,-g[a+1][b+1]+val);
            g[a+1][b+1]=val;
        }
        else{
            int a, b, c, d;
            cin >> a >> b >> c >> d;
            cout << get(a+1,b+1,c+1,d+1)<<'\n';
        }
        }
    }
return 0;
}
