#include<bits/stdc++.h>
#include <ext/pb_ds/assoc_container.hpp> 
#include <ext/pb_ds/tree_policy.hpp> 
using namespace std;
#define int long long
#define float double 
#define dg(x) cout<<#x<<" :"<<x;
#define dg_array(ar) for(auto x : ar) cout<<x<<" ";cout<<endl;
#define dg_2darray(ar) for(auto x : ar) {for(auto y : x) cout<< y<<" ";cout<<endl;}
#define endl '\n'
#define fast  ios_base::sync_with_stdio(false);cin.tie(NULL);
// Header files, namespaces, 
// macros as defined above 

using namespace __gnu_pbds; 
  
#define ordered_set tree<pair<int, int> , null_type,greater<pair<int, int>>, rb_tree_tag,tree_order_statistics_node_update> 

/*
Let's rewrite the inequality from 𝑎𝑖+𝑎𝑗>𝑏𝑖+𝑏𝑗 to (𝑎𝑖−𝑏𝑖)+(𝑎𝑗−𝑏𝑗)>0.
 This looks much simpler. Let's build the array 𝑐 where 𝑐𝑖=𝑎𝑖−𝑏𝑖 and sort this array.
  Now our problem is to find the number of pairs 𝑖<𝑗 such that 𝑐𝑖+𝑐𝑗>0.

Let's iterate over all elements of 𝑐 from left to right. For simplicity, we consider only "greater" summands. 
Because our sum (𝑐𝑖+𝑐𝑗) must be greater than 0, then at least one of these summands will be positive. 
So, if 𝑐𝑖≤0, just skip it. Now 𝑐𝑖>0 and we need to calculate the number of such 𝑗 that 𝑐𝑖+𝑐𝑗>0 and 𝑗<𝑖. 
It means that each 𝑐𝑗≥−𝑐𝑖+1 (for some 𝑗<𝑖) will be okay. Such leftmost position 𝑗 can be found with std::lower_bound or binary search. 
Then add the value 𝑖−𝑗 to the answer and consider the next element.

Time complexity: 𝑂(𝑛log𝑛).
*/
void solve()
{
	int n ;
	cin >> n;
	vector<int> a(n), b(n);
	for(int i =0 ; i < n; i++)	cin >> a[i];
	for(int i =0 ; i < n; i++) cin >> b[i];
	ordered_set o_set;
	map<int, int> mp;
	int res =0;
	for(int i =0 ; i< n; i++)
	{
		res += o_set.order_of_key({ (b[i]-a[i]) , INT_MAX});
		mp[a[i]- b[i]]++;
		o_set.insert({a[i] - b[i], mp[a[i] - b[i]]});
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


// tutorial solution 
// althrough my solution's complexity is also O(nlogn) but still tutorial's solution is good as it is not using any 
// advance data structure.
/*

#include <bits/stdc++.h>

using namespace std;

int main() {
#ifdef _DEBUG
	freopen("input.txt", "r", stdin);
//	freopen("output.txt", "w", stdout);
#endif
	
	int n;
	cin >> n;
	vector<int> a(n), b(n);
	for (auto &it : a) cin >> it;
	for (auto &it : b) cin >> it;
	vector<int> c(n);
	for (int i = 0; i < n; ++i) {
		c[i] = a[i] - b[i];
	}
	sort(c.begin(), c.end());
	
	long long ans = 0;
	for (int i = 0; i < n; ++i) {
		if (c[i] <= 0) continue;
		int pos = lower_bound(c.begin(), c.end(), -c[i] + 1) - c.begin();
		ans += i - pos;
	}
	
	cout << ans << endl;
	
	return 0;
}

*/