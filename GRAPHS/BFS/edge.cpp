#include<bits/stdc++.h>
using namespace std;
int main()
{
vector <int> adj[1001]; 
int x, y, nodes, edges, queries, node1, node2; 
cin >> nodes >> edges; 
for(int i = 0;i < edges;i++) 
{
cin >> x >> y;
adj[x].push_back(y);//Insert y in adjacency list of x
adj[y].push_back(x);//Insert x in adjacency list of y because undirected graph
}
cin >> queries;
for(int j=0 ;j < queries; j++)
{
int c=0;
cin >> node1 >> node2;
for(int k=0 ; k < adj[node1].size() ; k++)
{
if(adj[node1][k] == node2)
{
c=1;
break;
}
}
if(c==1)
cout << "YES" <<endl;
else
cout << "NO" <<endl;
}
return 0;
}
