#include<bits/stdc++.h>
using namespace std;
#define int long long
#define float double 
#define dg(x) cout<<#x<<" :"<<x;
#define dg_array(ar) for(auto x : ar) cout<<x<<" ";cout<<endl;
#define dg_2darray(ar) for(auto x : ar) {for(auto y : x) cout<< y<<" ";cout<<endl;}
#define endl '\n'
#define fast  ios_base::sync_with_stdio(false);cin.tie(NULL);
const int MAX = 5 * 1e5;
pair<int, bool> Tree[MAX];  

void construct(vector<int>&ar, int root , int left, int right)
{
	if(left == right)
	{
		Tree[root] = {ar[left], true};
		return ;
	}
	
	int mid =  (left + right)/2;
	construct(ar, root*2 , left, mid);
	construct(ar, root*2 + 1 , mid + 1, right);
	if(Tree[root*2].second)
	{
		Tree[root] = {Tree[root*2].first | Tree[root* 2 + 1].first, false};
	}
	else
	{
		Tree[root] = {Tree[root*2].first ^ Tree[root* 2 + 1].first, true};
		
	}
	
}
void update(int root, int left , int right, int index, int val)
{
	if(left == right)
	{
		Tree[root].first = val;
		return ;
	}

	int mid = (left + right)/2;
	if( index <= mid)
	{
		update(root*2, left , mid, index, val);
	}
	else
	{
		update(root*2 + 1, mid +1, right ,index, val);
	}
	
	if(Tree[root*2].second)
	{
		Tree[root] = {Tree[root*2].first | Tree[root* 2 + 1].first, false};
	}
	else
	{
		Tree[root] = {Tree[root*2].first ^ Tree[root* 2 + 1].first, true};
		
	}
}


void solve()
{
	int n , m ;
	cin >> n >> m;
	n = pow(2, n);
	vector<int> ar(n);
	for(int i=0 ;i<n; i++)
	{
		cin >> ar[i];
	}
	construct(ar, 1, 0 , n-1);

	for(int i = 0; i < m; i++)
	{
		int a, b;
		cin >> a >> b;
		update(1, 0, n-1, a - 1, b);
		cout<< Tree[1].first << endl;
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



/*

good implementation of segment Tree
https://codeforces.com/blog/entry/18051
*/