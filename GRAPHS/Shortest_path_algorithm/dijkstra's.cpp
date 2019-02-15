#include <bits/stdc++.h>
#define ll long long int
#define pp pair<ll,ll>
using namespace std;
const int MAX = 1e6 + 5;
bool visited[MAX];
ll dist[MAX];
vector <pp> adj[MAX];
void dijkstra(ll source)
{
memset(dist,9999999,sizeof(dist));//set distance to maximum for each vertex
priority_queue<pp, vector<pp>, greater<pp> > Q;
dist[source]=0;
Q.push(make_pair(0, source));
while(!Q.empty())
{
// Select the edge with minimum weight
pp p = Q.top();
Q.pop();
ll x = p.second;
// Checking for cycle
if(visited[x]==true)
continue;
visited[x] = true;
for(ll i = 0;i < adj[x].size();++i)
{
ll y = adj[x][i].second;
ll weight=adj[x][i].first;
if(dist[y]>dist[x]+weight)
{
dist[y]=dist[x]+weight;
Q.push(make_pair(dist[y],y));
}
}
}
}

int main()
{
ll nodes, edges, x, y;
ll weight, minimumCost;
cin >> nodes >> edges;
for(ll i = 0;i < edges;++i)
{
cin >> x >> y >> weight;
adj[x].push_back(make_pair(weight, y));
//adj[y].pb(mp(weight, x));
}
// Selecting 1 as the source node from where all distances are to be calculated
dijkstra(1);
for(int i=2;i<=nodes;i++)
cout<<dist[i]<<" ";
return 0;
}
