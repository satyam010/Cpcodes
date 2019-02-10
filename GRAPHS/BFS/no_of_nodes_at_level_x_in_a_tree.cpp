#include<bits/stdc++.h>
using namespace std;
vector<int> v[10005];
bool vis[10005];
int level[10005];
void bfs(int s)
{
    queue<int> q;
    q.push(s);
    level[s]=1;
    vis[s]=true;
    while(!q.empty())
    {
        int p = q.front();
        q.pop();
        for(int i = 0 ; i<v[p].size();i++)
        {
        	if(vis[v[p][i]]==false)
        	{
        		level[v[p][i]]= level[p]+1;
        		q.push(v[p][i]);
        		vis[v[p][i]]=true; 		
			}
		}   
    }   
}
int main()
{
int n,e;
cin>>n;
e=n-1;
for(int i=1;i<=e;i++)
{
int x,y;
cin>>x>>y;
v[x].push_back(y);
v[y].push_back(x);	
}
bfs(1);
int count=0,x;
cin>>x;
for(int i=1;i<=n;i++)
{
	if(level[i]==x)
	count++;
}
cout<<count<<endl;
return 0;   
}
