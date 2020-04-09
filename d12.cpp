#include<bits/stdc++.h>
using namespace std;
#define int long long
#define float double 
#define dg(x) cout<<#x<<" :"<<x;
#define dg_array(ar) for(auto x : ar) cout<<x<<" ";cout<<endl;
#define dg_2darray(ar) for(auto x : ar) {for(auto y : x) cout<< y<<" ";cout<<endl;}
#define endl '\n'
#define fast  ios_base::sync_with_stdio(false);cin.tie(NULL);

// wrong solution that look right at first 
/*
void solve()
{
	int n;
	cin >> n;
	vector<float> a(n), b(n);
	for(int i =0 ; i < n; i++ )
		cin >> a[i];
	for(int i = 0 ; i < n; i++)
		cin >> b[i];
	map<float ,int > mp;
	int c =0;
	for(int i = 0; i< n; i++)
	{

		if(!b[i] && !a[i])
		{
			c++;
			continue;
		}
		else if(!b[i])
		{
			mp[0]++;
			continue;
		}
		if(!a[i]) continue;
		float cur = (-b[i])/(a[i]);					// should not this because it might be possible that a and b are too big and mutually prime then a/b  can be equal to another a'/b'
													// so , instead i will store (a/b) means denominator and numerator in  pair
		cout << cur << endl;
		mp[cur]++;
	}
	int res =c;
	for(auto x: mp)
		res = max(res, x.second + c);
	cout << res << endl;
}
*/
void solve()
{
	int n ;
	cin >> n;
	vector<int> a(n), b(n);
	for(int i=0 ; i< n; i++)
	{
		cin >> a[i];

	}
	for(int i =0 ;  i< n; i++)
	{
		cin >> b[i];
	}

	int c =0;
	map<pair<int, int > , int> mp;
	for(int i=0 ;i<n ; i++)
	{
		if(a[i] == 0 )
		{
			if(b[i] == 0)				
			{
				c ++; 			// if b[i] is zero we can choose any value as d
			}
			continue; 				// if a=0 (and b !=0) then we cannot make it zero
		}
		else  if(b[i] == 0)			// if b =0 and a !=0 and we need to multi a with zero (d ==0)
		{
			mp[{0LL,0LL}]++;
		}
		else
		{
			int g = __gcd(a[i], b[i]);
			mp[{a[i] / g, b[i] / g}]++;
		}
	}
	int res = c;
	for(auto x : mp)
	{
		res = max(res, x.second + c);
	}
	cout<< res << endl;
}

void testcase()
{
    int t;
    cin>>t;
    while(t--)
        solve();
}
int32_t main(){
	fast;

//    testcase();           
   solve();              
}