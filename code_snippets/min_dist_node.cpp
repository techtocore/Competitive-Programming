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
int vis[10001];


void dfs(int s, int l)
{
    vis[s] = l;
    for(int i = 0; i < adj[s].size(); ++i)
    {
        if(vis[adj[s][i]] == 0)
            dfs(adj[s][i],l+1);
    }
}

int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    ll int t,x,y,q,n,r,f;
    //vector<ll int> a;
    cin>>n;
    t=n-1;
    memset(vis,0,sizeof(vis));
    whl(t)
    {
        cin >> x >> y;
        //Undirected Graph
        adj[x].push_back(y);                   //Edge from vertex x to vertex y
        adj[y].push_back(x);
    }
    dfs(1,1); //assuming city 1 as root node
    cin>>q;
    ll m=INT_MAX;
    fr(i,0,q)
    {
        cin>>r;

        if(m>vis[r])
        {
            m=vis[r];
            f=r;
        }
    }
    cout<<f<<"\n";

    return 0;
}
