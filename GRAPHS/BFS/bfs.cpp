#include<bits/stdc++.h>
using namespace std;
void bfs(int s) 
{
	    vector <int> v[10];
	    bool vis[10];
        int x, y, nodes, edges;
        cin >> nodes;      
        cin >> edges;       
        for(int i = 0;i < edges;++i)
        {
            cin >> x >> y;
            v[x].push_back(y);   
			v[y].push_back(x);        
        }
        queue <int> q;
        q.push(s);
        vis[ s ] = true;
        while(!q.empty())
        {
            int p = q.front();
            cout<<p<<",";
            q.pop();
            for(int i = 0;i < v[ p ].size() ; i++)
            {
                if(vis[ v[ p ][ i ] ] == false)
                {   
                     q.push(v[ p ][ i ]);
                     vis[ v[ p ][ i ] ] = true;
                }
            }
        }
    }
int main()
{
	int t;
	cin>>t;
	while(t--)
	{
        bfs(1);
    }
    return 0;
}

