#include <bits/stdc++.h>
using namespace std;

vector <int> adj[100005];
bool visited[100005] = { false };
int ans = 0,ii=0;

void dfs(int s)
{
	
visited[s] = true;
ans++;
for(int i = 0; i < adj[s].size(); ++i)
{
if(visited[adj[s][i]] == false)
{
dfs(adj[s][i]);
}
ii++;
}
}

int main(){
int n, e, x, y;
cin >> n >> e;
for(int i = 0; i < e; i++){
cin >> x >> y;
adj[x].push_back(y); 
adj[y].push_back(x); 
}
for(int i=1;i<=n;i++)
{
dfs(i);
cout << ans<<"\n";
ans=0;
}
cin>>n;
return 0;
}
