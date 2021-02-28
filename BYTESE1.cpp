#include <bits/stdc++.h>
using namespace std;

int g[105][105] ;
bool vis[105][105];
int p[105][105];
int dist[105][105];
int n, m,a,b;
int X[]= {0,0,1,-1};
int Y[]= {1,-1,0,0};

typedef tuple<int, int, int> tup;
#define bound(i,j) ((i>=0 && i<n)&&(j>=0&&j<m))

void bfs (int x, int y)
{

    priority_queue< tup, vector <tup>, greater<tup> > pq;
    dist[x][y] = 0;
    vis[x][y]  =1;
    pq.push(make_tuple(0, x, y));
    while( !pq.empty ())
    {
        int u = get<1>(pq.top());
        int v = get<2>(pq.top());
        pq.pop();
        if(u==a && v==b)
            return;

        //cout << "pop "<<v+1<<"\n";
        //cout <<g[v].size()<<"\n";
        //cout << dist[ v ] <<"\n";
        for( int i=0; i<4; i++)
        {
            // cout << g[v][i].first+1<<" "<<dist[ g[ v ][ i ].first ]<<"\n";
            int w = u + X[i];
            int z = v + Y[i];

                //cout << w <<" "<< z <<"\n";
                //cout << u <<" "<< v <<"    "<<w<<" "<<z<<"\n";
                     if(bound(w,z) && !vis[w][z])
                    {dist[ w ][ z ] = g[ w ][ z ] + dist[u][v] ;
                    vis[w ][z]=1;
                    //cout << "Changed " <<g[v][i].first+1<<" "<<dist[ g[ v ][ i ].first ]<<"\n";
                    //cout <<dist[w][w]<<"\n";
                    pq.push(make_tuple(dist[ w ][ z ], w, z));
                    }

        }

    }
}


int main()
{
    ios::sync_with_stdio(0), cin.tie(0), cout.tie(0);
    int q;
    cin >> q;
    while(q--)
    {
        cin >> n >> m ;
        int t;
        for(int i=0; i<n; i++)
            {for(int j=0; j<m; j++)
            {
                cin >> g[i][j];

            }
            }

        cin >> a >> b >> t;
        for(int i=0; i<n; i++)
            {for(int j=0; j<m; j++)
            {
                dist[i][j]=99999999;
                vis[i][j]=0;
            }
            }
        bfs(0,0);
        if(dist[a-1][b-1]+g[0][0]>t)
        {
            cout <<"NO"<<"\n";
        }
        //cout << dist[a-1][b-1]+g[0][0]<<"\n";
        else cout <<"YES"<<"\n"<<t-dist[a-1][b-1]-g[0][0]<<"\n";
    }
    return 0;
}




