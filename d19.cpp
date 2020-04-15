#include<bits/stdc++.h>
using namespace std;
#define int long long
#define float double 
#define dg(x) cout<<#x<<" :"<<x;
#define dg_array(ar) for(auto x : ar) cout<<x.first<<" ";cout<<endl;
#define dg_array2(ar) for(auto x : ar) cout<<x.second<<" ";cout<<endl;

#define dg_2darray(ar) for(auto x : ar) {for(auto y : x) cout<< y<<" ";cout<<endl;}
#define endl '\n'
#define fast  ios_base::sync_with_stdio(false);cin.tie(NULL);

bool comp(const pair<int, int> & a, const pair<int, int> &b)
{	
	if(a.first == b.first)
	{
		return a.second > b.second;
	}
	return a.first < b.first;
}
void solve()
{
	int n ;
	cin >> n;
	vector<pair<int, int>> ar(n);
	for(int i = 0; i< n; i++)
	{
		cin >>ar[i].first;
		ar[i].second = i;

	}
	sort(ar.begin() ,ar.end(), comp);
	// dg_array(ar);
	// dg_array2(ar);

	int t;
	cin >> t ;
	while(t--)
	{
		int a , b;
		cin >> a >> b;
		b--;
		vector<pair<int, int>> temp(a);
		for(int i = n -a , j =0; i <n; i++, j++)
		{
			temp[j] = {ar[i].second, ar[i].first};
		}
		// dg_array(temp);
		sort(temp.begin(), temp.end());
		cout<< temp[b].second <<endl;
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
//    testcase();           
   solve();              
}