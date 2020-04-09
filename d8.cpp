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
	int n;
	cin >> n;
	vector<int> ar(n);
	map<int, int> mp;
	for(int i =0 ; i<n ; i++)
	{
		cin >> ar[i];
		mp[ar[i]]++;
	}
	vector<int> ans;
	for(auto x: mp)
		ans.push_back(x.second);
	sort(ans.begin(), ans.end(), greater<int>());
	// for(auto x: ans)
	// 	cout<< x <<" ";
	// 	cout<<endl;
	int pre = ans[0];
	int res =pre;
	for(int i =1 ;i<ans.size(); i++)
	{	
		// cout<< ans[i] << " " << pre << endl;
		if( pre ==0)
			break;

			if( ans[i] >= pre)
			{
				res += (pre -1);
				pre  --;  
			}
			else
			{
				res += ans[i];
				pre = ans[i];
			}
			
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
	#ifdef _DEBUG
	freopen("input.txt", "r", stdin);
	//	freopen("output.txt", "w", stdout);
	#endif
   testcase();           
//    solve();              
}