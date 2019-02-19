#include <bits/stdc++.h>
using namespace std;
#define INF 1000000000
int n,q;
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
	    a[i] = (a[i*2]*a[i*2+1])/(__gcd(a[i*2],a[i*2+1]));
	}
	
	
	
	
	while (q --)
	{
	    int l,r;
	    cin >> l >> r;
	    r++;//now it will include from index  [l,r]
	    l += n;
	    r += n;
	    int sum=1;

	    while (l < r)
		{
	        if (l%2==1)
			{
	            sum=(sum*a[l])  /  (__gcd(sum,a[l]));
	            l ++;
	        }
	        if (r%2==1)
			{
	            r --;
	             sum=(sum*a[r])/(__gcd(sum,a[r]));
	        }
	        l /= 2;
	        r /= 2;
	    }
	    cout << sum << endl;
	}
}
