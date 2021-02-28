# include <bits/stdc++.h>
#define fast                ios_base::sync_with_stdio(false),cin.tie(NULL),cout.tie(NULL)
using namespace std;

int n;
bool vis[20000+5];
int r(string s){
    int ans = 0;
    for(int i=0; i<s.length(); i++)
        ans=((ans*10)+(int)(s[i]-'0'))%n;
    return ans;
}
string bfs(string s0){
    queue<string>q;
    q.push(s0);

    while(!q.empty()){
        string s = q.front();
        q.pop();
        int rem = r(s);
        vis[rem] = true;
        if(rem==0) return s;
        string tmp1 = s+"0";
        string tmp2 = s+"1";
        if(!vis[r(tmp1)]) q.push(tmp1);
        if(!vis[r(tmp2)]) q.push(tmp2);
    }
    return "-1";
}
int main()
{
    fast;
    int t;
    cin >> t;
    while(t--){
        fill(vis,vis+20000+5,false);
        cin >> n;
        string s = "1";
        cout << bfs(s) << endl;
    }
}
/*
*/
