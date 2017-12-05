#include <bits/stdc++.h>
#define pb push_back
#define ll long long
#define fr(i,a,b) for(ll int i=a;i<b;i++)
#define vsort(v) sort(v.begin(),v.end())
#define whl(t) while(t--)
#define vuni(vec) vec.erase( unique( vec.begin(), vec.end() ), vec.end() )


using namespace std;
//akashravi.tk

vector <int> adj[10001];
bool vis[10001];


void dfs(int s)
{
    vis[s] = true;
    for(int i = 0; i < adj[s].size(); ++i)
    {
        if(vis[adj[s][i]] == false)
            dfs(adj[s][i]);
    }
}

int main()
{
    int m,n,x,y,ct=0,s;
    cin>>n>>m;
    for(int i = 0; i < m; ++i)
    {
        cin >> x >> y;
        //Undirected Graph
        adj[x].push_back(y);                   //Edge from vertex x to vertex y
        adj[y].push_back(x);                   //Edge from vertex y to vertex x
    }

    memset(vis,false,sizeof(vis));

    cin>>s;
    dfs(s);

    for(int i = 1; i <= n; ++i)
    {
        if(vis[i] == false)
        {
            ct++;
        }
    }
    cout << ct << endl;
    return 0;
}
