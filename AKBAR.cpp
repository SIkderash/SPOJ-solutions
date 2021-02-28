#include<bits/stdc++.h>
using namespace std;
int n, r, m;
int vis[10000000+5];
int d[10000000+5];
bool bfs(int k, int s, int tp, vector<int>v[]){
if(vis[k]!=-1 && vis[k]!=tp){
    return false;
}
vis[k] = tp;
queue<int>q;
q.push(k);
d[k]=0;
while(!q.empty()){
        int x = q.front();
        q.pop();
        if(d[x]==s) continue;
        for(auto y : v[x]){
        if(vis[y]==tp) continue;
        if(vis[y]!=-1) return false;
        vis[y]=tp;
        d[y] = d[x]+1;
        if(d[y]==s) continue;
        q.push(y);
    }
}
    return true;
}

int main(){
int t;
cin >> t;
l:
while(t--){
    cin >> n >> r >> m;
    for(int i=0; i<n; i++){
        vis[i] = -1;
    }
    vector<int> v[n];
    vector<pair<int,int> > sc;
    for(int i=0; i<r; i++){
        int x, y ;
        cin >> x >> y;
        x--, y--;
        v[x].push_back(y);
        v[y].push_back(x);
    }
    for(int i=0; i<m; i++){
        int k, s;
        cin >> k >> s;
        k--;
        sc.push_back(make_pair(k,s));
    }
    int i=0;
    for(auto x: sc){
        bool y = bfs(x.first,x.second,i,v);
        if(!y){
            cout <<"No\n";
            goto l;
        }
        i++;
    }
    for(int i=0; i<n; i++){
        if(vis[i]==-1) {
            cout<<"No\n";
            goto l;
        }
    }
    cout << "Yes\n";
}
return 0;
}
