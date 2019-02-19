#include <bits/stdc++.h>
using namespace std;
int n,q; 
int a[10000000];
int b[10000000];
 
void build( int A[]) 
{
    for (int i=0; i<n; i++)    
    a[n+i] = A[i];
     
    for (int i = n - 1; i > 0; --i)     
        a[i] =min( a[2*i],a[2*i+1] );    
}

void build( int A[]) 
{
    for (int i=0; i<n; i++)    
    a[n+i] = A[i];
     
    for (int i = n - 1; i > 0; --i)     
        a[i] =min( a[2*i],a[2*i+1] );    
}

void update(int i, int val)
{
	a[n+i] = val;
	i+=n;
	while(i)
	{
		i/=2;
		a[i] = min( a[2*i],a[2*i+1] );    
	}
 
}
 

int query(int l, int r) 
{ 
    int minn = 999999;
    
    for (l += n, r += n; l < r; l >>= 1, r >>= 1)
    {
        if (l&1) 
        minn=min(minn,a[l++]);
     
        if (r&1) 
        minn= min(minn,a[--r]);
    }
     
    return minn;
}
 
int main() 
{
	cin>>n>>q;
    
    for(int i=0;i<n;i++)
    cin>>a[i];
    
     
    build(a);  // build tree 
	
     
    while(q--)
    {
    int l,r;
    cin>>l>>r;
    cout <<query(l,r)<<endl;
    }
    cin>>n;
 
    return 0;
}
