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
	int n ; 
	cin >> n ;
	vector<int > ar(n);
	map<int, vector<int> > mp;
	for(int i =0 ; i< n; i++)
	{
		cin >> ar[i];
		mp[ar[i]].push_back(i);
	}
	int maxx  = 0;
	int res = -1;
	for(auto x: mp)
	{
		if( x.second.size()  > maxx)
		{
			maxx = x.second.size() ;
			res = x.first;
		}
	}
	int pre =-1;
	vector<pair<int, int> > ans;
	for(auto x : mp[res])
	{
		int i =x;
		while((i -1) > pre)
		{
			ans.push_back({i-1, i});
			i--;
		}
		pre = x;
	}
	for(int i =pre+1; i< n ;i++)
	{
			ans.push_back({i, i-1});
		
	}
	cout<< ans.size() << endl;

	for(auto x : ans)
	{
		cout<< (ar[x.first] > res ? '2' : '1') << " " << (x.first+1 )<< " " << (x.second + 1) << endl;
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