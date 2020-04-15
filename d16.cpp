#include<bits/stdc++.h>
using namespace std;
#define int long long
#define float double 
#define dg(x) cout<<#x<<" :"<<x;
#define dg_array(ar) for(auto x : ar) cout<<x<<" ";cout<<endl;
#define dg_2darray(ar) for(auto x : ar) {for(auto y : x) cout<< y<<" ";cout<<endl;}
#define endl '\n'
#define fast  ios_base::sync_with_stdio(false);cin.tie(NULL);
vector<int> res;

int getresult(vector<vector<int>> &graph, int st, int parent)
{

	if((graph[st].size() ==1 && graph[st][0] == parent) || !graph[st].size())
	{
		// cout<< st << " ";
		res.push_back(1);
		return 1;
	}
	int ans =0;
	for(auto x : graph[st])
	{
		if(x != parent)
			ans += getresult(graph, x, st);
	}
	res.push_back(ans);
	return ans;

}

void solve()
{
	int n;
	cin >> n;
	vector<vector<int>> graph(n+1);
	for(int i =2 ; i<=n; i++)
	{
		int x;
		cin >> x;
		graph[x].push_back(i);
		graph[i].push_back(x);
	}
	getresult(graph, 1, 0);
	sort(res.begin(), res.end());
	// cout<< endl; 
	for(auto x: res)
		cout<< x << " ";
	cout << endl;

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