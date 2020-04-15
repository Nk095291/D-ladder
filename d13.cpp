#include<bits/stdc++.h>
using namespace std;
#define int long long
#define float double 
#define dg(x) cout<<#x<<" :"<<x;
#define dg_array(ar) for(auto x : ar) cout<<x<<" ";cout<<endl;
#define dg_2darray(ar) for(auto x : ar) {for(auto y : x) cout<< y<<" ";cout<<endl;}
#define endl '\n'
#define fast  ios_base::sync_with_stdio(false);cin.tie(NULL);
int mod  =998244353; 
int getresult(int x,int times)
{
	int p = 1;
	int res = 0;
	while(x)
	{
		int d = x%10;
		x /= 10;
		res =( res + (d * p)%mod)%mod;
		p *=100;
	}
	res = ((res * 10  + res )% mod * (times)% mod) % mod;
	return res;
}
void solve()
{
	int n ; 
	cin >> n;
	vector<int> ar(n);
	for(int i =0 ; i< n; i++)
	{
		cin >> ar[i];
	}
	int res =0 ;
	for(auto x: ar)
	{
		res = (res + getresult(x, n ))%mod;
	}
	cout << res << endl;

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