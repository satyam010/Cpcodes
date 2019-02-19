#include <bits/stdc++.h>
using namespace std;
#define INF 1000000000
int n,q;
int main() 
{
	cin >> n >> q;	
	
	int a[2*n];
    int b[2*n];
	
	for (int i = n; i < 2*n; i++)
	{
	    cin >> a[i];
	    b[i] = a[i];
	}
	
	for (int i = n-1; i > 0; i--)
	{
	    a[i] = max(a[i*2],a[i*2+1]);
	    b[i] = min(b[i*2],b[i*2+1]);
	}
	
	while (q --)
	{
	    int l,r;
	    cin >> l >> r;
	    r ++;  //now it will include from index  [l,r]
	    l += n;
	    r += n;
	    int mx = -INF;
	    int mn = INF;
	    
	    while (l < r)
		{
	        if (l%2==1)
			{
	            mx = max(mx,a[l]);
	            mn = min(mn,b[l]);
	            l ++;
	        }
	        if (r%2==1)
			{
	            r --;
	            mx = max(mx,a[r]);
	            mn = min(mn,b[r]);
	        }
	        l /= 2;
	        r /= 2;
	    }
	    cout << mn<<","<<mx << endl;
	}
}
