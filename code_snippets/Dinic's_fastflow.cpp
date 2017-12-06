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

//typedef long long ll;

void fscpp()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
}
typedef long long LL;
struct Edge
{
    int u, v;
    LL cap, flow;
    Edge() {}
    Edge(int u, int v, LL cap): u(u), v(v), cap(cap), flow(0) {}
};
struct Dinic
{
    int N;
    vector<Edge> E;
    vector<vector<int>> g;
    vector<int> d, pt;
    Dinic(int N): N(N), E(0), g(N), d(N), pt(N) {}
    void AddEdge(int u, int v, LL cap)
    {
        if (u != v)
        {
            E.emplace_back(Edge(u, v, cap));
            g[u].emplace_back(E.size() - 1);
            E.emplace_back(Edge(v, u, 0));
            g[v].emplace_back(E.size() - 1);
        }
    }
    bool BFS(int S, int T)
    {
        queue<int> q({S});
        fill(d.begin(), d.end(), N + 1);
        d[S] = 0;
        while(!q.empty())
        {
            int u = q.front();
            q.pop();
            if (u == T) break;
            for (int k: g[u])
            {
                Edge &e = E[k];
                if (e.flow < e.cap && d[e.v] > d[e.u] + 1)
                {
                    d[e.v] = d[e.u] + 1;
                    q.emplace(e.v);
                }
            }
        }
        return d[T] != N + 1;
    }
    LL DFS(int u, int T, LL flow = -1)
    {
        if (u == T || flow == 0) return flow;
        for (int &i = pt[u]; i < g[u].size(); ++i)
        {
            Edge &e = E[g[u][i]];
            Edge &oe = E[g[u][i]^1];
            if (d[e.v] == d[e.u] + 1)
            {
                LL amt = e.cap - e.flow;
                if (flow != -1 && amt > flow) amt = flow;
                if (LL pushed = DFS(e.v, T, amt))
                {
                    e.flow += pushed;
                    oe.flow -= pushed;
                    return pushed;
                }
            }
        }
        return 0;
    }
    LL MaxFlow(int S, int T)
    {
        LL total = 0;
        while (BFS(S, T))
        {
            fill(pt.begin(), pt.end(), 0);
            while (LL flow = DFS(S, T))
                total += flow;
        }
        return total;
    }
};
// BEGIN CUT
// The following code solves SPOJ problem #4110: Fast Maximum Flow (FASTFLOW)
int main()
{
    int N, E;
    scanf("%d%d", &N, &E);
    Dinic dinic(N);
    for(int i = 0; i < E; i++)
    {
        int u, v;
        LL cap;
        scanf("%d%d%lld", &u, &v, &cap);
        dinic.AddEdge(u - 1, v - 1, cap);
        dinic.AddEdge(v - 1, u - 1, cap);
    }
    printf("%lld\n", dinic.MaxFlow(0, N - 1));
    return 0;
}
