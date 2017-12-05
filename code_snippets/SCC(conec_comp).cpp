#include <bits/stdc++.h>
#define pb push_back
#define mp make_pair
#define ms(a,b) memset(a,b,sizeof(a))
#define fr(i,a,b) for(long long int i=a;i<b;i++)
#define vsort(v) sort(v.begin(),v.end())
#define whl(t) while(t--)
#define vuni(vec) vec.erase( unique( vec.begin(), vec.end() ), vec.end() )
#define mod 1000000007

using namespace std;
//akashravi.tk

typedef long long ll;

void fscpp()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
}


const int MAX = 1e5+5;
int low[MAX]= {0},tym[MAX]= {0};
bool visit[MAX]= {0},inst[MAX]= {0};
int odd=0,even=0;
vector<int> a[MAX];
stack<int> st;
static int t=0;

void dfs(int u)
{
    visit[u] = true;
    low[u] = tym[u] = t++;
    st.push(u);
    inst[u]=true;
    for(int i=0; i<a[u].size(); i++)
    {
        int v = a[u][i];
        if(!visit[v])
        {
            dfs(v);

            low[u] = min(low[u],low[v]);
        }
        else if(inst[v]==true)
        {
            low[u] = min(low[u],tym[v]);
        }
    }
    int temp=0;
    if(low[u]==tym[u])
    {
        while(st.top()!=u)
        {
            temp++;
            inst[st.top()] = false;
            st.pop();
        }
        temp++;
        inst[st.top()]=false;
        st.pop();
        if(temp%2==0 and temp!=0)
        {
            even += temp;
        }
        else if(temp != 0)
        {
            odd += temp;
        }
        temp=0;
    }
}
int main()
{
    fscpp();
    int n,m,x,y;
    cin>>n>>m;
    for(int i=0; i<m; i++)
    {
        cin>>x>>y;
        a[x].pb(y);
    }
    for(int i=1; i<=n; i++)
    {
        if(!visit[i])
            dfs(i);
    }
    cout<<odd-even;
    return 0;
}
