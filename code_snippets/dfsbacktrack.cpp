#include <bits/stdc++.h>
#define pb push_back
#define ll long long
#define fr(i,a,b) for(ll int i=a;i<b;i++)
#define vsort(v) sort(v.begin(),v.end())
#define whl(t) while(t--)
#define vuni(vec) vec.erase( unique( vec.begin(), vec.end() ), vec.end() )

using namespace std;
//akashravi.tk

int cx[]={0,0,1,-1},cy[]={-1,1,0,0};
long long ans;
int a[100][100],n;
bool vis[100][100];

bool valid(int x,int y)
{
    return (x>=0&&x<n&&y>=0&&y<n);
}


void dfs(int x,int y)
{
    //cout<<x<<' '<<y<<endl;
    if(!valid(x,y))
        return;
    if(x==n-1&&y==n-1)
    {
        ans++;
        return;
    }
    if(!vis[x][y]&&a[x][y]==0)
    {
        //cout<<x<<' '<<y<<endl;
        vis[x][y]=true;
        fr(i,0,4)
        {
            int x1=x+cx[i],y1=y+cy[i];
            /*if(x==0&&y==1)
                cout<<x1<<' '<<y1<<endl;*/
            if(valid(x1,y1)&&!vis[x1][y1]){
                //cout<<x1<<' '<<y1<<endl;
                dfs(x1,y1);
                vis[x1][y1]=false;
            }
        }
        vis[x][y]=false;
    }
}

int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    ll int t;
	//vector<ll int> ac;
    cin>>t;
    while(t--)
    {
        memset(vis,false,sizeof(vis));
        ans=0;
        cin>>n;
        fr(i,0,n)
            fr(j,0,n){
                cin>>a[i][j];
                vis[i][j]=false;
            }
        dfs(0,0);
        cout<<ans<<"\n";
    }    //cout<<"\n";

    return 0;
}
