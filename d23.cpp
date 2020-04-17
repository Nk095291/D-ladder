#include<bits/stdc++.h>
using namespace std;
#define int long long
#define float double 
#define dg(x) cout<<#x<<" :"<<x;
#define dg_array(ar) for(auto x : ar) cout<<x<<" ";cout<<endl;
#define dg_2darray(ar) for(auto x : ar) {for(auto y : x) cout<< y<<" ";cout<<endl;}
#define endl '\n'
#define fast  ios_base::sync_with_stdio(false);cin.tie(NULL);
const int MAX = 1e5;
int mod = 1e9 + 7;
int dp[2 * MAX];

/*
We can notate each string as a binary string, instead of red and white flowers. A string of this type is good only if every maximal contigous subsequence of "0" has the length divisible by k. We can make dynamic programming this way : nri = the number of good strings of length i. If the i-th character is "1" then we can have any character before and if the i-th character is "0" we must have another k - 1 "0" characters before, so nri = nri - 1 + nri - k for i ≥ k and nri = 1 for i < k. Then we compute the partial sums (sumi = nr1 + nr2 + ... + nri) and for each query the result will be sumb - suma - 1. This solution has the complexity O(maxVal + t), where maxVal is the maximum value of bi.
*/

int getresult(int i , int k)
{
	if( i < 0)
		return 0;
	if( i == 0)
		return 1;
	if(dp[i] != -1)
		return dp[i];

	int res =0;
	res = (res + getresult(i -1, k)) % mod;
	res = (res + getresult(i - k , k )) % mod;
	return dp[i] =  res;
}


void solve()
{
	int n, k;
	cin >> n >> k;
	memset(dp, -1, sizeof(dp));
	getresult(MAX,k);
	vector<int> pre(2*MAX);
	pre[0]=0;
	for(int i =1 ; i<= MAX; i++)
	{
		pre[i] = (pre[i-1] + dp[i])%mod;
	}
	while(n--)
	{
		int a , b;
		cin >> a >>b;
		int cur = (pre[b] - pre[a-1] + mod)%mod;
		cout << cur << endl;
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