#include<bits/stdc++.h>
using namespace std;
#define int long long
#define float double 
#define dg(x) cout<<#x<<" :"<<x;
#define dg_array(ar) for(auto x : ar) cout<<x<<" ";cout<<endl;
#define dg_2darray(ar) for(auto x : ar) {for(auto y : x) cout<< y<<" ";cout<<endl;}
#define endl '\n'
#define fast  ios_base::sync_with_stdio(false);cin.tie(NULL);
void solve()
{
	int n , x;
	cin >> n >> x;
	int ans =0;
	map<int, int> mp;
	for(int i =0 ;i < n; i++)
	{
		int a ;
		cin >> a ;
		mp[a%x]++;
		while(mp[ans%x])
		{
			mp[ans%x]--;
			ans ++;
		}
		cout << ans << endl;
	}
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
	#ifdef _DEBUG
	freopen("input.txt", "r", stdin);
	//	freopen("output.txt", "w", stdout);
	#endif
//    testcase();           
   solve();              
}