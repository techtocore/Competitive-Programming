#include <bits/stdc++.h>
#define pb push_back
#define ll long long
#define fr(i,a,b) for(ll int i=a;i<b;i++)
#define vsort(v) sort(v.begin(),v.end())
#define whl(t) while(t--)
#define vuni(vec) vec.erase( unique( vec.begin(), vec.end() ), vec.end() )

using namespace std;
//akashravi.tk

ll a[100][100];
ll p,m,n;

bool valid(int x, int y)
{
   return (x>=0 && x<n && y>=0 && y<m);
}

bool vis[100][100];

int cx[8]={0,0,1,1,1,-1,-1,-1};
int cy[8]={1,-1,1,-1,0,1,-1,0};

void dfs(int x, int y)
{
    if(!valid(x,y))
        return;
    if(vis[x][y])
        return;
   // if()
     //   return;

    vis[x][y]=true;
    fr(i,0,8)
    {
        dfs(x+cx[i],y+cy[i]);
    }
}


int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    ll int t,ct,r;
	vector<ll int> a;
    cin>>t;
    whl(t)
    {
        ct=0;
        memset(vis,false,sizeof(vis));
         cin>>n>>m;
        fr(i,0,n)
            fr(j,0,m)
            {
                cin>>a[i][j];
            }

            fr(i,0,n)
            {
                fr(j,0,m)
                {
                    if(!vis[i][j])
                    {
                        p=0;
                        ct++;
                        dfs(i,j);
                    }
                }
            }

    }
    //cout<<"\n";

    return 0;
}
