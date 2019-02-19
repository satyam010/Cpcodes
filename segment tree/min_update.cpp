#include <bits/stdc++.h>
using namespace std;
#define INF 1000000000
int n,q;


void update(int a[],int n, int i, int val)
{
	a[n+i] = val;
	i+=n;
	while(i)
	{
		i/=2;
		a[i] = min(a[2*i],a[2*i+1]);
	}
}

int main() 
{
	cin >> n >> q;	
	
	int a[2*n];
	
	for (int i = n; i < 2*n; i++)
	{
	    cin >> a[i];
	}
	
	for (int i = n-1; i > 0; i--)
	{
	    a[i] = min(a[i*2],a[i*2+1]);
	}
	
	while (q --)
	{
		char ch;
	    int l,r;
	    cin >> ch >> l >> r;
	    
	    if(ch=='u')
	    {
			l--;
			update(a,n,l,r);
			continue;
		}
		l--;r--;  //for 1 based indexing
	    r ++;  //now it will include from index  [l,r]
	    l += n;
	    r += n;
	    int mn = INF;
	    
	    while (l < r)
		{
	        if (l%2==1)
			{
	            mn = min(mn,a[l]);
	            l ++;
	        }
	        if (r%2==1)
			{
	            r --;
	            mn = min(mn,a[r]);
	        }
	        l /= 2;
	        r /= 2;
	    }
	    cout << mn << endl;
	}
}

