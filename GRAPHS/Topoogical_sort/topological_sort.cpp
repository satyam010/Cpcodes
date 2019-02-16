#include <bits/stdc++.h>
using namespace std;
#define ll long long
stack<int> s;
bool visited[11] = {false};
vector<int> v[11];
void dfs(int n)
{
    visited[n] = true;
    sort(v[n].begin(),v[n].end(),greater<int>());
    
	for (int i = 0; i <(int)v[n].size(); i++)
	{
        if(visited[v[n][i]]==false)
		{
            dfs(v[n][i]);
        }
    }
    s.push(n);
}

int main()
{
    int n,e;
    cin>>n>>e;
    int x,y;
    for (int i = 0; i < e; i++)
	{
        cin>>x>>y;
        v[x].push_back(y);
    }
    for(int i=n;i>=1;i--)
	{
        if(visited[i]==false)
		{
            dfs(i);
        }
    }
    while(!s.empty())
	{
        cout<<s.top()<<" ";
        s.pop();
    }
    cin>>n;
}
