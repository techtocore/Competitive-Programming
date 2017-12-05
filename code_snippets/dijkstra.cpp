#include <bits/stdc++.h>
#define pb push_back
#define ll long long
#define fr(i,a,b) for(ll int i=a;i<b;i++)
#define vsort(v) sort(v.begin(),v.end())
#define whl(t) while(t--)
#define vuni(vec) vec.erase( unique( vec.begin(), vec.end() ), vec.end() )

using namespace std;
//akashravi.tk
#define SIZE 100000 + 1
const int N = 1e5;
int dis[N + 1];
bool vis[N + 1] = {0};
vector<pair<int, int> > adj[N];

class cmp {
    public:
    bool operator() (const pair<int, int> &p1, const pair<int, int> &p2) {
        return p1.second > p2.second;
    }
};

void dijkstra(int s) {
    for(int i = 0; i <= N; i++) {
        dis[i] = INT_MAX;
    }
    dis[s] = 0;
    priority_queue<pair<int, int>, vector<pair<int, int> >, cmp> q;
    q.push(make_pair(s, 0));
    while (!q.empty()) {
        pair<int, int> currPair = q.top();
        q.pop();
        int currVertex = currPair.first;
        int currWeight = currPair.second;
        if (vis[currVertex]) {
            continue;
        }
        vis[currVertex] = true;
        for (int i = 0; i < adj[currVertex].size(); i++) {
            int nextVertex = adj[currVertex][i].first;
            int nextVertexWeight = adj[currVertex][i].second;
            if(!vis[nextVertex] && currWeight + nextVertexWeight < dis[nextVertex]) {
                dis[nextVertex] = currWeight + nextVertexWeight;
                q.push(make_pair(nextVertex, dis[nextVertex]));
            }
        }
    }
}

int main() {

    int n, m, v1, v2, w;
    cin >> n >> m;
    for (int i = 0; i < m; i++) {
        cin >> v1 >> v2 >> w;
        adj[v1].push_back(make_pair(v2, w));
        adj[v2].push_back(make_pair(v1, w));
    }
    int s;
    cin >> s;
    dijkstra(s);
    for (int i = 0; i < n; i++) {
        cout << dis[i+1] << "\n";
    }
    return 0;
}
