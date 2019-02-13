#include<bits/stdc++.h>
using namespace std;
int main()
{
	int t;
	cin>>t;
	while(t--)
	{
		vector <int> adj[10];
        int x, y, nodes, edges;
        cin >> nodes;       //Number of nodes
        cin >> edges;       //Number of edges
        for(int i = 0;i < edges;++i)
        {
            cin >> x >> y;
            adj[x].push_back(y);         
        }
    for(int i = 1;i <= nodes;++i)
    {  
            for(int j = 0;j < adj[i].size();++j)
                cout << adj[i][j] << " --> ";
                cout<<"\n";
    }
    
    }
    return 0;
}

